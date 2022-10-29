#pragma comment(linker, "/STACK:200000000")
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
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
//#define double long double
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i, n)  for (int i = 0; i < int(n); ++i)
#define ford(i, n)  for (int i=int(n) - 1; i >= 0; --i)
#define fore(i, l, r)  for (int i = int(l); i < int(r); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 110;


int n, m, a[MAXN], b[MAXN], tp[MAXN];

bool read() {
	if (!(cin >> n >> m))
		return false;
	forn(i, m) {
		char buf[10];
		cin >> a[i] >> b[i] >> buf;
		--a[i], --b[i];
		tp[i] = string(buf) == "RIGHT";
	}
	return true;
}


vector<int> g[MAXN];
vector<vector<int>> comps;
bool forbidden[MAXN];
int compid[MAXN];
int ans_g[MAXN][2];
int check_exp, check_tl[MAXN], check_tr[MAXN], check_t;

void dfs_comp(int v) {
	compid[v] = (int)comps.size() - 1;
	comps.back().push_back(v);
	if (forbidden[v])
		return;
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (compid[to] == -1)
			dfs_comp(to);
	}
}

bool rec(vector<int> vs) {
	if (vs.size() == 1)
		return true;

	sort(all(vs));

	int root = vs[0];
	vs.erase(vs.begin());
	forbidden[root] = true;

	set<int> child[2];

	forn(i, m)
		if (a[i] == root) {
			if (!binary_search(all(vs), b[i]))
				return false;
			child[tp[i]].insert(b[i]);
		}

	memset(compid, -1, sizeof compid);
	comps.clear();
	forn(i, n)
		if (compid[i] == -1) {
			comps.push_back(vector<int>());
			dfs_comp(i);
		}

	bool changed;
	do {
		changed = false;

		forn(tp, 2) {
			for (set<int>::iterator it = child[tp].begin(); it != child[tp].end(); ++it) {
				int c = compid[*it];
				forn(i, comps[c].size()) {
					int cand = comps[c][i];
					if (!binary_search(all(vs), cand) || child[1 - tp].count(cand))
						return false;
					if (!child[tp].count(cand)) {
						child[tp].insert(cand);
						changed = true;
					}
				}
			}

			if (child[tp].size()) {
				int mi = *child[tp].begin();
				int ma = *child[tp].rbegin();
				forn(i, vs.size()) {
					int cand = vs[i];
					if (mi <= cand && cand <= ma || (tp == 0 && cand <= ma) || (tp == 1 && cand >= mi)) {
						if (child[1 - tp].count(cand))
							return false;
						if (!child[tp].count(cand)) {
							child[tp].insert(cand);
							changed = true;
						}
					}
				}
			}
		}
	} while (changed);

	forn(i, vs.size()) {
		int cand = vs[i];
		if (!child[0].count(cand) && !child[1].count(cand)) {
			child[1].insert(cand);
		}
	}

	if (child[0].size() + child[1].size() != vs.size())
		throw;

	forn(tp, 2)
		if (child[tp].size()) {
			ans_g[root][tp] = *child[tp].begin();
			if (!rec(vector<int>(all(child[tp]))))
				return false;
		}
	return true;
}

bool dfs_check(int v) {
	if (v != check_exp)
		return false;
	++check_exp;

	if (ans_g[v][0] != -1)
		if (!dfs_check(ans_g[v][0]))
			return false;

	if (ans_g[v][1] != -1)
		if (!dfs_check(ans_g[v][1]))
			return false;
	
	return true;
}

void dfs_check2(int v) {
	check_tl[v] = check_t++;
	forn(tp, 2)
		if (ans_g[v][tp] != -1)
			dfs_check2(ans_g[v][tp]);
	check_tr[v] = check_t++;
}

bool check2() {
	dfs_check2(0);
	forn(i, m) {
		int son = ans_g[a[i]][tp[i]];
		if (son == -1)
			return false;
		if (!(check_tl[son] <= check_tl[b[i]] && check_tr[b[i]] <= check_tr[son]))
			return false;
	}
	return true;
}

void dfs_ans(int v) {
	if (ans_g[v][0] != -1)
		dfs_ans(ans_g[v][0]);
	printf("%d ", v + 1);
	if (ans_g[v][1] != -1)
		dfs_ans(ans_g[v][1]);
}

void solve() {
	forn(i, n)
		g[i].clear();
	forn(i, m) {
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	memset(forbidden, 0, sizeof forbidden);

	vector<int> vs;
	forn(i, n)
		vs.push_back(i);
	memset(ans_g, -1, sizeof ans_g);
	check_exp = 0;
	if (!rec(vs) || !dfs_check(0) || !check2()) {
		puts("IMPOSSIBLE");
		return;
	}

	dfs_ans(0);
	puts("");
}


int main() {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	while (read())
		solve();
#else
	if (!read())
		throw;
	solve();
#endif
}