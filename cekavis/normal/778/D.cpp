#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig = false, c = read(); !isdigit(c); c = read()) {
		if (c == '-') iosig = true;
		if (c == -1) return;
	}
	for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (iosig) x = -x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
const int N = 55, M = 100005;
int n, m, cnt;
bool flag;
pair<int,int> a[M];
char trans['Z'], s[N][N], t[N][N];
inline void dfs(int x, int y){
	if(s[x][y+1]=='U') s[x][y]=s[x+1][y]='L', s[x][y+1]=s[x+1][y+1]='R', a[++cnt]=make_pair(x, y);
	else{
		if(s[x][y+1]=='D') dfs(x-1, y+1);
		if(s[x+1][y+1]=='U') dfs(x+1, y+1);
		s[x][y]=s[x+1][y]='L', s[x][y+1]=s[x+1][y+1]='R', s[x][y+2]='U', s[x+1][y+2]='D';
		a[++cnt]=make_pair(x, y+1), a[++cnt]=make_pair(x, y);
	}
}
inline void solve(){
	if(flag){
		memcpy(t, s, sizeof s);
		memset(s, 0, sizeof s);
		rep(i, 1, n) rep(j, 1, m) s[j][n-i+1]=trans[t[i][j]];
		swap(n, m);
	}
	// rep(i, 1, n) puts(s[i]+1);
	rep(i, 1, n) rep(j, 1, m) if(s[i][j]=='U') dfs(i, j);
	if(flag) swap(n, m), memcpy(s, t, sizeof t);
}
int main() {
	trans['L']='U';
	trans['R']='D';
	trans['U']='R';
	trans['D']='L';
	read(n), read(m);
	if(m&1) flag=1;
	rep(i, 1, n){
		while(isspace(s[i][1]=read()));
		rep(j, 2, m) s[i][j]=read();
	}
	solve();
	int tmp=cnt;
	rep(i, 1, n){
		while(isspace(s[i][1]=read()));
		rep(j, 2, m) s[i][j]=read();
	}
	solve();
	printf("%d\n", cnt);
	if(flag) rep(i, 1, cnt) swap(a[i].first, a[i].second), a[i].first=n-a[i].first;
	rep(i, 1, tmp) printf("%d %d\n", a[i].first, a[i].second);
	for(int i=cnt; i>tmp; --i) printf("%d %d\n", a[i].first, a[i].second);
	return 0;
}