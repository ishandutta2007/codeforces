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

const int MAXN = 5e5 + 10;
const int INF = 2e18;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int x[MAXN], y[MAXN];
int L, R, mid, X, Y;
char s[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

bool chk(int l) {
	int x1 = -INF, x2 = INF, y1 = -INF, y2 = INF, b1 = -INF, b2 = INF;//1:max, 2:min
	for(int i = 1; i <= n; ++i) {
		x1 = max(x1, x[i] - l);
		x2 = min(x2, x[i] + l);
		y1 = max(y1, y[i] - l);
		y2 = min(y2, y[i] + l);
		b1 = max(b1, x[i] - y[i] - l);
		b2 = min(b2, x[i] - y[i] + l);
	}
	x1 = max(x1, 0ll), y1 = max(y1, 0ll);
	if(x1 > x2 || y1 > y2 || b1 > b2) return false;
	if(x1 - y2 > b2 || x2 - y1 < b1) return false;
	X = min(x2, y2 + b2);
	Y = min(y2, X - b1);
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1, Len; i <= n; ++i) {
		scanf("%s", s + 1);
		Len = strlen(s + 1);
		for(int p = 1; p <= Len; ++p) {
			if(s[p] == 'B') x[i]++;
			else y[i]++;
		}
	}
	chk(1);
	L = 0, R = 1e6;
	while(L < R) {
		mid = (L + R) >> 1;
		if(chk(mid)) R = mid;
		else L = mid + 1;
	}
	cout << L << endl;
	for(int i = 1;i <= X; ++i) putchar('B');
	for(int i = 1;i <= Y; ++i) putchar('N');
	return 0;
}