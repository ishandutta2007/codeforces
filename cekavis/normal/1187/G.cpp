#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 55, inf = 1e9;
struct MinCost{
	struct edge{ int v, f, w, id;};
	int n;
	vector<vector<edge>> e;
	void ext(int x){ if(++x>n) e.resize(x), n=x;}
	void add(int x, int y, int c, int w){
		ext(x), ext(y);
		e[x].push_back((edge){y, c, w, (int)e[y].size()});
		e[y].push_back((edge){x, 0, -w, (int)e[x].size()-1});
	}
	pair<int,int> solve(int S, int T){
		pair<int,int> ans=make_pair(0, 0);
		while(1){
			vector<int> f(n+1), g(n+1), vis(n+1), dis(n+1, inf);
			queue<int> q;
			q.push(S), f[S]=inf, dis[S]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto &i:e[u]){
					if(i.f && dis[u]+i.w<dis[i.v]){
						dis[i.v]=dis[u]+i.w, f[i.v]=min(f[u], i.f), g[i.v]=i.id;
						if(!vis[i.v]) q.push(i.v);
					}
				}
				vis[u]=0;
			}
			if(!f[T]) break;
			ans.first+=f[T], ans.second+=f[T]*dis[T];
			for(int i=T; i!=S;){
				auto &t=e[i][g[i]];
				t.f+=f[T], e[t.v][t.id].f-=f[T], i=t.v;
			}
		}
		return ans;
	}
} wish;
int n, m, k, c, d, a[N];

int main() {
	scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
	int S=101*n+1, T=S+1;
	for(int i=0; i<100; ++i) for(int j=1; j<=n; ++j)
		wish.add(i*n+j, i*n+n+j, inf, 0);
	for(int i=0; i<=100; ++i) wish.add(i*n+1, T, inf, c*i);
	for(int i=1, x; i<=k; ++i) scanf("%d", &x), ++a[x];
	for(int i=1; i<=n; ++i) if(a[i]) wish.add(S, i, a[i], 0);
	for(int i=1, x, y; i<=m; ++i){
		scanf("%d%d", &x, &y);
		for(int t=0; t<100; ++t) for(int j=1; j<=k; ++j)
			wish.add(t*n+x, t*n+n+y, 1, (j*2-1)*d),
			wish.add(t*n+y, t*n+n+x, 1, (j*2-1)*d);
	}
	auto ans=wish.solve(S, T);
	assert(ans.first==k);
	printf("%d\n", ans.second);
	return 0;
}