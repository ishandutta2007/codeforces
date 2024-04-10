#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, m, s[2], sec[MAXN];
ll d[MAXN], val[MAXN];
vector<pair<int, int>>	adj[MAXN];
vector<int>	vec[2][MAXN];
ll sm[2][MAXN][MAXN];
int sz[2], nxt[2][MAXN][MAXN];
set<pair<ll, int>>	st;
ll dp[2][MAXN][MAXN];
bool mark[MAXN];

void update(int v){
	for (auto e:adj[v]){
		int u = e.F, w = e.S;
		if (d[u] > d[v] + w){
			st.erase({d[u], u});
			d[u] = d[v] + w;
			st.insert({d[u], u});
		}
	}
}

int get_min(){
	auto temp = st.begin()->S;
	st.erase(st.begin());
	return temp;
}

void dijk(int rt){
	memset(d, 63, sizeof(d));
	d[rt] = 0;
	update(rt);
	while (st.size())
		update(get_min());
}

bool cmp(int u, int v){return d[u] < d[v];}

int main(){
	scanf("%d %d", &n, &m);
	for (int w = 0; w < 2; w++)
		scanf("%d", &s[w]), s[w]--;
	for (int i = 0; i < n; i++)
		scanf("%lld", &val[i]);
	while (m--){
		int a, b, c;	scanf("%d %d %d", &a, &b, &c), a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for (int w = 0; w < 2; w++){
		dijk(s[w]);
		iota(sec, sec + n, 0);
		sort(sec, sec + n, cmp);
		for (int i = 0; i < n;){
			int j = i;
			while (j < n && d[sec[i]] == d[sec[j]])	j++;
			for (int z = i; z < j; z++)
				vec[w][sz[w]].push_back(sec[z]);
			i = j;
			sz[w]++;
		}
	}

	for (int i = 0; i <= sz[1]; i++){
		memset(mark, 0, sizeof(mark));
		for (int j = 0; j < i; j++)
			for (int v:vec[1][j])	mark[v] = 1;

		int lst = sz[0];
		bool fl = 0;
		for (int j = sz[0] - 1; ~j; j--){
			for (int v:vec[0][j])
				if (!mark[v]){
					sm[0][i][j] += val[v];
					fl = 1;
				}
			
			if (fl)	lst = j, fl = 0;
			nxt[0][i][j] = lst;
		}
	}
	
	for (int i = 0; i <= sz[0]; i++){
		memset(mark, 0, sizeof(mark));
		for (int j = 0; j < i; j++)
			for (int v:vec[0][j])
				mark[v] = 1;

		int lst = sz[1];
		bool fl = 0;
		for (int j = sz[1] - 1; ~j; j--){
			for (int v:vec[1][j])
				if (!mark[v]){
					sm[1][i][j] += val[v];
					fl = 1;
				}
			
			if (fl)
				lst = j, fl = 0;
			nxt[1][i][j] = lst;
		}
	}

	dp[0][sz[0]][sz[1]] = dp[1][sz[0]][sz[1]] = 0;
	for (int i = sz[0]; ~i; i--)
		for (int j = sz[1]; ~j; j--)
			if (i^sz[0] || j ^ sz[1]){
				int w = 0;
				if (i == sz[0])
					dp[w][i][j] = 0;
				else{
					int cur = nxt[0][j][i];
					if (cur < sz[0]){
						dp[w][i][j] = max(dp[1-w][cur + 1][j] + sm[0][j][cur], dp[w][cur + 1][j] + sm[0][j][cur]);

					}
				}
				
				w = 1;
				if (j == sz[1])
					dp[w][i][j] = 0;
				else{
					int cur = nxt[1][i][j];
					if (cur < sz[1])
						dp[w][i][j] = min(dp[1-w][i][cur + 1] - sm[1][i][cur], dp[w][i][cur + 1] - sm[1][i][cur]);

				}
			}
	
	if (dp[0][0][0] < 0)
		printf("Cry\n");
	else if (dp[0][0][0] == 0)
		printf("Flowers\n");
	else
		printf("Break a heart\n");
	return 0;
}