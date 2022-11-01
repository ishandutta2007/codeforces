#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 52, M = 2555, inf = 1e9;
int n, h, m, S, T, cnt, ans, tot[M], d[M], cur[M];
struct edge{ int v, f, id;};
vector<edge> e[M];
inline void add(int x, int y, int z){
	e[x].push_back((edge){y, z, e[y].size()});
	e[y].push_back((edge){x, 0, e[x].size()-1});
}
int sap(int u, int flow){
	if(u==T || !flow) return flow;
	int now=0;
	for(int &i=cur[u]; i<(int)e[u].size(); ++i){
		edge &p=e[u][i];
		if(d[p.v]+1==d[u]){
			int tmp=sap(p.v, min(flow-now, p.f));
			p.f-=tmp, now+=tmp, e[p.v][p.id].f+=tmp;
			if(now==flow) return now;
		}
	}
	cur[u]=0;
	if(!--tot[d[u]]) d[T]=cnt;
	++tot[++d[u]];
	return now;
}
int main() {
	scanf("%d%d%d", &n, &h, &m);
	S=n*h+1, T=S+1;
	for(int i=1; i<=n; ++i){
		add(S, ++cnt, h*h);
		for(int i=1; i<h; ++i) add(cnt, cnt+1, h*h-i*i), ++cnt;
		add(cnt, T, 0);
	}
	cnt+=2;
	while(m--){
		int l, r, x, c;
		scanf("%d%d%d%d", &l, &r, &x, &c);
		add(++cnt, T, c);
		if(x<h) for(int i=l; i<=r; ++i) add((i-1)*h+x+1, cnt, inf);
	}
	tot[0]=cnt;
	while(d[T]!=cnt) ans+=sap(S, inf);
	return printf("%d", h*h*n-ans), 0;
}