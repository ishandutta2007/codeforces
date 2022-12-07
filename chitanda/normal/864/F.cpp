#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 3015, maxq = 400015;
int n, m, Q;
int ans[maxq];
int vis[maxn], sta[maxn], top, path[maxn], bg, ed;
vector<int> g[maxn];
vector<pair<int, pii>> que[maxn];
vector<pii> q[maxn];
bool flag[maxn];
bool insta[maxn];

void ddfs(int t){
	flag[t] = 1;
	vis[t] = -1;
	for(int v : g[t])
		if(vis[v] != -1) ddfs(v);
}

void dfs(int t){
	sta[++top] = t;
	vis[t] = top;
	insta[t] = 1;
	for(auto v : q[t]){
		if(!flag[t]){
			if(top >= v.fi) ans[v.se] = sta[v.fi];
			else ans[v.se] = -1;
		}else{
			/*
			if(v.fi <= bg) ans[v.se] = path[v.fi];
			else{
				int x = (v.fi - bg) % (ed - bg + 1);
				ans[v.se] = path[bg + x];
			}
			*/
		}
	}
	for(int v : g[t]){
		if(vis[v] == 0){
			if(!flag[t]) dfs(v);
		}else if(insta[v]){
			if(!flag[t]){
				ddfs(t);
			}
			/*
			memcpy(path, sta, sizeof(sta));
			ed = top;
			bg = vis[v];
			*/
		}
		//if(flag[t]) break;
	}
	insta[t] = 0;
	--top;
}

void work(int S){
	for(int i = 1; i <= n; ++i) q[i].clear(), vis[i] = 0, flag[i] = 0;
	for(auto v : que[S])
		q[v.fi].pb(v.se);
	dfs(S);
}

int main(){
	//freopen("data.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &Q);
	for(int i = 1, x, y; i <= m; ++i){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
	}
	for(int i = 1; i <= n; ++i)
		sort(g[i].begin(), g[i].end());
	for(int i = 1, s, t, k; i <= Q; ++i){
		scanf("%d%d%d", &s, &t, &k);
		que[s].pb(mkp(t, mkp(k, i)));
	}
	memset(ans, -1, sizeof(ans));
	for(int i = 1; i <= n; ++i) work(i);
	for(int i = 1; i <= Q; ++i)
		printf("%d\n", ans[i]);

	return 0;
}