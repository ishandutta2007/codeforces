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
#define vec vector

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	int a, b;
} s[MAXN];

int T, n, m, ans;
int sum[MAXN], v[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool cmpa (NODE x, NODE y) {return x.a > y.a;}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n, m);
		ans = 0;
		for(int i = 1; i <= m; ++i) {
			read(s[i].a, s[i].b);
			sum[i] = 0;
		}
		sort(s + 1, s + m + 1, cmpa);
		for(int i = 1; i <= m; ++i) {
			sum[i] = sum[i - 1] + s[i].a;
			v[i] = s[i].a;
		}
		v[0] = INF; v[m + 1] = -INF;
		for(int i = 1, L, R, mid; i <= m; ++i) {
			L = 0, R = m;
			while(L < R) {
				mid = (L + R + 1) >> 1;
				if(v[mid] >= s[i].b) L = mid;
				else R = mid - 1;
			}
			if(L >= n) ans = max(ans, sum[n]);
			else {
				if(n - L - (s[i].a < s[i].b) >= 0)
					ans = max(ans, sum[L] + (n - L - (s[i].a < s[i].b)) * s[i].b + s[i].a * (s[i].a < s[i].b));
			}
		}
		cout << ans << endl;
	}
	return 0;
}