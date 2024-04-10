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
#define y1 _y1

const int MAXN = 3010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Z;
int p[MAXN], x[2], v;
int Ans[MAXN];
map<pii, int> mmp;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int ask(int a, int b) {
	assert(a != b);
	if(a > b) swap(a, b);
	if(mmp.count(mp(a, b))) return mmp[mp(a, b)];
	int r; cout << "? " << a << ' ' << b << endl;
	cin >> r; return mmp[mp(a, b)] = r;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	srand(time(0));
	cin >> n;
	for(int i = 1; i <= n; ++i) p[i] = i;
	random_shuffle(p + 1, p + n + 1);
	x[0] = p[1], x[1] = p[2]; v = ask(x[0], x[1]);
	for(int i = 3, k; i <= n; ++i) {
		k = ask(x[0], p[i]);
		if(k > v) continue;
		if(k < v) x[1] = p[i];
		else x[0] = p[i]; 
		v = ask(x[0], x[1]);
	}
	while(1) {
		int t = randint(1, n), w1, w2;
		if(t == x[0] || t == x[1]) continue;
		w1 = ask(x[0], t), w2 = ask(x[1], t);
		if(w1 == w2) continue;
		Z = (w1 < w2) ? x[0] : x[1]; break;
	}
	Ans[Z] = 0;
	for(int i = 1; i <= n; ++i) if(i != Z) Ans[i] = ask(i, Z);
	cout << "! ";
	for(int i = 1; i <= n; ++i) cout << Ans[i] << ' ';
	cout << endl;
	return 0;
}