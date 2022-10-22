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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	double val; int id;
	NODE(double _val = 0, int _id = 0) : val(_val), id(_id) {}
	bool operator < (const NODE &b) const {return val > b.val;}
};

int n, m, k;
int a[MAXN], Max1[MAXN], maxp[MAXN];
int opt[MAXN], pos[MAXN], b[MAXN];
vec<NODE> p[MAXN], Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool cmp(NODE a, NODE b) {
	return opt[a.id] < opt[b.id];
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(k), read(n), read(m);
	for(int i = 1; i <= k; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) {
		read(opt[i]), read(pos[i]), read(b[i]);
		if(opt[i] == 1) {
			if(b[i] > Max1[pos[i]]) {
				Max1[pos[i]] = b[i];
				maxp[pos[i]] = i;
			}
		}
		if(opt[i] == 2) p[pos[i]].pb(NODE(b[i], i));
	}
	for(int i = 1, now; i <= k; ++i) {
		now = a[i];
		if(Max1[i] - a[i] > 0)
			p[i].pb(NODE(Max1[i] - a[i], maxp[i]));
		sort(p[i].begin(), p[i].end());
		for(auto v : p[i]) {
			Ans.pb(NODE(1. * (now + v.val) / now, v.id));
			now += v.val;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(opt[i] == 3) Ans.pb(NODE(b[i], i));
	sort(Ans.begin(), Ans.end());
	if(Ans.size() > m) Ans.resize(m);
	sort(Ans.begin(), Ans.end(), cmp);
	printf("%ld\n", Ans.size());
	for(auto x : Ans) printf("%lld ", x.id);
	return 0;
}