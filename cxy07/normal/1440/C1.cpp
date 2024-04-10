//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 110;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	pii a, b, c;
	NODE(pii _a = mp(0, 0), pii _b = mp(0, 0), pii _c = mp(0, 0)) {
		a = _a, b = _b, c = _c;
	}
};

int T, n, m;
int a[MAXN][MAXN];
char ss[MAXN];
vec<NODE> ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Do(NODE x) {
	a[x.a.fst][x.a.scd] ^= 1;
	a[x.b.fst][x.b.scd] ^= 1;
	a[x.c.fst][x.c.scd] ^= 1;
}

void print(int x, int y) {
		for(int i = 1; i <= n + x; ++i) {
			for(int j = 1; j <= m + y; ++j)
				cout << a[i][j];
			cout << endl;
		}
		cout << endl;
}

void solve(int x, int y) {
	int cnt = 0, cc = 0, lim = ans.size();
	pii p[5], l[5];
	for(int i = x; i <= x + 1; ++i)
		for(int j = y; j <= y + 1; ++j) {
			if(a[i][j])	p[++cnt] = mp(i, j);
			else l[++cc] = mp(i, j);
		}
	if(!cnt) return;
	if(cnt == 3) {
		ans.pb(NODE(p[1], p[2], p[3]));
	} else if(cnt == 4) {
		for(int i = 1; i <= 4; ++i) {
			int aa = i, bb = (i) % 4 + 1, cc = (i + 1) % 4 + 1;
			ans.pb(NODE(p[aa], p[bb], p[cc]));
		}
	} else if(cnt == 2) {
		ans.pb(NODE(p[1], l[1], l[2]));
		ans.pb(NODE(p[2], l[1], l[2]));
	} else if(cnt == 1) {
		cc = 0;
		for(int i = x; i <= x + 1; ++i)
			for(int j = y; j <= y + 1; ++j)
				p[++cc] = mp(i, j);
		for(int i = 1; i <= 4; ++i) {
			int aa = i, bb = (i) % 4 + 1, cc = (i + 1) % 4 + 1;
			int xa = p[aa].fst, ya = p[aa].scd;
			int xb = p[bb].fst, yb = p[bb].scd;
			int xc = p[cc].fst, yc = p[cc].scd;
			if(a[xa][ya] || a[xb][yb] || a[xc][yc]) {
				ans.pb(NODE(p[aa], p[bb], p[cc]));
			}	
		}
	}
	for(int i = lim; i < ans.size(); ++i) Do(ans[i]);
}

void clearn(int x) {
	int lim = ans.size();
	for(int i = 1; i <= m; ++i) {
		pii up = mp(x - 1, i), uup;
		if(i < m) uup = mp(x - 1, i + 1);
		else uup = mp(x - 1, i - 1);
		if(a[x][i]) ans.pb(NODE(mp(x, i), up, uup));
	}
	for(int i = lim; i < ans.size(); ++i) Do(ans[i]);
}

void clearm(int x) {
	int lim = ans.size();
	for(int i = 1; i <= n; ++i) {
		pii up = mp(i, x - 1), uup;
		//cout << '!' << i << ' ' << x << endl;
		if(i < n) uup = mp(i + 1, x - 1);
		else uup = mp(i - 1, x - 1);
		if(a[i][x]) ans.pb(NODE(mp(i, x), up, uup));
	}
	for(int i = lim; i < ans.size(); ++i) Do(ans[i]);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	cin >> T;
	while(T--) {
		ans.clear();
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			cin >> ss + 1;
			for(int j = 1; j <= m; ++j)
				a[i][j] = ss[j] - '0';
		}
		int addn = 0, addm = 0;
		if(n & 1) clearn(n--), addn = 1;
		if(m & 1) clearm(m--), addm = 1;
		for(int i = 1; i <= n; i += 2) {
			for(int j = 1; j <= m; j += 2) {
				solve(i, j);
			}
		}
		cout << ans.size() << endl;
		//assert(ans.size() <= n * m);
		for(auto x : ans) {
			cout << x.a.fst << ' ' << x.a.scd << ' ' << x.b.fst << ' ' << x.b.scd << ' ' << x.c.fst << ' ' << x.c.scd << endl;
		}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				assert(!a[i][j]);
		//print(addn, addm);
	}
	return 0;
}