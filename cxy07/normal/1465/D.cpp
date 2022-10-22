//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 1e5 + 10;
const int INF = 2e16;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, x, y, cnt;
int ans = INF;
int pre0[MAXN], pre1[MAXN], c01, c10;
char s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%s", s + 1);
	read(x), read(y); n = strlen(s + 1);
	if(x > y) {
		for(int i = 1; i <= n; ++i) {
			if(s[i] != '?')
				s[i] = (s[i] == '0' ? '1' : '0');
		}
		swap(x, y);
	}
	for(int i = 1; i <= n; ++i) {
		pre0[i] = pre0[i - 1] + (s[i] == '0');
		pre1[i] = pre1[i - 1] + (s[i] == '1');
	}
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '0') {
			c01 += ((n - i) - (pre0[n] - pre0[i]));
			c10 += ((i - 1) - pre0[i - 1]);
		}
	}
	ans = min(ans, c01 * x + c10 * y);
	for(int i = 1; i <= n; ++i) {
		if(s[i] != '?') continue;
		c01 -= ((i - 1) - pre1[i - 1]); c10 += pre1[i];
		c10 -= (pre0[n] - pre0[i]); c01 += ((n - i) - (pre0[n] - pre0[i]));
		assert(c01 >= 0 && c10 >= 0);
		ans = min(ans, c01 * x + c10 * y);
	}
	cout << ans << endl;
	return 0;
}