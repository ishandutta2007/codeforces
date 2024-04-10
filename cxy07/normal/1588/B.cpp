//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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
#define y1 _y1

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, tot;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int ask(int l, int r) {
	int res;
	cout << "? " << l << ' ' << r << endl;
	cout.flush();
	cin >> res;
	return res;
}

void solve() {
	cin >> n;
	int l = 1, r = n, mid, dt, len;
	tot = ask(1, n);
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(ask(mid, n) != tot) r = mid - 1;
		else l = mid;
	}
	dt = ask(l + 1, n);
	assert(dt < tot); dt = tot - dt + 1;
	len = (int)sqrt((tot - dt * (dt - 1) / 2) * 2) + 1;
	assert(tot * 2 == dt * (dt - 1) + len * (len - 1));
	cout << "! " << l << ' ' << l + dt << ' ' << l + dt + len - 1 << endl;
	cout.flush();
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--) solve();
	return 0;
}