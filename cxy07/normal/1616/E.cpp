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
const int INF = 2e15;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int FT[MAXN];
vec<int> pos[26];
string s, t, best;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add(int x, int v) {
	++x;
	for(; x <= n; x += lowbit(x)) FT[x] += v;
}

int ask(int x) {
	int res = 0; ++x; 
	for(; x; x -= lowbit(x)) res += FT[x];
	return res;
}

void solve() {
	cin >> n;
	cin >> s >> t; best = s, Ans = INF;
	sort(best.begin(), best.end());
	if(best >= t) return cout << -1 << endl, void();
	for(int i = 0; i < 26; ++i) pos[i].clear();
	for(int i = n - 1; i >= 0; --i) pos[s[i] - 'a'].pb(i);
	memset(FT, 0, sizeof(int) * (n + 5));
	for(int i = 0, v, cur = 0, num; i < n; ++i) {
		v = t[i] - 'a';
		for(int c = 0; c < v; ++c) {
			if(!pos[c].size()) continue;
			num = pos[c].back() - ask(pos[c].back());
			assert(num >= 0);
			Ans = min(Ans, cur + num);
		}
		if(!pos[v].size()) break;
		num = pos[v].back() - ask(pos[v].back());
		assert(num >= 0);
		cur += num;
		add(pos[v].back() + 1, 1);
		pos[v].pop_back();
	}
	cout << Ans << endl;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) solve();
	return 0;
}