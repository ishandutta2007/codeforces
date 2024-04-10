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

const int N = 1000005;
int n, q, top, x[N], y[N], a[N], stk[N];
ll ans[N], s1[N], s2[N], f[N];
vector<pair<int,int>> w[N];
inline void solve(){
	top=0;
	for(int i=1; i<=n; ++i){
		ll tmp=0;
		while(top && a[stk[top]]<a[i]) tmp+=f[top]+i-stk[top-1]-1, --top;
		stk[++top]=i, s1[top]=s1[top-1]+i;
		s2[top]=s2[top-1]+(f[top]=tmp);
		// for(int j=1; j<=top; ++j) printf("[%d %lld]", stk[j], s1[j]); puts("");

		for(auto j:w[i]){
			int x=lower_bound(stk+1, stk+top+1, j.first)-stk;
			// printf(">> %d %d %d\n", j.first, x, top);
			ans[j.second]+=(ll)i*(top-x+1)-s1[top]+s1[x-1]+s2[top]-s2[x];
		}
	}
}
int main() {
	read(n), read(q);
	for(int i=1; i<=n; ++i) read(a[i]);
	for(int i=1; i<=q; ++i) read(x[i]);
	for(int i=1; i<=q; ++i)
		read(y[i]), w[y[i]].push_back(make_pair(x[i], i));
	solve();
	reverse(a+1, a+n+1);
	for(int i=1; i<=n; ++i) w[i].clear();
	for(int i=1; i<=q; ++i) w[n-x[i]+1].push_back(make_pair(n-y[i]+1, i));
	solve();
	for(int i=1; i<=q; ++i) print(ans[i]+y[i]-x[i]+1), print(' ');
	return flush(), 0;
}