//Code By CXY07
//CF788D
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

const int MAXN = 1e4 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
bool vis[MAXN];
vec<int> idx, X, Y;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int query(int x, int y) {
	static int d;
	printf("0 %d %d\n", x, y); fflush(stdout);
	scanf("%d", &d); return d;
}

void solve(int L, int R) {
	if(L > R) return;
	int mid = (L + R) / 2, d, pos = -INF;
	d = query(mid, mid);
	if(!d) return idx.pb(mid), solve(L, mid - 1), solve(mid + 1, R), void();
	if(mid - d >= L && !query(mid - d, mid - d)) idx.pb(mid - d), pos = mid - d;
	else if(mid + d <= R && !query(mid + d, mid + d)) idx.pb(mid + d), pos = mid + d;
	if(pos == -INF) return;
	solve(L, pos - 1), solve(pos + 1, R);
}

void calc() {
	int pos = 0;
	for(auto x : idx) if(0 <= x && x <= (int)1e4) vis[x] = true;
	while(vis[pos]) pos++;
	for(auto x : idx) {
		if(!query(x, pos)) X.pb(x);
		if(!query(pos, x)) Y.pb(x);
	}
	printf("1 %ld %ld\n", X.size(), Y.size());
	for(auto x : X) printf("%d ", x);
	putchar('\n');
	for(auto x : Y) printf("%d ", x);
	putchar('\n');
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	solve(-1e8, 1e8); calc();
	return 0;
}