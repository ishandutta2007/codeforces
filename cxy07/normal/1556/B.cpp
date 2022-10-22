//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define min(a, b) (a < b ? a : b)
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, c[2], Ans;
int a[MAXN];

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
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	cin >> T;
	while(T--) {
		cin >> n; c[0] = c[1] = 0; Ans = INF;
		int now = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i], a[i] &= 1;
			c[a[i]]++;
		}
		if(abs(c[0] - c[1]) > 1) { puts("-1"); continue; }
		if(c[1] > c[0]) {
			swap(c[0], c[1]);
			for(int i = 1; i <= n; ++i) a[i] ^= 1;
		}
		int p = 1;
		for(int i = 1; i <= n; i += 2) {
			while(p < n && a[p]) ++p;
			now += abs(i - p); p++;
		}
		p = 1;
		for(int i = 2; i <= n; i += 2) {
			while(p < n && !a[p]) ++p;
			now += abs(i - p); p++;
		}
		Ans = now;
		if(c[0] == c[1]) {
			int p = 1; now = 0;
			for(int i = 1; i <= n; i += 2) {
				while(p < n && !a[p]) ++p;
				now += abs(i - p); ++p;
			}
			p = 1;
			for(int i = 2; i <= n; i += 2) {
				while(p < n && a[p]) ++p;
				now += abs(i - p); ++p;
			}
			Ans = min(Ans, now);
		}
		cout << Ans / 2 << endl;
	}
	return 0;
}