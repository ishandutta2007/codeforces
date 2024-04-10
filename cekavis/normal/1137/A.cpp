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

const int N = 1005;
int n, m, f[N], g[N], a[N][N], b[N][N], c[N][N];
pair<int,int> p[N];
int main() {
	read(n), read(m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) read(a[i][j]);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j) p[j]=make_pair(a[i][j], j);
		sort(p+1, p+m+1);
		int cnt=0;
		for(int j=1; j<=m; ++j) b[i][p[j].second]=(p[j].first==p[j-1].first?cnt:++cnt);
		f[i]=cnt;
	}
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=n; ++j) p[j]=make_pair(a[j][i], j);
		sort(p+1, p+n+1);
		int cnt=0;
		for(int j=1; j<=n; ++j) c[p[j].second][i]=(p[j].first==p[j-1].first?cnt:++cnt);
		g[i]=cnt;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			int t=max(b[i][j], c[i][j]);
			printf("%d ", max(f[i]-b[i][j]+t, g[j]-c[i][j]+t));
		}
		puts("");
	}
	return 0;
}