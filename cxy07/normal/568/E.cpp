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

int n, m, Ans;
int a[MAXN], b[MAXN];
int val[MAXN];
bool ban[MAXN];
vec<int> at[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	read(m);
	for(int i = 1; i <= m; ++i) read(b[i]);
	sort(b + 1, b + m + 1);
	memset(val, 0x3f, sizeof val);
	val[0] = 0;
	for(int i = 1, p; i <= n; ++i) {
		if(a[i] == -1) {
			p = n;
			for(int j = m; j; --j) {
				while(p >= 1 && val[p] >= b[j]) p--;
				assert(val[p] < b[j]);
				assert(val[p + 1] >= b[j]);
				val[p + 1] = b[j];
				Ans = max(Ans, p + 1);
			}
			continue;
		}
		p = lower_bound(val + 1, val + n + 1, a[i]) - val - 1;
		assert(0 <= p && p < n);
		assert(val[p + 1] >= a[i]);
		val[p + 1] = a[i];
		at[p + 1].pb(i);
		Ans = max(Ans, p + 1);
	}
	int x, p = m;
	if(at[Ans].size()) x = at[Ans][0];
	else {
		for(int i = n; i >= 1; --i)
			if(a[i] == -1) {x = i; break;}
		a[x] = b[p];
		ban[p--] = true;
	}
	for(int i = Ans - 1; i; --i) {
		bool flag = false;
		for(auto pos : at[i])
			if(pos < x && a[pos] < a[x]) {flag = true, x = pos; break;}
		int v = a[x];
		if(!flag) {
			while(a[x] != -1) x--;
			while(b[p] >= v) p--;
			a[x] = b[p]; ban[p--] = true;
		}
	}
	p = 1;
	for(int i = 1; i <= n; ++i) {
		if(a[i] != -1) continue;
		while(ban[p]) ++p;
		a[i] = b[p++];
	}
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	return 0;
}