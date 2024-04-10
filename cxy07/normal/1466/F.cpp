//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int fa[MAXN];
int X, Y;
bool vis[MAXN];
vec<int> id;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void Jump(int &x) {
	x = find(x);
}

bool Insert() {
	int x = X, y = Y;
	if(x > y) swap(x, y);
	while(x != y) {
		if(x > y) swap(x, y);
		if(!vis[x]) break;
		Jump(x);
	}
	if(x == y) return false;
	if(x > y) swap(x, y);
	vis[x] = true;
	fa[x] = y;
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= m + 1; ++i) fa[i] = i;
	for(int i = 1, k; i <= n; ++i) {
		read(k);
		read(X); Y = m + 1;
		if(k == 2) read(Y);
		if(Insert()) id.pb(i);
	}
	int tot = qpow(2, id.size());
	printf("%lld %ld\n", tot, id.size());
	for(auto x : id) printf("%lld ", x);
	printf("\n");
	return 0;
}