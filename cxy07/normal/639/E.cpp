//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define double long double
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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-10;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int p[MAXN], t[MAXN], T;
int L[MAXN], R[MAXN], sum[MAXN], id[MAXN];
pair<double, int> ord[MAXN];
pii s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool chk(double c) {
	double mx = 0;
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while(r + 1 <= n && s[l].fst == s[r + 1].fst) r++;
		for(int i = l, x; i <= r; ++i) {
			x = s[i].scd;
			double v = (1. - 1. * c * sum[R[x]] / T) * p[x];
			if(mx > v) return false;
		}
		for(int i = l, x; i <= r; ++i) {
			x = s[i].scd;
			mx = max(mx, (1. - 1. * c * (sum[L[x] - 1] + t[x]) / T) * p[x]);
		}
	}
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(p[i]);
	for(int i = 1; i <= n; ++i) {
		read(t[i]), T += t[i], s[i] = mp(p[i], i);
		ord[i] = mp(-1. * p[i] / t[i], i);
	}
	sort(ord + 1, ord + n + 1);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + t[ord[i].scd];
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while(r + 1 <= n && fabs(ord[l].fst - ord[r + 1].fst) < eps) r++;
		for(int i = l; i <= r; ++i) L[ord[i].scd] = l, R[ord[i].scd] = r;
	}
	sort(s + 1, s + n + 1);
	double l = 0, r = 1, mid;
	while(fabs(r - l) > eps) {
		mid = (l + r) / 2.;
		if(chk(mid)) l = mid;
		else r = mid;
	}
	printf("%.10Lf\n", l);
	return 0;
}