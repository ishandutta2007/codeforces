/* 	* In the name of GOD 
 	* Thanks God */

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 300001, SQ = 1005;
int a[N], lb[N][N / SQ + 1];
vector <int> b[N];

int cnt(int l, int r, int x) {
	return lower_bound(b[x].begin(), b[x].end(), r + 1) - lower_bound(b[x].begin(), b[x].end(), l);
}

int cnt2(int l, int r, int x) {
	return lb[r + 1][x] - lb[l][x];
}

int32_t main() {
	srand(time(NULL));
	vector <int> v;
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		b[a[i]].push_back(i);
	}
	for (int i = 0; i <= n; i++) {
		if (b[i].size() >= SQ) {
			v.push_back(i);
			int aa = v.size() - 1;
			for (int i = 0; i <= n; i++) {
				lb[i][aa] = lower_bound(b[v[aa]].begin(), b[v[aa]].end(), i) - b[v[aa]].begin();
			}
		}
	}
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		int mx = 0, s = (r - l + 1);
		if ((r - l + 1) >= 2 * SQ + 1) {
			for (int i = 0; i < v.size(); i++) {
				int x = cnt2(l, r, i);
				if (x >= mx) {
					mx = x;
				}
			}
		} else {
			for (int i = 0; i <= 60; i++) {
				int f = rand() % (r - l + 1) + l;
				int x = cnt(l, r, a[f]);
				if (x >= mx) {
					mx = x;
				}
			}
		}
		if (mx <= (s + 1) / 2) {
			printf("1 ");
			continue;
		}
		int d = s - mx, f = mx;
		f--;
		int ans = min({d, f / 2, f - d});
		f -= ans * 2;
		d -= ans;
		if (d == 0) {
			ans += f + 1;
		} else {
			ans += 1;
		}
		printf("%d ", ans);
	}
}