#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define loop(k,a) for (int k=(a); ~k; k=link[k])
#define Next(x) ((x++)%maxn)
using namespace std;
 
const int maxn = 10009, maxm = 1000009, INF = 1e9;
struct edge { int u, v, w, f, c; };
struct flows {
	int n, s, t, limit, a[maxn], d[maxn], inq[maxn], q[maxn];
	int m, head[maxn], link[maxm], p[maxn];
	edge e[maxm];
	void init(int _n, int _limit = 0) {
		n = _n; m = 0; limit = _limit;
		memset(head, -1, sizeof head);
	}
	void add(int u, int v, int c, int w) {
		e[m].u = u; e[m].v = v; e[m].f = 0; e[m].c = c; e[m].w = w;
		link[m] = head[u]; head[u] = m++;
		e[m].u = v; e[m].v = u; e[m].f = 0; e[m].c = 0; e[m].w = -w;
		link[m] = head[v]; head[v] = m++;
	}
	bool SPFA(int s, int t, int &flow, int &cost) {
		int l = 0, r = 0, u;
		memset(d, 0x3f, sizeof d);
		memset(inq, 0, sizeof inq);
		d[s] = 0; q[Next(r)] = s; a[s] = INF;
		while (l < r) {
			u = q[Next(l)]; inq[u] = 0;
			loop (k, head[u])
				if (e[k].f < e[k].c && d[u] + e[k].w < d[e[k].v]) {
					d[e[k].v] = d[u] + e[k].w;
					a[e[k].v] = min(a[u], e[k].c - e[k].f);
					p[e[k].v] = k;
					if (!inq[e[k].v]) {
						q[Next(r)] = e[k].v; inq[e[k].v] = 1;
					}
				}
		}
		if (d[t] >= INF) return false;
		flow += a[t]; cost += a[t] * d[t]; u = t;
		while (u != s) {
			e[p[u]].f += a[t]; e[p[u]^1].f -= a[t];
			u = e[p[u]].u;
		}
		return true;
	}
	int MinCost(int s, int t) {
		int flow = 0, cost = 0;
		while (SPFA(s, t, flow, cost));
		if (flow < limit) return -1;
		return cost;
	}
} G;
 
const int N=1005;
int d[N],u[N],v[N],f[N],c[N];
int n,m,S,T,ans;
 
int main(){
	cin>>n>>m;
	rep(i,1,m){
		cin>>u[i]>>v[i]>>c[i]>>f[i];
		d[u[i]]-=f[i];
		d[v[i]]+=f[i];
		if(c[i]<f[i])ans+=f[i]-c[i];
	}
	S=n+1,T=S+1;
	G.init(T);
	rep(i,1,n)
		if(d[i]>0)G.add(S,i,d[i],0);
		else G.add(i,T,-d[i],0);
	rep(i,1,m)
		if(f[i]<c[i]){
			G.add(u[i],v[i],c[i]-f[i],1);
			G.add(u[i],v[i],INF,2);
			G.add(v[i],u[i],f[i],1);
		}
		else{
			G.add(u[i],v[i],INF,2);
			G.add(v[i],u[i],f[i]-c[i],0);
			G.add(v[i],u[i],c[i],1);
		}
	G.add(n,1,INF,0);
	printf("%d\n",ans+G.MinCost(S,T));
	return 0;
}