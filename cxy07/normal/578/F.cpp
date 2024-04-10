//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, mod, Ans;
int id[MAXN][MAXN], idc, f[MAXN * MAXN];
int id2[MAXN * MAXN], idc2;
int G[MAXN][MAXN];
char s[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int find(int x) {return f[x] == x ? f[x] : f[x] = find(f[x]);}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	f[y] = x;
}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void Add(int x, int y) {
	//cerr << x << ' ' << y << endl;
	if(!x || !y || x == y) void();
	G[x][y]--, G[y][x]--, G[x][x]++, G[y][y]++;
}

int MatrixTree(int n) {
	/*for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			printf("%d%c", G[i][j], " \n"[j == n]);*/
	n--; bool opt = false; int res = 1;
	for(int i = 1, pos; i <= n; ++i) {
		pos = i;
		for(int j = i; j <= n; ++j) if(G[j][i] % mod) {pos = j; break;}
		if(i ^ pos) swap(G[i], G[pos]), opt ^= 1;
		int Inv = inv(G[i][i]);
		for(int j = i + 1, d; j <= n; ++j) {
			d = G[j][i] * Inv % mod;
			for(int k = i; k <= n; ++k)
				(G[j][k] += mod - G[i][k] * d % mod) %= mod;
		}
	}
	for(int i = 1; i <= n; ++i) res = (res * G[i][i]) % mod;
	if(opt) res = mod - res;
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(mod);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n + 1; ++i)
		for(int j = 1; j <= m + 1; ++j) id[i][j] = ++idc;
	for(int i = 1; i <= idc; ++i) f[i] = i;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == '*') continue;
			if(s[i][j] == '/') merge(id[i + 1][j], id[i][j + 1]);
			if(s[i][j] == '\\') merge(id[i][j], id[i + 1][j + 1]);
		}
	}
	for(int i = 1; i <= n + 1; ++i)
		for(int j = 1; j <= m + 1; ++j) {
			if((i + j) & 1) continue;
			if(find(id[i][j]) == id[i][j]) id2[id[i][j]] = ++idc2;
		}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '*') {
				Add(id2[find(id[i][j])], id2[find(id[i + 1][j + 1])]);
				Add(id2[find(id[i + 1][j])], id2[find(id[i][j + 1])]);
			}
	(Ans += MatrixTree(idc2)) %= mod;
	memset(G, 0, sizeof G); idc2 = 0;
	memset(id2, 0, sizeof id2);
	for(int i = 1; i <= n + 1; ++i)
		for(int j = 1; j <= m + 1; ++j)
			if(((i + j) & 1) && find(id[i][j]) == id[i][j]) 
				id2[id[i][j]] = ++idc2;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '*') {
				Add(id2[find(id[i][j])], id2[find(id[i + 1][j + 1])]);
				Add(id2[find(id[i + 1][j])], id2[find(id[i][j + 1])]);
			}
	(Ans += MatrixTree(idc2)) %= mod;
	printf("%lld\n", Ans);
	return 0;
}