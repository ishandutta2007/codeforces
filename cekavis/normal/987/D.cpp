#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define Rep(i,x,y) for(int i=(x);i<(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
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
#include<queue>
const int N = 100005, K = 105;
int n, m, k, s, num, a[N], dis[N], h[N], e[N<<1], pre[N<<1], ans[N][K];
queue<int> qq[K];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
int main() {
	read(n), read(m), read(k), read(s);
	rep(i, 1, n) read(a[i]), qq[a[i]].push(i);
	rep(i, 1, m){
		static int x, y;
		read(x), read(y);
		add(x, y), add(y, x);
	}
	rep(i, 1, k){
		memset(dis, 0x3f3f3f3f, sizeof dis);
		rep(j, 1, n) if(a[j]==i) dis[j]=0;
		queue<int> &q=qq[i];
		while(!q.empty()){
			int u=q.front(); q.pop();
			travel(j, u) if(dis[u]<dis[e[j]]) dis[e[j]]=dis[u]+1, q.push(e[j]);
		}
		rep(j, 1, n) ans[j][i]=dis[j];
	}
	rep(i, 1, n){
		nth_element(ans[i]+1, ans[i]+s+1, ans[i]+k+1);
		int ass=0;
		rep(j, 1, s) ass+=ans[i][j];
		printf("%d ", ass);
	}
	return 0;
}