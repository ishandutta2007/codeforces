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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, S, Ans, siz;
int sum[MAXN], X[MAXN], Y[MAXN];
int add[460][460], pos[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Addsmall(int x, int t) {
	int p = X[x] + Y[x];
	for(int i = t; i <= t + X[x] - 1; ++i) add[p][i % p]++;
}

void Delsmall(int x, int t) {
	int p = X[x] + Y[x];
	for(int i = t; i <= t + X[x] - 1; ++i) add[p][i % p]--;
}

void Addbig(int x, int t) {
	int p = X[x] + Y[x];
	for(int i = t; i <= m; i += p) {
		sum[i]++;
		if(i + X[x] <= m) sum[i + X[x]]--;
	}
}

void Delbig(int x, int t, int cur) {
	int p = X[x] + Y[x];
	for(int i = t; i <= m; i += p) {
		sum[i]--;
		if(i + X[x] <= m) sum[i + X[x]]++;
		if(i < cur && cur <= i + X[x]) Ans--;
	}
}

int calc(int t) {
	Ans += sum[t];
	int now = Ans;
	for(int i = 1; i <= S; ++i) now += add[i][t % i];
	return now;
}

void solve(int t) {
	int opt, id; read(opt), read(id);
	if(opt == 1) {
		assert(!pos[id]);
		if(X[id] + Y[id] > S) Addbig(id, t);
		else Addsmall(id, t);
		pos[id] = t; ++siz;
	} else {
		assert(pos[id]);
		if(X[id] + Y[id] > S) Delbig(id, pos[id], t);
		else Delsmall(id, pos[id]);
		pos[id] = 0; --siz;
	} printf("%d\n", siz - calc(t));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); S = 450;
	for(int i = 1; i <= n; ++i) read(X[i]), read(Y[i]);
	for(int i = 1; i <= m; ++i) solve(i);
	return 0;
}