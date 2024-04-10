#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 256 * 1024;

int n, m, r[ma], use[ma], cl[ma];
vector<int> num[ma];
vector<pair<int, int> > e[ma];

void dfs(int nu) {
	use[nu] = 1;
	for (auto v : e[nu]) {
		if (use[v.fi]) {
			if (cl[nu] != (cl[v.fi] ^ v.se)) {
				cout << "NO\n";
				exit(0);
			}
		} else {
			cl[v.fi] = (cl[nu] ^ v.se);
			dfs(v.fi);
		}
	}
}
int main() {
	iostream::sync_with_stdio(0);
//	freopen("a.in", "r", stdin);
	scanf("%d%d", &n, &m);
	forn (i, n) {
		scanf("%d", &r[i]);
	}
	forn (i, m) {
		int k;
		scanf("%d", &k);
		forn (j, k) {
			int b;
			scanf("%d", &b);
			b--;
			num[b].push_back(i);
		}
	}
	forn (i, n) {
		if (r[i]) {
			e[num[i][0]].push_back(mp(num[i][1], 0));
			e[num[i][1]].push_back(mp(num[i][0], 0));
		} else {
			e[num[i][0]].push_back(mp(num[i][1], 1));
			e[num[i][1]].push_back(mp(num[i][0], 1));
		}
	}
	forn (i, m)
		cl[i] = -1;
	forn (i, m) {
		if (!use[i]) {
			dfs(i);
		}
	}
	cout << "YES\n";
}