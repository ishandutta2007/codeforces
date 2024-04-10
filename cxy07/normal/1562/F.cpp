//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, V = 2e5, qcnt;
int pr[MAXN], pcnt, tmpv[MAXN];
int Ans[MAXN];
bool np[MAXN];

void sieve(int siz) {
	for(int i = 2; i <= siz; ++i) {
		if(!np[i]) pr[++pcnt] = i;
		for(int j = 1; j <= pcnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

int ask(int x, int y) {
	static int res; ++qcnt;
	cout << "? " << x << ' ' << y << endl;
	cout.flush();
	cin >> res; cout.flush(); return res;
}

void print() {
	cout << "! ";
	for(int i = 1; i <= n; ++i) cout << Ans[i] << ' ';
	cout << endl; cout.flush();
}

namespace sub1 {
	int lcm[110][110], x = 0, y = 0, r, cur;
	bool ban[110];
	void solve() {
		x = y = 0;
		for(int i = 1; i <= n; ++i) {
			ban[i] = false;
			for(int j = i + 1; j <= n; ++j) {
				lcm[i][j] = lcm[j][i] = ask(i, j);
				if(!x || lcm[i][j] > lcm[x][y]) x = i, y = j;
			}
		}
		for(int i = 2; i <= V; ++i)
			if(lcm[x][y] == (i - 1) * i) { r = i; break; }
		bool flag = true;
		for(int i = 1, tmp; i <= n; ++i) {
			if(x == i || y == i) continue;
			tmp = lcm[x][i];
			if(tmp % r) { Ans[y] = r, Ans[x] = r - 1, flag = false; break; }
		}
		if(flag) Ans[x] = r, Ans[y] = r - 1;
		if(Ans[x] == r) ban[x] = true, cur = y;
		else ban[y] = true, cur = x;
		for(int t = 1, pos; t <= n - 2; ++t) {
			pos = 0;
			for(int i = 1; i <= n; ++i) {
				if(ban[i] || i == cur) continue;
				if(!pos || lcm[pos][cur] < lcm[i][cur]) pos = i;
			}
			Ans[pos] = Ans[cur] - 1; ban[cur] = true; cur = pos;
		}
	}
}

namespace sub2 {
	int lcm[MAXN], at, maxpr, p[MAXN];
	int max_prime(int x) {
		int res = 0;
		for(int i = 1; i <= pcnt && pr[i] * pr[i] <= x; ++i) {
			if(x % pr[i]) continue;
			while(x % pr[i] == 0) x /= pr[i];
			res = max(res, pr[i]);
		}
		if(x ^ 1) res = max(res, x);
		return res;
	}
	void solve() {
		for(int i = 1; i <= n; ++i) p[i] = i;
		random_shuffle(p + 1, p + n + 1);
		maxpr = at = 0; p[n + 1] = p[1];
		for(int i = 1, nowpr; i <= n; i += 2) {
			lcm[i] = ask(p[i], p[i + 1]);
			nowpr = max_prime(lcm[i]);
			if(maxpr < nowpr) maxpr = nowpr, at = i;
		}
		for(int i = 1, l; i <= n; ++i) {
			if(p[i] == p[at] || p[i] == p[at + 1]) continue;
			l = ask(p[i], p[at]);
			if(l % maxpr) Ans[p[++at]] = maxpr;
			else Ans[p[at]] = maxpr;
			break;
		}
		for(int i = 1; i <= n; ++i)
			if(p[i] != p[at]) Ans[p[i]] = ask(p[i], p[at]) / maxpr;
	}
}

namespace sub3 {
	int x, y;
	pii factor(int x) {
		static vec<int> fact;
		int cnt = 0; fact.clear();
		for(int i = 1; i <= pcnt && pr[i] * pr[i] <= x; ++i) {
			if(x % pr[i]) continue;
			while(x % pr[i] == 0) {
				++cnt, x /= pr[i];
				fact.pb(pr[i]);
				if(cnt > 2) return mp(-1, -1);
			}
		}
		if(x ^ 1) fact.pb(x), ++cnt;
		if(cnt != 2) return mp(-1, -1);
		return mp(fact[0], fact[1]);
	}
	pii find_pair() {
		for(int i = 1, l; i <= 3000; ++i) {
			x = randint(1, n - 1); y = randint(x + 1, n);
			l = ask(x, y); pii res = factor(l);
			if(res.fst == -1) continue;
			if(res.fst >= 500 && res.scd >= 500) return res;
		}
		return mp(-1, -1);
	}
	void solve() {
		pii res = find_pair(); bool flag = true;
		for(int i = 1, now, l; i <= 100; ++i) {
			do now = randint(1, n);
			while(now == x || now == y);
			l = ask(x, now);
			if(l % res.fst) { flag = false; break; }
		}
		Ans[x] = res.fst, Ans[y] = res.scd;
		if(!flag) swap(Ans[x], Ans[y]);
		for(int i = 1, l; i <= n; ++i) {
			if(i == x || i == y) continue;
			l = ask(i, x); Ans[i] = l / Ans[x];
			if(Ans[i] <= 500) Ans[i] = ask(i, y) / Ans[y];
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	srand(time(0)); sieve(2e5); cin >> T;
	while(T--) {
		cin >> n; qcnt = 0;
		if(n <= 100) sub1::solve();
		else if(n <= 10000) sub2::solve();
		else sub3::solve();
		print();
	}
	return 0;
}