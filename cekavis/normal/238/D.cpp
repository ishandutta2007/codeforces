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

const int N = 100005, M = N*11;
int n, q, cnt, top, l[N], r[N], ans[N], vis[N<<1], stk[N<<1], nxt[N<<1][2], a[M], f[M][10];
char s[N<<1];
vector<pair<int,int>> g[M];
inline int cmp(int x, int y){ return a[x]<y;}
int main() {
	read(n), read(q), fill(s+1, s+n+1, '>');
	while(isspace(s[n+1]=read()));
	for(int i=2; i<=n; ++i) s[n+i]=read();
	for(int i=1; i<=n<<1; ++i) nxt[i][0]=i-1, nxt[i][1]=i+1;
	int now=n+1, x=1;
	memset(vis, 0x3f3f3f3f, sizeof vis);
	for(int i=1; now; ++i){
		a[++cnt]=now;
		if(vis[now]==0x3f3f3f3f) vis[now]=i;
		memcpy(f[i], f[i-1], 10<<2);
		if(isdigit(s[now])){
			++f[i][s[now]-'0'];
			if(--s[now]<'0') nxt[nxt[now][0]][1]=nxt[now][1], nxt[nxt[now][1]][0]=nxt[now][0];
		}
		else{
			if(s[now]=='<') x=0; else if(s[now]=='>') x=1; 
			if(!isdigit(s[nxt[now][x]])) nxt[nxt[now][0]][1]=nxt[now][1], nxt[nxt[now][1]][0]=nxt[now][0];
		}
		now=nxt[now][x];
	}
	for(int i=1; i<=q; ++i) read(l[i]), read(r[i]), l[i]+=n, r[i]+=n, g[vis[l[i]]].push_back(make_pair(l[i], i));
	stk[0]=0x3f3f3f3f;
	for(int i=cnt; i; --i){
		while(top && a[stk[top]]>=a[i]) --top;
		stk[++top]=i;
		for(auto j:g[i]) ans[j.second]=*(lower_bound(stk+1, stk+top, j.first, cmp)-1);
	}
	for(int i=1; i<=q; ++i){
		int L=vis[l[i]]-1, R=min(ans[i], vis[r[i]+1])-1;
		for(int j=0; j<10; ++j) print(f[R][j]-f[L][j]), print(j==9?'\n':' ');
	}
	return flush(), 0;
}