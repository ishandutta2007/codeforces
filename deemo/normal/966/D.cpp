#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m;
vector<int> adj[MAXN];
int q[MAXN], lv[MAXN], par[MAXN];
int firstAns;

void show(int v){
	if (~par[v])
		show(par[v]);
	cout << v+1 << " ";
}

int mark[MAXN], del[MAXN];
int sec[MAXN], sz;
bool vis[MAXN];

void dfs(int v){
	sec[sz++] = v;
	vis[v] = true;
	for (int u:adj[v])
		if (u && !vis[u])
			dfs(u);
}

int mk[MAXN], gg;
void go(int u){
	sz = 0;
	dfs(u);

	gg++;
	for (int i = 0; i < sz; i++) mk[sec[i]] = gg, del[sec[i]] = true;
	for (int i = 0; i < sz; i++){
		u = sec[i];
		int cnt = 0;
		for (int w:adj[u])
			if (mk[w] == gg)
				cnt++;

		if (cnt != sz-1){
			memset(lv, 63, sizeof(lv));
			memset(par, -1, sizeof(par));
			int h = 0, t = 0;
			lv[u] = 0;
			q[t++] = u;
			while (t-h){
				int v = q[h++];
				for (int u:adj[v])
					if (u && lv[v]+1 < lv[u]){
						lv[u] = lv[v] + 1;
						par[u] = v;
						q[t++] = u;
					}
			}

			for (int v = 0; v < n; v++)
				if (lv[v] == 2){
					cout << "5\n";
					cout << "1 " << u+1 << " " << par[v]+1 << " " << v+1 << " " << u+1 << " " << n << "\n";
					exit(0);
				}
			exit(0);
		}
	}
}

int _q[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(lv, 63, sizeof(lv));
	memset(par, -1, sizeof(par));
	int h = 0, t = 0;
	lv[0] = 0;
	q[t++] = 0;
	while (t-h){
		int v = q[h++];
		for (int u:adj[v])
			if (lv[v]+1 < lv[u]){
				lv[u] = lv[v] + 1;
				par[u] = v;
				q[t++] = u;
			}
	}
	if (lv[n-1] < 4){
		cout << lv[n-1] << "\n";
		show(n-1);
		cout << "\n";
		return 0;
	}

	t = 0;
	for (int v = 1; v < n; v++)
		if (lv[v] < 1e8)
			q[t++] = v;

	{
		for (int i = 0; i < t; i++)
			if (lv[q[i]] == 2){
				cout << "4\n";
				cout << 1 << " " << par[q[i]]+1 << " " << q[i]+1 << " 1 " << n << "\n";
				return 0;
			}

		if (lv[n-1] >= 5){
			memcpy(_q, q, sizeof(q));
			for (int i = 0; i < t; i++)
				mark[_q[i]] = 1;
			for (int i = 0; i < t; i++)
				if (!del[_q[i]])
					go(_q[i]);
		}
	}
	if (lv[n-1] < 1e8){
		cout << lv[n-1] << "\n";
		show(n-1);
		cout << "\n";
		return 0;
	}

	cout << "-1\n";
	return 0;
}