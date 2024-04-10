#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

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
const int N = 1000005, P = 998244353;
int n, m, cnt, r, c, x2, x1, y2, y1, sum, f[N];
struct st{
	int v, x, y;
	inline bool operator <(const st &rhs)const{ return v<rhs.v;}
}a[N];
inline int Pow(ll x, int y=P-2){
	ll ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	read(n), read(m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) read(a[++cnt].v), a[cnt].x=i, a[cnt].y=j;
	read(r), read(c);
	sort(a+1, a+cnt+1);
	for(int i=1; i<=cnt; ++i){
		int j=i;
		while(a[j+1].v==a[j].v && j<cnt) ++j;
		// printf(">>%d %d %d %d\n", x1, x2, y1, y2);
		for(int k=i; k<=j; ++k){
			f[k]=(x2-2ll*x1*a[k].x+a[k].x*a[k].x*(i-1ll) + y2-2ll*y1*a[k].y+a[k].y*a[k].y*(i-1ll) + sum)%P*Pow(i-1)%P;
		}
		for(int k=i; k<=j; ++k){
			(x2+=a[k].x*a[k].x)%=P;
			x1+=a[k].x;
			(y2+=a[k].y*a[k].y)%=P;
			y1+=a[k].y;
			(sum+=f[k])%=P;
		}
		i=j;
	}
	for(int i=1; i<=cnt; ++i) if(a[i].x==r && a[i].y==c) printf("%d", (f[i]+P)%P);
	return 0;
}