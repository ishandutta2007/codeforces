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

const int N = 200005;
int n, S, mn, ct, cnt, cnt2, a[N], b[N], siz[N], f[1<<20];
ll ans[N];
char c[N];
bool vis[N];
vector<int> e[N];
void dfs(int u, int fa=0){
	siz[u]=1;
	int mx=0;
	for(int v:e[u]) if(v!=fa && !vis[v])
		dfs(v, u), siz[u]+=siz[v], mx=max(mx, siz[v]);
	if((mx=max(mx, S-siz[u]))<mn) mn=mx, ct=u;
}
int find(int u, int size){ return mn=n, S=size, dfs(u), ct;}
void dfs2(int u, int s=0, int fa=0){
	++f[a[++cnt]=s^=1<<c[u]];
	for(int v:e[u]) if(v!=fa && !vis[v]) dfs2(v, s, u);
}
void dfs3(int u, int s=0, int fa=0){
	--f[b[++cnt2]=s^=1<<c[u]];
	for(int v:e[u]) if(v!=fa && !vis[v]) dfs3(v, s, u);
}
int calc(int s){
	int sum=f[s];
	for(int i=0; i<20; ++i) sum+=f[s^(1<<i)];
	return sum;
}
ll dfs4(int u, int s=0, int fa=0){
	ll t=calc(s^=1<<c[u]);
	for(int v:e[u]) if(v!=fa && !vis[v]) t+=dfs4(v, s, u);
	return ans[u]+=t, t;
}
void divide(int u, int size){
	if(size==1) return;
	u=find(u, size), vis[u]=1;
	dfs2(u);
	// printf("divide: %d %d %d\n", u, f[1], f[3]);
	ll sum=0;
	for(int v:e[u]) if(!vis[v]){
		dfs3(v, 1<<c[u]), sum+=dfs4(v);
		while(cnt2) ++f[b[cnt2--]];
	}
	ans[u]+=(calc(0)+sum)/2;
	while(cnt) f[a[cnt--]]=0;
	for(int v:e[u]) if(!vis[v]) divide(v, siz[v]<siz[u]?siz[v]:size-siz[u]);
}
int main() {
	read(n);
	for(int i=1, x=0, y=0; i<n; ++i) read(x), read(y), e[x].push_back(y), e[y].push_back(x);
	while(isspace(c[1]=read()));
	c[1]-='a';
	for(int i=2; i<=n; ++i) c[i]=read()-'a';
	divide(1, n);
	for(int i=1; i<=n; ++i) print(ans[i]+1), print(' ');
	return flush(), 0;
}