/* 	* In the name of GOD  */

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200200, K = 455, B = 440;
ll k[B];
ll ps[N];
int a[N];
pair <int, int> w[B][K];

bool cmp (pair <int, int> p, pair <int, int> q) {
	return p.F < q.F;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 0; i < N; i++)
		a[i] = INT_MAX / 2;
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	n = N;
	k[0] = 0;
	for (int i = 0; i < B; i++) {
		if (i != 0) {
			k[i] = ps[i * K - 1] + a[i * K - 1] + k[i - 1];
		}
		ps[i * K] = 0;
		w[i][0] = make_pair(a[i * K], 0);
		for (int j = i * K + 1; j < (i + 1) * K; j++) {
			ps[j] = ps[j - 1] + a[j - 1];
			if (a[j] < ps[j]) {
				w[i][j - i * K] = make_pair(-1, j - i * K);
				continue;
			}
			w[i][j - i * K] = make_pair(a[j] - ps[j], j - i * K);
		}
		sort(w[i], w[i] + K, cmp);
	}
	while (q--) {
		int p, x;
		cin >> p >> x;
		p--;
		for (int i = 0; i < B; i++) {
			if (i * K > p && i * K < n) {
				k[i] -= a[p];
				k[i] += x;
			}
		}
		a[p] = x;
		int b = p / K;
		ps[b * K] = 0;
		w[b][0] = make_pair(a[b * K], 0);
		for (int j = b * K + 1; j < (b + 1) * K; j++) {
			ps[j] = ps[j - 1] + a[j - 1];
			if (a[j] < ps[j]) {
				w[b][j - b * K] = make_pair(-1, j - b * K);
				continue;
			}
			w[b][j - b * K] = make_pair(a[j] - ps[j], j - b * K);
		}
		sort(w[b], w[b] + K, cmp);
		int ans = -1;
		for (int i = 0; i < B; i++) {
			if (k[i] >= INT_MAX)
				continue;
			int x = lower_bound(w[i], w[i] + K, make_pair((int)k[i], 0)) - w[i];
			if (x == K)
				continue;
			if (w[i][x].F == k[i]) {
				ans = w[i][x].S + 1 + i * K;
				break;
			}
		}
		cout << ans << ' ';
	}
}