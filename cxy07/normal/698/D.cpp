//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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
#define y1 _y1

const int MAXN = 1010;
const int MAXK = 8;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, Ans;
int ax[MAXK], ay[MAXK], mx[MAXN], my[MAXN];
int p[MAXK], pos;
bool killed[MAXN];
vec<int> on[MAXK][MAXN], idx;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool chk(int a, int b, int x) {
	if(mx[x] < min(ax[a], mx[b]) || mx[x] > max(ax[a], mx[b])) return false;
	if(my[x] < min(ay[a], my[b]) || my[x] > max(ay[a], my[b])) return false;
	int x1 = mx[x] - ax[a], y1 = my[x] - ay[a];
	int x2 = mx[b] - ax[a], y2 = my[b] - ay[a];
	if(1ll * x1 * y2 == 1ll * x2 * y1) return true;
	return false;
}

bool DFS(int who) {
	if(killed[who]) return true;
	if((++pos) > k) return false;
	for(auto id : on[p[pos]][who]) if(!DFS(id)) return false;
	idx.pb(who); killed[who] = true;
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(k), read(n);
	for(int i = 1; i <= k; ++i) read(ax[i]), read(ay[i]);
	for(int i = 1; i <= n; ++i) read(mx[i]), read(my[i]);
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= n; ++j)
			for(int p = 1; p <= n; ++p) {
				if(p != j && chk(i, j, p)) on[i][j].pb(p);
				if((int)on[i][j].size() >= k) break;
			}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) p[j] = j;
		do { 
			for(auto x : idx) killed[x] = false;
			pos = 0, idx.clear(); 
			if(DFS(i)) { Ans++; break; } 
		} while(next_permutation(p + 1, p + k + 1));
	} printf("%d\n", Ans);
	return 0;
}