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

const int MAXN = 1010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m;
double dp[MAXN][MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

double DP(int x,int y) {
	if(x < 0 || y < 0) return 0.;
	if(!x) return 0.;
	if(!y) return 1.;
	if(dp[x][y]) return dp[x][y];
	if(x + y) dp[x][y] = (1. * x / (x + y));
	if(x + y > 2 && y >= 1) dp[x][y] += DP(x - 1,y - 2) * (1. * y / (x + y)) * (1. * (y - 1) / (x + y - 1)) * (1. * x / (x + y - 2));
	if(x + y > 2 && y >= 2) dp[x][y] += DP(x,y - 3) * (1. * y / (x + y)) * (1. * (y - 1) / (x + y - 1)) * (1. * (y - 2) / (x + y - 2));
	return dp[x][y];
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	printf("%.10lf\n",DP(n,m));
	return 0;
}