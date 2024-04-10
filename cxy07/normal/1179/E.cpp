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
#define y1 _y1

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, LEN, cnt;
int p[MAXN], p2[MAXN], p3[MAXN];
pii Ans[MAXN];
random_device rnd;
map<pii, int> mmp;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int ask(int id, int p) {
	if(mmp.count(mp(id, p))) return mmp[mp(id, p)];
	cout << "? " << id << ' ' << p << endl;
	int r; cin >> r; return mmp[mp(id, p)] = r;
}

int find(int id, int l, int r, int g) {
	int mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(ask(id, mid) < g) l = mid + 1;
		else r = mid;
	}
	return l;
}

int nth(int l, int r, int k, int vL, int vR, int g) {
	if(l == r) return find(p[l], vL, vR, g);
	int i1 = l - 1, i2 = r + 1, pos = randint(l, r);
	int t, num, i3 = 0, now = p[pos];
	t = find(now, vL, vR, g);
	for(int i = l, cur; i <= r; ++i) {
		if(i == pos) continue;
		cur = ask(p[i], t);
		if(cur > g) p2[++i1] = p[i];
		else if(cur < g) p2[--i2] = p[i];
		else p3[++i3] = p[i];
	}
	p3[++i3] = now;
	for(int i = 1; i <= i3; ++i) p2[i1 + i] = p3[i];
	for(int i = l; i <= r; ++i) p[i] = p2[i];
	num = i1 - l + 1;
	if(num < k && k <= num + i3) return t;
	else if(num + i3 < k) return nth(i2, r, k - num - i3, t, vR, g);
	else return nth(l, i1, k, vL, t, g);
}

void solve(int a, int b, int L, int R) {
	if(a > b) return;
	if(a == b) return Ans[p[a]] = mp(L, R), void();
	int mid = (a + b) >> 1, M; 
	M = nth(a, b, mid - a + 1, L, R, mid * LEN);
	solve(a, mid, L, M), solve(mid + 1, b, M, R);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	srand(rnd()); read(n), read(LEN); LEN /= n;
	for(int i = 1; i <= n; ++i) p[i] = i;
	solve(1, n, 0, 1e18);
	cout << "!" << endl;
	for(int i = 1; i <= n; ++i)
		cout << Ans[i].fst << ' ' << Ans[i].scd << endl;
	return 0;
}