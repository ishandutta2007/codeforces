#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef unsigned long long ull;
const ll ma = 128;

int n, ans[100000], h[100000];
vector<int> e[100000];
vector<int> vv;
int ps = 0, hh = 0;

void dfs(int nu, int pr, int qh) {
	if (qh > hh) {
		ps = nu;
		hh = qh;
	}
	for (int v : e[nu]) {
		if (v != pr) {
			dfs(v, nu, qh + 1);
		}
	}
}

int dfs2(int nu, int pr) {
	int c = -1;
	for (int v : e[nu]) {
		if (v != pr) {
			int qq = dfs2(v, nu);
			if (qq > c) {
				if (c != -1) vv.push_back(c);
				c = qq;
			} else
				vv.push_back(qq);
		}
	}
	c++;
	return max(c, 1);
}

int main() {
	iostream::sync_with_stdio(0);
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(0, -1, 0);
	vv.push_back(dfs2(ps, -1));
	while(sz(vv) + 1 < n) vv.push_back(0);
	sort(vv.rbegin(), vv.rend());
	cout << 1 << " ";
	int sm = 0;
	for (int v : vv) {
		sm += v;	
		cout << sm << " ";
	}
}