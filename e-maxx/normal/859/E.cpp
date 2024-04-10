#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 210000;
const int MOD = 1000000007;


int n, from[MAXN], to[MAXN];


bool read() {
	if (!(cin >> n))
		return false;
	forn(i, n) {
		scanf("%d%d", &from[i], &to[i]);
		--from[i];
		--to[i];
	}
	return true;
}


int target[MAXN], d[MAXN][2];
vector<int> g[MAXN];
bool u[MAXN];

int mul(int64 a, int64 b) {
	return int((a * b) % MOD);
}

int get_d(int v, int tp) {
	int& my = d[v][tp];
	if (my != -1)
		return my;
	my = 0;

	int deg = (int)g[v].size();

	vector<int> ds(deg);
	forn(i, deg) {
		int nv = g[v][i];
		ds[i] = get_d(nv, 0);
	}

	vector<int> pref(deg+1, 1);
	forn(i, deg)
		pref[i+1] = mul(pref[i], ds[i]);
	vector<int> suf(deg+1, 1);
	forn(i, deg)
		suf[i+1] = mul(suf[i], ds[deg-i-1]);

	my = pref[deg];

	if (tp == 1) {
		forn(i, deg) {
			int nv = g[v][i];
			int val2 = mul(mul(pref[i], get_d(nv, 1)), suf[deg-1-i]);
			my = (my + val2) % MOD;
		}
	}

	return my;
}

void solve() {
	forn(i, n*2)
		g[i].clear();
	memset(target, -1, sizeof target);
	forn(i, n) {
		target[from[i]] = to[i];
		g[to[i]].pb(from[i]);
	}

	memset(u, 0, sizeof u);
	int cycles = 0;
	forn(i, n*2)
		if (!u[i]) {
			int v = i;
			set<int> visited;
			while (!u[v]) {
				u[v] = true;
				visited.insert(v);
				v = target[v];
				if (v == -1)
					break;
				if (visited.count(v)) {
					if (target[v] != v)
						++cycles;
					break;
				}
			}
		}

	int ans = 1;
	memset(d, -1, sizeof d);
	forn(i, n*2)
		if (target[i] == -1 && g[i].size())
			ans = mul(ans, get_d(i, 1));
	forn(i, cycles)
		ans = mul(ans, 2);

	cout << ans << endl;
}


int main() {
#ifdef EMAXX_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tt = 0;
	while (read()) {
		cerr << "Case " << ++tt << ": starting..." << endl;
		solve();
	}
    cerr << "Finished.";

	return 0;
}