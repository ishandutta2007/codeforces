#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int inf = 1e9;
struct MaxFlow{
	struct edge{ int to, f, id;};
	int n, tar;
	vector<int> d, cur, w;
	vector<vector<edge>> e;
	void ext(int x){ if(++x>n) e.resize(n=x), w.resize(n);}
	inline void add(int x, int y, int z, int l){
		ext(x), ext(y), w[y]+=l, w[x]-=l;
		e[x].push_back((edge){y, z-l, (int)e[y].size()});
		e[y].push_back((edge){x, 0, (int)e[x].size()-1});
	}
	bool bfs(int s){
		int r=1;
		vector<int> q(n);
		fill(d.begin(), d.end(), 0), d[s]=1, q[1]=s;
		for(int l=1; l<=r; ++l) for(edge &i:e[q[l]])
			if(i.f && !d[i.to]) d[i.to]=d[q[l]]+1, q[++r]=i.to;
		return d[tar];
	}
	int dfs(int u, int flow=inf){
		if(u==tar || !flow) return flow;
		int now=0;
		for(int &i=cur[u]; i<(int)e[u].size(); ++i){
			edge &p=e[u][i];
			if(p.f && d[p.to]==d[u]+1){
				int t=dfs(p.to, min(flow-now, (int)p.f));
				p.f-=t, e[p.to][p.id].f+=t, now+=t;
				if(now==flow) return now;
			}
		}
		return now;
	}
	int solve(int s, int t){
		int ans=0, ss=n, tt=n+1;
		ext(tt);
		d.resize(n), cur.resize(n);
		add(t, s, inf, 0);
		for(int i=1; i<ss; ++i)
			if(w[i]<0) add(i, tt, -w[i], 0);
			else if(w[i]>0) add(ss, i, w[i], 0);
		tar=tt;
		while(bfs(ss)) fill(cur.begin(), cur.end(), 0), dfs(ss);
		for(edge &i:e[ss]) if(i.f) return -1;
		tar=t;
		while(bfs(s)) fill(cur.begin(), cur.end(), 0), dfs(s);
		for(edge &i:e[s]) if(i.to!=t && i.to!=ss && i.to!=tt)
			ans+=e[i.to][i.id].f;
		return ans-w[s];
	}
} wish;
const int N = 200005;
int n;
vector<int> a[N], b[N];
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<=n; ++i)
		scanf("%d%d", &x, &y), a[x].push_back(i), b[y].push_back(i);
	int p=n, S=++p, T=++p;
	for(int i=1, s; i<=200000; ++i) if(s=a[i].size()){
		++p;
		wish.add(S, p, (s+1)/2, s/2);
		for(int j:a[i]) wish.add(p, j, 1, 0);
	}
	for(int i=1, s; i<=200000; ++i) if(s=b[i].size()){
		++p;
		wish.add(p, T, (s+1)/2, s/2);
		for(int j:b[i]) wish.add(j, p, 1, 0);
	}
	wish.solve(S, T);
	for(int i=1; i<=n; ++i)
		putchar(wish.e[i][wish.e[i][0].to>wish.e[i][1].to].f?'r':'b');
	return 0;
}