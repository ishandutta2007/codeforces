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

const int MAXN = 6e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, now;
int bit[MAXN];
priority_queue<int> Q[55];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Add(int x, int v) {
	for(; x < MAXN; x += lowbit(x))
		bit[x] += v;
}

int Ask(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res += bit[x];
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); read(m); now = n;
	for(int i = 1, x; i <= n; ++i) {
		read(x); Add(i, 1);
		Q[x].push(n - i + 1);
	}
	while(m--) {
		int x; read(x);
		printf("%d ", n - Ask(Q[x].top()) + 1);
		Add(Q[x].top(), -1);
		Q[x].pop(); Q[x].push(++now);
		Add(now, 1);
	}
	return 0;
}