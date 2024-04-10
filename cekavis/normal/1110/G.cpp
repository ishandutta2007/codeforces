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

const int N = 500005;
int T, n, S, x, mx, num, cnt, a[N], d[N], h[N], fa[N], e[N<<1], pre[N<<1];
char col[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u, int dep=0){
	if(dep>mx) mx=dep, S=u;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u]) fa[e[i]]=u, dfs(e[i], dep+1);
}
int main() {
	read(T);
	while(T--){
		num=0, memset(h+1, 0, n<<2), memset(d+1, 0, n<<2);
		read(n);
		for(int i=1, x=0, y=0; i<n; ++i) read(x), read(y), add(x, y), add(y, x), ++d[x], ++d[y];
		while(isspace(col[1]=read()));
		for(int i=2; i<=n; ++i) col[i]=read();
		if(n<=2){
			puts("Draw");
			goto nxt;
		}
		for(int i=1; i<=n; ++i) if(d[i]>3){
			puts("White");
			goto nxt;
		}
		mx=fa[1]=0, dfs(1);
		x=S, cnt=0;
		mx=fa[x]=0, dfs(x);
		while(S!=x) a[++cnt]=S, S=fa[S];
		a[++cnt]=x;
		for(int i=3; i<cnt-1; ++i) if(d[a[i]]>2){
			puts("White");
			goto nxt;
		}
		if(n==3){
			puts((col[1]=='W')+(col[2]=='W')+(col[3]=='W')>1?"White":"Draw");
			goto nxt;
		}
		for(int i=1; i<=n; ++i) if(col[i]=='W' && !(d[i]==1 && d[i==x?a[cnt-1]:fa[i]]==2)){
			puts("White");
			goto nxt;
		}
		if(cnt>3 && (cnt&1) && (d[a[2]]==3 || col[a[1]]=='W') && (d[a[cnt-1]]==3 || col[a[cnt]]=='W'))
			puts("White");
		else puts("Draw");
		nxt:;
	}
	return 0;
}