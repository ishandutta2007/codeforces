#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005, M = 55;
int n, m, d, id, num, cnt, top, stk[N], bl[N], dfn[N], low[N], dep[N], q[N], w[N<<1], du[N<<1], f[N<<1], h[N<<1], e[N<<1], pre[N<<1], ans[N<<1][M];
char s[N][M];
bool instk[N];
inline void add(int x, int y, int z=0){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
inline int gcd(int x, int y){ return y?gcd(y, x%y):x;}
inline void chkmx(int &x, int y){ x=(x<y?y:x);}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	instk[stk[++top]=u]=1;
	for(int i=h[u]; i; i=pre[i])
		if(!dfn[e[i]]) dep[e[i]]=dep[u]+1, tarjan(e[i]), low[u]=min(low[u], low[e[i]]);
		else if(instk[e[i]]) low[u]=min(low[u], dfn[e[i]]);
	if(dfn[u]==low[u]){
		++id;
		do{
			int v=stk[top];
			bl[v]=id, instk[v]=0;
			dep[v]-=dep[u];
		} while(stk[top--]!=u);
	}
}
int main() {
	read(n), read(m), read(d), id=n;
	for(int i=1, x=0, y=0; i<=m; ++i) read(x), read(y), add(x, y);
	for(int i=1; i<=n; ++i){
		while(isspace(s[i][0]=read()));
		for(int j=1; j<d; ++j) s[i][j]=read();
	}
	tarjan(1);
	for(int i=n+1; i<=id; ++i) f[i]=d;
	for(int i=1; i<=n; ++i) if(dfn[i]) for(int j=h[i]; j; j=pre[j])
		if(bl[i]==bl[e[j]]) f[bl[i]]=gcd(f[bl[i]], abs(dep[i]-dep[e[j]]+1));
	for(int i=1; i<=n; ++i) if(dfn[i]){
		dep[i]%=f[bl[i]];
		static int a[M];
		memset(a, 0, sizeof a);
		for(int j=0; j<d; ++j) a[(d-dep[i]+j)%f[bl[i]]]|=(s[i][j]=='1');
		for(int j=0; j<f[bl[i]]; ++j) ans[bl[i]][j]+=a[j];
	}
	for(int i=1; i<=n; ++i) if(dfn[i])
		for(int j=h[i]; j; j=pre[j]) if(bl[i]!=bl[e[j]])
			add(bl[i], bl[e[j]], dep[i]+1), ++du[bl[e[j]]];
	// for(int j=1; j<=n; ++j){
	// 	printf("%d %d\n", bl[j], f[bl[j]]);
	// 	for(int i=0; i<d; ++i) printf("[%d]", ans[bl[j]][i]);
	// 	puts("");
	// }
	int r=0;
	for(int i=n+1; i<=id; ++i) if(!du[i]) q[++r]=i;
	for(int l=1; l<=r; ++l){
		int u=q[l];
		// printf(">> %d\n", u);
		for(int j=h[u]; j; j=pre[j]) if(!--du[e[j]]) q[++r]=e[j];
	}
	for(int l=r; l; --l){
		int u=q[l];
		static int a[M];
		memset(a, 0, sizeof a);
		for(int j=h[u]; j; j=pre[j])
			for(int k=0; k<d; ++k) chkmx(a[(k-w[j]+d)%f[u]], ans[e[j]][k]);
		for(int k=0; k<f[u]; ++k) ans[u][k]+=a[k];
		for(int k=f[u]; k<d; ++k) ans[u][k]=ans[u][k-f[u]];
	}
	return printf("%d", ans[bl[1]][0]), 0;
}