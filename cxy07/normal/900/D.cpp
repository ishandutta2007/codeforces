//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,x,y,ans;
int pr[MAXN],cnt;
bool np[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void Sieve(int siz) {
	for(int i = 2;i <= siz; ++i) {
		if(!np[i]) pr[++cnt] = i;
		for(int j = 1;j <= cnt && pr[j] * i <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

int qpow(int x,int b) {
	int res = 1;
	for(;b;b >>= 1,(x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

int g(int x) {
	return qpow(2,x - 1);
}

int mu(int x) {
	int res = 0;
	for(int i = 1,now;pr[i] * pr[i] <= x; ++i) {
		if(x % pr[i]) continue;
		now = 0;
		while(x % pr[i] == 0) x /= pr[i],now++;
		if(now > 1) return 0;
		res++;
	}
	if(x ^ 1) res++;
	return (res & 1) ? -1 : 1;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	Sieve(1e5);
	read(x); read(y);
	if(y % x) return puts("0"),0;
	n = y / x;
	for(int i = 1;i * i <= n; ++i) {
		if(n % i) continue;
		(ans += g(i) * mu(n / i) % mod) %= mod;
		if(i * i != n) (ans += g(n / i) * mu(i) % mod) %= mod;
	}
	printf("%lld\n",(ans % mod + mod) % mod);
	return 0;
}