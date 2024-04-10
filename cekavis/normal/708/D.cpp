#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int inf = 1e9, N = 105;
int n, m, ans, a[N];
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
int main() {
	scanf("%d%d", &n, &m);
	while(m--){
		int u, v, c, f;
		scanf("%d%d%d%d", &u, &v, &c, &f);
		a[u]+=f, a[v]-=f;
		if(f<=c){
			wish.add(u, v, c-f, 1);
			wish.add(u, v, inf, 2);
			wish.add(v, u, f, 1);
		}
		else{
			ans+=f-c;
			wish.add(u, v, inf, 2);
			wish.add(v, u, f-c, 0);
			wish.add(v, u, c, 1);
		}
	}
	for(int i=1; i<=n; ++i)
		if(a[i]>0) wish.add(i, n+2, a[i], 0); else wish.add(n+1, i, -a[i], 0);
	wish.add(n, 1, inf, 0);
	printf("%d\n", wish.solve(n+1, n+2).second+ans);
	return 0;
}