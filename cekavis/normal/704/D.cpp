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
		if(l>z) puts("-1"), exit(0);
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
bool o;
int n, m, c1, c2;
map<int,int> sa, sb;
map<int,vector<int>> a, b;
int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	if(c1>c2) swap(c1, c2), o=1;
	for(int i=1, x, y; i<=n; ++i)
		scanf("%d%d", &x, &y), a[x].push_back(i), b[y].push_back(i);
	for(int i=1, x, y, z; i<=m; ++i){
		scanf("%d%d%d", &x, &y, &z);
		if(x==1) if(!sa.count(y)) sa[y]=z; else sa[y]=min(sa[y], z);
		else if(!sb.count(y)) sb[y]=z; else sb[y]=min(sb[y], z);
	}
	int p=n, S=++p, T=++p;
	for(auto &i:a){
		++p;
		if(!sa.count(i.first)) wish.add(S, p, n, 0);
		else{
			int s=i.second.size(), x=sa[i.first];
			wish.add(S, p, (s+x)/2, max(0, (s-x+1)/2));
		}
		for(int j:i.second) wish.add(p, j, 1, 0);
	}
	for(auto &i:b){
		++p;
		if(!sb.count(i.first)) wish.add(p, T, n, 0);
		else{
			int s=i.second.size(), x=sb[i.first];
			wish.add(p, T, (s+x)/2, max(0, (s-x+1)/2));
		}
		for(int j:i.second) wish.add(j, p, 1, 0);
	}
	int ans=wish.solve(S, T);
	if(ans==-1) return puts("-1"), 0;
	printf("%lld\n", (ll)c1*ans+(ll)c2*(n-ans));
	for(int i=1; i<=n; ++i)
		putchar(wish.e[i][wish.e[i][0].to>wish.e[i][1].to].f^o?'r':'b');
	return 0;
}