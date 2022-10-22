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
#define inv(x) ksm((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 5010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int n,k,ans;
int str[MAXN][MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int qpow(int x,int b) {
	int res = 1;
	for(;b;b >>= 1,(x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(k);
	str[0][0] = 1;
	for(int i = 1;i <= k; ++i) 
		for(int j = 1;j <= i; ++j)
			str[i][j] = (str[i - 1][j - 1] + str[i - 1][j] * j % mod) % mod;
	int tmp = 1,n2 = qpow(2,n),inv2 = (mod + 1) >> 1;
	for(int i = 0;i <= k; ++i) {
		(ans += str[k][i] * tmp % mod * n2 % mod) %= mod;
		(tmp *= (n - i) % mod) %= mod;
		(n2 *= inv2) %= mod;
	}
	printf("%lld\n",ans);
	return 0;
}