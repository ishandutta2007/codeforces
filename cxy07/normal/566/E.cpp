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

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, cnt;
bool nl[MAXN], used[MAXN], star = true;
bitset<MAXN> s[MAXN], tmp, leaf[MAXN], vis[MAXN];

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
	if(n == 2) return puts("1 2"), 0;
	for(int i = 1, c, x; i <= n; ++i) {
		read(c); star &= (c == n);
		while(c--) read(x), s[i][x] = 1;
	}
	if(star) {
		for(int i = 1; i < n; ++i) printf("%d %d\n", i, n);
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			tmp = s[i] & s[j];
			if(tmp.count() != 2) continue;
			int x = tmp._Find_first(), y = tmp._Find_next(x);
			if(vis[x][y]) continue;
			printf("%d %d\n", x, y);
			vis[x][y] = vis[y][x] = true, nl[x] = nl[y] = true;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(nl[i]) {vis[i][i] = true, cnt++; continue;}
		int siz = INF, pos;
		for(int j = 1; j <= n; ++j) {
			if(used[j] || !s[j][i]) continue;
			int c = s[j].count();
			if(c < siz) siz = c, pos = j;
		}
		used[pos] = true, leaf[i] = s[pos];
	}
	if(cnt == 2) {
		int a, b;
		for(int i = 1; i <= n; ++i) if(nl[i]) {a = i; break;}
		for(int i = a + 1; i <= n; ++i) if(nl[i]) {b = i; break;}
		for(int i = 1; i <= n; ++i) {
			if(s[i].count() == n) continue;
			for(int j = 1; j <= n; ++j) {
				if(nl[j]) continue;
				if(s[i][j]) printf("%d %d\n", a, j);
				else printf("%d %d\n", b, j);
			}
			break;
		}
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		if(nl[i]) continue;
		for(int j = 1; j <= n; ++j)
			if(!nl[j]) leaf[i][j] = 0;
		for(int j = 1; j <= n; ++j) {
			if(!nl[j] || leaf[i] != vis[j]) continue;
			printf("%d %d\n", i, j);
			break;
		}
	}
	return 0;
}