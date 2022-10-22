//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 1e4 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k;
int x[MAXN], a[MAXN], o[MAXN];
int s[MAXN], _s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int OR(int i, int j) {
	int res = 0;
	cout << "or " << i << ' ' << j << endl;
	cout.flush(); cin >> res; return res;
}

int AND(int i, int j) {
	int res = 0;
	cout << "and " << i << ' ' << j << endl;
	cout.flush(); cin >> res; return res;
}

void solve() {
	int _a[4][4], _o[4][4];
	int na[4][4], no[4][4];
	for(int i = 1; i <= 3; ++i)
		for(int j = i + 1; j <= 3; ++j) {
			_a[i][j] = _a[j][i] = AND(i, j);
			_o[i][j] = _o[j][i] = OR(i, j);
		}
	for(int p = 0; p <= 30; ++p) {
		_s[1] = _s[2] = _s[3] = -1;
		for(int i = 1; i <= 3; ++i)
			for(int j = 1; j <= 3; ++j) {
				if(i == j) continue;
				na[i][j] = (_a[i][j] >> p) & 1;
				no[i][j] = (_o[i][j] >> p) & 1;
				if(na[i][j]) _s[i] = _s[j] = 1;
			}
		int ca = 0;
		for(int i = 1; i <= 3; ++i)
			for(int j = i + 1; j <= 3; ++j)
				if(!na[i][j]) {
					if(_s[i] == 1) _s[j] = 0;
					if(_s[j] == 1) _s[i] = 0;
				} else ++ca;
		if(!ca) {
			for(int i = 1; i <= 3; ++i) {
				int c = 0;
				for(int j = 1; j <= 3; ++j)
					if(i != j) c += no[i][j];
				if(c == 2) _s[i] = 1;
				else _s[i] = 0;
			}
		}
		for(int i = 1; i <= 3; ++i) {
			assert(_s[i] != -1);
			s[i] |= (_s[i] << p);
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	cin >> n >> k;
	solve();
	for(int i = 4; i <= n; ++i) { 
		a[i] = AND(1, i);
		o[i] = OR(1, i);
		x[i] = o[i] ^ a[i];
	}
	for(int i = 4; i <= n; ++i)
		s[i] = s[1] ^ x[i];
	sort(s + 1, s + n + 1);
	cout << "finish " << s[k] << endl;
	return 0;
}