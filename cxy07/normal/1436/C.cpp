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
#define vec vector

const int MAXN = 1010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, x, pos;
int cntmax, cntmin;
int L = 0, R, mid;
int ans = 1;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(x); read(pos);
	cntmax = n - x;
	cntmin = x - 1;
	L = 0, R = n;
	while(L < R) {
		mid = (L + R) / 2;
		if(mid <= pos) {
			if(mid != pos) (ans *= (cntmin--)) %= mod;
			L = mid + 1;
		} else {
			if(mid != pos) (ans *= (cntmax--)) %= mod;
			R = mid;
		}
	}
	if(cntmax < 0 || cntmin < 0) return puts("0"), 0;
	for(int i = 1; i <= cntmax + cntmin; ++i)
		(ans *= i) %= mod;
	cout << (ans % mod + mod) % mod;
	return 0;
}