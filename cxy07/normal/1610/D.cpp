//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int a[MAXN], c[MAXN], p2[MAXN];
int buk[31];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); p2[0] = 1;
	for(int i = 1; i < MAXN; ++i) p2[i] = p2[i - 1] * 2 % mod;
	for(int i = 1, x; i <= n; ++i) {
		read(a[i]), x = a[i];
		while(x % 2 == 0) x >>= 1, ++c[i];
		buk[c[i]]++;
	}
	for(int i = 0, t; i <= 30; ++i) {
		if(!buk[i]) continue;
		t = 0;
		for(int j = i + 1; j <= 30; ++j) t += buk[j];
		t = p2[t] * (p2[buk[i] - (i != 0)] - 1) % mod;
		(Ans += t) %= mod;
	}
	cout << Ans << endl;
	return 0;
}