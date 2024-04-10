//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector
#define ui unsigned int

const int MAXN = 6e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, L, R, mid;
ui st[MAXN][21], lg[MAXN];
ui Min[MAXN][21];
vec<int> ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

ui Gcd(ui x, ui y) {
	if(!y) return x;
	return Gcd(y, x % y);
}

void build() {
	for(int p = 1; p <= 20; ++p)
		for(int i = 1; i + (1 << p) - 1 <= n; ++i) {
			st[i][p] = Gcd(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
			Min[i][p] = min(Min[i][p - 1], Min[i + (1 << (p - 1))][p - 1]);
		}
	lg[0] = -1;
	for(int i = 1; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
}

ui GCD(int l, int r) {
	if(l > r) swap(l, r);
	int len = lg[r - l + 1];
	return Gcd(st[l][len], st[r - (1 << len) + 1][len]);
}

ui MIN(int l, int r) {
	if(l > r) swap(l, r);
	int len = lg[r - l + 1];
	return min(Min[l][len], Min[r - (1 << len) + 1][len]);
}

bool chk(int len, int opt) {
	int cnt = 0;
	if(opt) ans.clear();
	for(int i = 1; i <= n - len + 1; ++i) 
		if(GCD(i, i + len - 1) == MIN(i, i + len - 1)) {
			cnt++;
			if(opt) ans.pb(i);
		}
	return (bool) cnt;
}

signed main () {
#ifdef FILE
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(st[i][0]);
		Min[i][0] = st[i][0];
	}
	L = 1, R = n;
	build();
	while(L < R) {
		mid = (L + R + 1) >> 1;
		if(chk(mid, 0)) L = mid;
		else R = mid - 1;
	}
	chk(L, 1);
	printf("%d %d\n", ans.size(), L - 1);
	for(int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}