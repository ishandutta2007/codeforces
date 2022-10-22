//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 210;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, ans;
int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][(1 << 10) + 10];

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
	read(n); read(m);
	dp[0][0] = 1;
	for(int i = 1;i <= n; ++i) read(a[i]);
	for(int i = 1;i <= m; ++i) read(b[i]);
	for(int i = 1,c;i <= n; ++i) {
		for(int S = 0; S < (1 << 9); ++S)
			for(int j = 1;j <= m; ++j) 
				dp[i][S | (b[j] & a[i])] |= dp[i - 1][S];
	}
	for(int i = 0; i < (1 << 9); ++i)
		if(dp[n][i]) {
			cout << i << endl;
			return 0;
		}
	return 0;
}