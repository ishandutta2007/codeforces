//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, S, len;
int sav, k = 8;
vec<pii> qs;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void print() {
	cout << "? " << qs.size() << endl;
	for(auto x : qs) cout << x.fst << ' ' << x.scd << ' ';
	cout << endl;
	cout.flush();
}

bool chk(int p) {
	qs.clear();
	int len = (1 << p), t;
	for(int i = len; i <= 200; i += len)
		for(int j = 1; j <= 200; ++j) qs.pb(mp(i, j));
	print();
	cin >> t;
	if(t * len == S) return true;
	sav = t, k = p;
	return false;
}

signed main () {
#ifdef FILE
	freopen("h.in", "r", stdin);
	freopen("h.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cout << "? " << 40000 << endl;
	for(int i = 1; i <= 200; ++i)
		for(int j = 1; j <= 200; ++j) cout << i << ' ' << j << ' ';
	cout << endl;
	cout.flush();
	cin >> S;
	int L = 1, R = 7, mid;
	while(L <= R) {
		mid = (L + R) >> 1;
		if(!chk(mid)) R = mid - 1;
		else L = mid + 1;
	}
	len = abs(S / (1 << (k - 1)) - (sav << 1));
	cout << "! " << ((len - 1 + (S / len - 1)) << 1) << endl;
	cout.flush();
	return 0;
}