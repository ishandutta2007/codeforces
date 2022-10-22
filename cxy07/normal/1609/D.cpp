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

const int MAXN = 1e3 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, d, E;
int X[MAXN], Y[MAXN];
int dsu[MAXN], siz[MAXN];
multiset<int> S1, S2;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }

void unity(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	dsu[x] = y;
	S1.erase(S1.find(siz[x]));
	S1.erase(S1.find(siz[y]));
	siz[y] += siz[x];
	S1.insert(siz[y]);
}

void calc(int cnt) {
	int tot = 0;
	S2.clear();
	while(S1.size() && cnt) {
		int x = *(--S1.end());
		tot += x;
		S2.insert(x);
		S1.erase(S1.find(x));
		--cnt;
	}
	while(S2.size()) {
		S1.insert(*S2.begin());
		S2.erase(S2.begin());
	}
	printf("%d\n", tot - 1);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(d);
	for(int i = 1; i <= d; ++i) read(X[i]), read(Y[i]);
	for(int i = 1; i <= n; ++i) 
		dsu[i] = i, siz[i] = 1, S1.insert(1);
	for(int i = 1, x, y; i <= d; ++i) {
		x = find(X[i]), y = find(Y[i]);
		if(x != y) { unity(x, y); E++; }
		calc(i - E + 1);
	}
	return 0;
}