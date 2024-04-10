//#include "grader.h"
#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef int ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
//const int ma = 128 * 1024, mal = 8;
const int MAXN = 2 * 100 * 1000;
const ll mod = ll(1e9) + 7;

int n, cl[MAXN], mi[MAXN], ma[MAXN];
vector<int> e[MAXN];

void dfs(int nu, int pr) {
	for (int v : e[nu]) {
		if (v != pr) {
			dfs(v, nu);
			mi[nu] = min(mi[nu], mi[v]);
			ma[nu] = max(ma[nu], ma[v]);
		}
	}
}

void dfs1(int nu, int pr) {
	int nm_of = -1, cnt = 0;
	for (int v : e[nu]) {
		if (v != pr && mi[v] != ma[v]) {
			nm_of = v;
			cnt++;
		}
	}
	if (cnt >= 2) {
		cout << "NO\n";
		exit(0);
	}
	if (cnt == 0) {
		cout << "YES\n";
		cout << nu + 1;
		exit(0);
	}
	for (int v : e[nu]) {
		if (v != nm_of && cl[v] != cl[nu]) {
			cout << "NO\n";
			exit(0);
		}
	}
	dfs1(nm_of, nu);
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	forn (i, n) {
		cin >> mi[i];
		ma[i] = mi[i];
		cl[i] = mi[i];
	}
	dfs(0, -1);
	dfs1(0, -1);
	cout << "NO\n";
}