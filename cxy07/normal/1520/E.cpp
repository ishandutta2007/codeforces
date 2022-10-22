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

const int MAXN = 1e6 + 10;
const int INF = 2e16;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int sum[MAXN], tot[MAXN];
char s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int S(int l, int r) {
	return sum[r] - sum[l - 1];
}

int TOT(int l, int r) {
	return tot[r] - tot[l - 1];
}

int calc(int a, int b) {
	if(a > b) return 0;
	return (a + b) * (b - a + 1) >> 1;
}

void solve() {
	cin >> n >> s + 1;
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1], tot[i] = tot[i - 1];
		if(s[i] == '*') sum[i] += i, tot[i]++;
	}
	int Ans = INF;
	for(int i = 1; i <= n; ++i) {
		int now = calc(i - TOT(1, i) + 1, i) - S(1, i) + S(i + 1, n) - calc(i + 1, i + TOT(i + 1, n));
		Ans = min(Ans, now);
	}
	cout << Ans << endl;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	cin >> T;
	while(T--) solve();
	return 0;
}