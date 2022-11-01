#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505, M = 105, K = N*4+N*M*2, inf = 1e9;
int n, m, X, num, len[M], x[N], h[N<<1], f[N<<1], nxt[N<<1], e[K], w[K], c[K], pre[K], q[K<<2];
ll ans, dis[N<<1];
bool vis[N<<1];
char s[N], b[N];
inline void add(int x, int y, int a, int b){
	e[++num]=y, w[num]=a, c[num]=b, pre[num]=h[x], h[x]=num;
	e[++num]=x, w[num]=0, c[num]=-b, pre[num]=h[y], h[y]=num;
}
inline bool spfa(int S, int T){
	memset(dis, -1, sizeof dis), memset(f, 0, sizeof f);
	int r=1;
	q[1]=S, f[S]=inf, dis[S]=0;
	for(int l=1; l<=r; ++l){
		int u=q[l];
		for(int i=h[u]; i; i=pre[i]) if(w[i] && dis[u]+c[i]>dis[e[i]]){
			dis[e[i]]=dis[u]+c[i], f[e[i]]=min(f[u], w[i]), nxt[e[i]]=i^1;
			if(!vis[e[i]]) q[++r]=e[i], vis[e[i]]=1;
		}
		vis[u]=0;
	}
	if(!f[T]) return 0;
	ans+=f[T]*dis[T];
	for(int x=T; x!=S; x=e[nxt[x]]) w[nxt[x]]+=f[T], w[nxt[x]^1]-=f[T];
	return 1;
}
int main() {
	scanf("%d%s%d", &n, s+1, &m), num=1;
	for(int i=1, q, len; i<=m; ++i){
		scanf("%s%d", b+1, &q), len=strlen(b+1);
		for(int j=1; j<=n-len+1; ++j){
			for(int k=1; k<=len; ++k) if(s[j+k-1]!=b[k]) goto nxt;
			add(j*2-1, (j+len-1)*2, 1, q);
			nxt:;
		}
	}
	scanf("%d", &X);
	for(int i=1; i<=n; ++i) x[i]=X;
	int S=0, T=n*2+1;
	add(S, 1, 100, 0), add(n*2, T, 100, 0);
	for(int i=1; i<=n; ++i) add(i*2-1, i*2, 100-x[i], inf), add(i*2-1, i*2, 100, 0);
	for(int i=1; i<n; ++i) add(i*2, i*2+1, 100, 0);
	while(spfa(S, T));
	return printf("%lld", ans%inf), 0;
}