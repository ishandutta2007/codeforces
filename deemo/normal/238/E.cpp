//Finally met her!

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<deque>

using namespace std;

const int MAXN = 100 + 10;
const int INF = 1e9 + 2;

int n, m, s, t, k, lv[MAXN], cnt[MAXN], q[MAXN], tt[MAXN][MAXN], mk[MAXN], beg[MAXN], edd[MAXN];
vector<int>	adj[MAXN], rev_adj[MAXN], sure[MAXN], sst[MAXN][MAXN];
vector<pair<int, int>>	sec[MAXN], vec[MAXN];
bool vis[MAXN], mark[MAXN][MAXN], sn[MAXN], sr[MAXN][MAXN], wss[MAXN][MAXN];
deque<pair<int, int>>	qq;
int d[MAXN][MAXN];

void find_path(int source, int des, int id){
	fill(lv, lv + MAXN, INF);
	for (int i = 0; i < MAXN; i++)
		tt[i][id] = INF;
	
	lv[source] = 0;
	int h = 0, t = 0;	q[t++] = source;
	while (h < t){
		int v = q[h++];
		for (int u:adj[v])
			if (lv[u] > lv[v] + 1){
				lv[u] = lv[v] + 1;
				q[t++] = u;
			}
	}	
	if (lv[des] == INF)	return;

	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(sn, 0, sizeof(sn));
	h = t = 0;
	q[t++] = des;
	cnt[lv[des]]++;
	while (h < t){
		int v = q[h++];
		sn[v] = 1;
		for (int u:rev_adj[v])
			if (lv[u] + 1 == lv[v] && !vis[u]){
				vis[u] = 1;
				cnt[lv[u]]++;
				q[t++] = u;
			}
	}

	memset(vis, 0, sizeof(vis));
	vec[id].push_back({source, 0});
	sure[source].push_back(id);
	h = t = 0;
	q[t++] = source;
	while (h < t){
		int v = q[h++];
		tt[v][id] = lv[v];
		wss[v][id] = 1;
		for (int u:adj[v])
			if (sn[u] && lv[u] == lv[v] + 1 && !vis[u]){
				sst[id][u].push_back(v);
				vis[u] = 1;
				q[t++] = u;
				if (cnt[lv[u]] == 1){
					vec[id].push_back({u, lv[u]});
					sure[u].push_back(id);
					sr[u][id] = 1;
				}
				else	sec[id].push_back({u, lv[u]});
			}
			else if (sn[u] && lv[u] == lv[v] + 1)	sst[id][u].push_back(v);

	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> t;	s--, t--;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		rev_adj[b].push_back(a);
	}
	cin >> k;
	for (int i = 0; i < k; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		beg[i] = a, edd[i] = b;
		find_path(a, b, i);
	}
	
	{
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)	d[i][j] = INF;
		for (int i = 0; i < k; i++)
			if (wss[t][i])	d[t][i] = 1;
	
		bool flag = 1;
		while (flag){
			flag = 0;
			for (int i = 0; i < n; i++){
				int mn = INF;
				for (int j:sure[i])
					mn = min(mn, d[i][j]);
				if (mn == INF)	continue;

				for (int j = 0; j < k; j++)
					if (wss[i][j]){
						if (d[i][j] == INF)	flag = 1;
						d[i][j] = min(d[i][j], mn + 1);
					}
			}

			for (int j = 0; j < k; j++){
				fill(mk, mk + MAXN, INF);
				for (int i = (int)vec[j].size() - 1; i >= 0; i--)
					mk[vec[j][i].second] = min(mk[vec[j][i].second], d[vec[j][i].first][j]); 
				for (int i = MAXN - 2; i >= 0; i--)
					mk[i] = min(mk[i], mk[i + 1]);

				for (int i = 0; i < n; i++){
					int z = tt[i][j];
					if (z != INF){
						if (d[i][j] == INF && mk[z] != INF)	flag = 1;
						d[i][j] = min(d[i][j], mk[z]);
					}
				}
			}

			for (int j = 0; j < k; j++){
				memset(mk, 0, sizeof(mk));
				memset(vis, 0, sizeof(vis));
	
				int v = edd[j];
				int h = 0, t = 0;
				q[t++] = v;
				while (h < t){
					v = q[h++];
					if (v != edd[j])	d[v][j] = min(d[v][j], mk[v]);

					for (int u:sst[j][v]){
						if (!vis[u])
							q[t++] = u, vis[u] = 1;
						mk[u] = max(mk[u], d[v][j]);
					}
				}
			}
		}
	}
	
	int ans = INF;
	for (int i = 0; i < k; i++)
		for (pair<int, int>	u:vec[i])
			if (u.first == s)	ans = min(ans, d[s][i]);
	if (ans == INF)	ans = -1;
	cout << ans << "\n";
	return	0;	
}