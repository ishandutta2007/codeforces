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
	for (x = 0; isdigit(c); c = read())
		x = ((x + (x << 2)) << 1) + (c ^ '0');
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
const int N = 55;
int n, k, ans, cnt, a[5][N];
pair<int,int> f[N<<1], g[N<<1];
int main() {
	read(n), read(k);
	rep(i, 1, 4) rep(j, 1, n) read(a[i][j]);
	rep(i, 1, n){
		if(a[1][i] && a[1][i]==a[2][i]) print(a[1][i]), print(' '), print('1'), print(' '), print(i), print('\n'), a[1][i]=a[2][i]=0, --k, ++ans;
		if(a[4][i] && a[3][i]==a[4][i]) print(a[4][i]), print(' '), print('4'), print(' '), print(i), print('\n'), a[3][i]=a[4][i]=0, --k, ++ans;
	}
	if(k==n*2) return puts("-1"), 0;
	f[++cnt]=make_pair(2, 1), g[cnt]=make_pair(3, 1);
	rep(i, 1, n-1) f[++cnt]=make_pair(3, i), g[cnt]=make_pair(3, i+1);
	f[++cnt]=make_pair(3, n), g[cnt]=make_pair(2, n);
	for(int i=n; i>1; --i) f[++cnt]=make_pair(2, i), g[cnt]=make_pair(2, i-1);
	while(k){
		// rep(i, 1, n) printf("%d ", a[2][i]); puts("");
		// rep(i, 1, n) printf("%d ", a[3][i]); puts("");
		// puts("------------------");
		// printf("%d\n", k);
		rep(i, 1, cnt) if(!a[f[i].first][f[i].second]){
			int lim=(i==1?cnt-1:cnt);
			rep(j, i, lim) if(a[g[j].first][g[j].second])
				print(a[g[j].first][g[j].second]), print(' '), print(f[j].first), print(' '), print(f[j].second), print('\n'),
				swap(a[g[j].first][g[j].second], a[f[j].first][f[j].second]), ++ans;
			rep(j, 1, i-2)
				print(a[g[j].first][g[j].second]), print(' '), print(f[j].first), print(' '), print(f[j].second), print('\n'),
				swap(a[g[j].first][g[j].second], a[f[j].first][f[j].second]), ++ans;
			break;
		}
		rep(i, 1, n){
			if(a[1][i] && a[1][i]==a[2][i]) print(a[1][i]), print(' '), print('1'), print(' '), print(i), print('\n'), a[1][i]=a[2][i]=0, --k, ++ans;
			if(a[3][i] && a[3][i]==a[4][i]) print(a[4][i]), print(' '), print('4'), print(' '), print(i), print('\n'), a[3][i]=a[4][i]=0, --k, ++ans;
		}
	}
	printf("%d\n", ans);
	return flush(), 0;
}