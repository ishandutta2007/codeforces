#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<vector>
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
const int N = 300005, K = 1000005;
int n, k, top, L[N], stk[N], a[N], s[N], b[K];
vector<int> f[N];
ll ans;
int main() {
	read(n), read(k);
	rep(i, 1, n) read(a[i]), s[i]=(s[i-1]+a[i])%k;
	rep(i, 1, n){
		while(top && a[stk[top]]<=a[i]) --top;
		L[i]=stk[top];
		stk[++top]=i;
	}
	stk[top=0]=n+1;
	for(int i=n; i; --i){
		while(top && a[stk[top]]<a[i]) --top;
		if(stk[top]-i<=i-L[i]) for(int j=i; j<stk[top]; ++j){
			if(L[i]) f[L[i]-1].push_back((k+s[j]-s[i]+s[i-1])%k+k);
			f[i-1].push_back((k+s[j]-s[i]+s[i-1])%k);
		}
		else for(int j=L[i]; j<i; ++j) f[i-1].push_back((k+s[i]+s[j]-s[i-1])%k+k), f[stk[top]-1].push_back((k+s[i]+s[j]-s[i-1])%k);
		stk[++top]=i;
	}
	rep(i, 0, n){
		++b[s[i]];
		for(int j:f[i]) if(j>=k) ans-=b[j-k]; else ans+=b[j];
	}
	return printf("%lld", ans-n), 0;
}