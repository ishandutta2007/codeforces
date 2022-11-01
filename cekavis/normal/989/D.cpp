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
const int N = 100005;
int n, l, w;
ll ans;
pair<int,int> a[N];
inline void solve(pair<int,int> *x, int n){
	queue<ll> q;
	int tot=0;
	per(i, n, 1) if(x[i].second==1){
		while(!q.empty() && q.front()>(ll)(w+1)*x[i].first) q.pop(), ++tot;
		ans+=tot;
	}
	else q.push((ll)(w-1)*(x[i].first+l));
}
int main() {
	read(n), read(l), read(w);
	rep(i, 1, n) read(a[i].first), read(a[i].second);
	sort(a+1, a+n+1);
	rep(i, 1, n) if(-l<a[i].first && a[i].first<0){
		if(a[i].second==1) rep(j, i+1, n) if(a[j].second==-1) ++ans;
		if(a[i].second==-1) rep(j, 1, i-1) if(a[j].second==1) ++ans;
		Rep(j, i, n) a[j]=a[j+1];
		--n;
		break;
	}
	int mid=1;
	while(a[mid].first<0) ++mid;
	int tot=0;
	Rep(i, 1, mid) if(a[i].second==1) ++tot;
	rep(i, mid, n) if(a[i].second==-1) ans+=tot;
	solve(a+mid-1, n-mid+1);
	Rep(i, 1, mid) a[i].first=-a[i].first-l, a[i].second=-a[i].second;
	sort(a+1, a+mid);
	solve(a, mid-1);
	printf("%lld", ans);
	return 0;
}