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

const int MAXN = 110;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, B;
int c[MAXN * MAXN], buk[MAXN];
int AnsL[MAXN], AnsR[MAXN];
bool ok[MAXN];
vec<int> pos[MAXN], cur;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve(int L, int R) {
	cur.clear();
	for(int i = L; i <= R; ++i) 
		for(auto x : pos[i]) cur.pb(x);
	sort(cur.begin(), cur.end());
	for(int i = 0; i < (int)cur.size(); ++i) {
		if(ok[c[cur[i]]]) continue;
		if(buk[c[cur[i]]]) {
			ok[c[cur[i]]] = true;
			AnsL[c[cur[i]]] = buk[c[cur[i]]];
			AnsR[c[cur[i]]] = cur[i];
			memset(buk, 0, sizeof buk);
		} else buk[c[cur[i]]] = cur[i];
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= n * k; ++i) read(c[i]), pos[c[i]].pb(i);
	for(int i = 1; i <= n; i += k - 1)
		solve(i, min(i + k - 2, n));
	for(int i = 1; i <= n; ++i) printf("%d %d\n", AnsL[i], AnsR[i]);
	return 0;
}