//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int G = 3;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;

int n,in,ans;
int pr[MAXN],cnt,mu[MAXN];
int E[MAXN],f[MAXN];
bool np[MAXN];
vector<int> s[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void Sieve(int siz) {
	mu[1] = 1;
	for(int i = 2;i <= siz; ++i) {
		if(!np[i]) {pr[++cnt] = i; mu[i] = -1;}
		for(int p = 1;pr[p] * i <= siz && p <= cnt; ++p) {
			np[pr[p] * i] = true;
			if(!(i % pr[p])) break;
			mu[pr[p] * i] = -mu[i];
		}
	}
	for(int i = 1;i <= siz; ++i) {
		for(int p = 1;p * p <= i; ++p)
			if(i % p == 0) {
				s[i].push_back(p);
				if(p != i / p) s[i].push_back(i / p);
			}
	}
}

int ksm(int x,int b) {
	int res = 1;
	for(;b;b >>= 1,(x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void update(int x) {
	for(int i = 1;i * x <= n; i++)
		f[i * x] += E[x] * mu[i];
}

void GetE(int i) {
	int div = inv(n - (n / i));
	E[i] = n;
	for(auto T:s[i]) (E[i] += (n / T) * f[T] % mod) %= mod;
	(E[i] *= div) %= mod;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	Sieve(1e5);
	read(n); in = inv(n);
	E[1] = 0;
	//puts("!");
	update(1);
	for(int i = 2;i <= n; ++i) {
		GetE(i);
		update(i);
	}
	for(int i = 1;i <= n; ++i)
		(ans += E[i]) %= mod;
	//ans += 1;
	(ans *= in) %= mod;
	printf("%lld\n",(ans + 1 + mod) % mod);
	return 0;
}