/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, LG = 17;
int rmq[N][LG];
int a[N];
int n, m, q;
vector <int> v[N];
int w[N];

void sp() {
	for (int i = 0; i < n - 1; i++) {
    	rmq[i][0] = a[i];
  	}
	for (int i = 1; i < LG; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (j + (1 << i) > n)
                break;
            rmq[j][i] = max(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int ask(int l, int r) { 
    int mn;
	int sz = (r - l + 1);
    if (sz == 1) {
        mn = rmq[l][0];
    } else {
        int x = 1, y = 0;
        while (x <= sz) {
            x *= 2;
            y++;
        }
        y--;
        mn = max(rmq[l][y], rmq[r - (1 << y) + 1][y]);
    }
    return mn;
}

void solve() {
	cin >> n >> m >> q;
	for (int i = 0; i <= n + 10; i++) {
		v[i].clear();
		v[i].push_back(i);
		w[i] = i;
		a[i] = INT_MAX;
	}
	for (int i = 0; i < m; i++) {
		int u, vv;
		cin >> u >> vv;
		u--, vv--;
		if (w[u] == w[vv])
			continue;
		int x = w[u];
		int y = w[vv];
		if (v[x].size() > v[y].size())
			swap(x, y);
		for (int j : v[x]) {
			v[y].push_back(j);
			w[j] = y;
		}
		for (int j : v[x]) {
			if (j != n - 1) {
				if (w[j] == w[j + 1]) {
					a[j] = min(a[j], i);
				}
			}
			if (j != 0) {
				if (w[j] == w[j - 1]) {
					a[j - 1] = min(a[j - 1], i);
				}
			}
		}
		v[x].clear();
	}
	sp();
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << 0 << ' ';
			continue;
		}
		l--;
		r -= 2;
		cout << ask(l, r) + 1 << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}