#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

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

const int N = 100005, K = 202, P = 1000000007;
int n, k, num, Ans, ans[K], p[K], C[K][K], S[K][K], siz[N], h[N], e[N<<1], pre[N<<1], f[N][K];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u, int fa=0){
	f[u][0]=1;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa){
		dfs(e[i], u), siz[u]+=siz[e[i]];
		for(int j=min(siz[u], k); j; --j){
			f[e[i]][j]=(f[e[i]][j]+(ll)f[e[i]][j-1]*j)%P;
			ans[j]=(ans[j]-f[e[i]][j]+P)%P;
		}
		++f[e[i]][0];
		for(int j=min(siz[u], k); ~j; --j){
			f[u][j]=(ll)f[u][j]*f[e[i]][0]%P;
			for(int t=max(j-siz[e[i]], 0); t<j && t<=siz[u]-siz[e[i]]; ++t)
				f[u][j]=(f[u][j]+(ll)f[u][t]*f[e[i]][j-t]%P*C[j][t])%P;
		}
	}
	for(int i=0; i<=k && i<=siz[u]; ++i) f[u][i]=f[u][i]*2%P;
	f[u][0]=(f[u][0]-1+P)%P;
	for(int i=0; i<=k && i<=siz[u]; ++i) (ans[i]+=f[u][i])%=P;
	++siz[u];
}
int main() {
	read(n), read(k);
	C[0][0]=S[0][0]=p[0]=1;
	for(int i=1; i<=k; ++i) p[i]=p[i-1]*2%P;
	for(int i=1; i<=k; ++i) for(int j=0; j<=i; ++j){
		C[i][j]=(C[i-1][j]+(j?C[i-1][j-1]:0))%P;
		if(j) S[i][j]=(S[i-1][j-1]+(ll)j*S[i-1][j])%P;
	}
	for(int i=1, x, y; i<n; ++i) read(x), read(y), add(x, y), add(y, x);
	dfs(1);
	for(int i=0; i<=k; ++i) Ans=(Ans+(ll)ans[i]*S[k][i])%P;
	return printf("%d", Ans), 0;
}