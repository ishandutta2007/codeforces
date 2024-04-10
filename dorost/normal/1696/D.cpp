/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 252144, LG = 18;
int a[N], dp[N], ns[N], ng[N];
pair <int, int> rmqmn[N][LG], rmqmx[N][LG];
int n;

void spmn() {
	for (int i = 1; i < LG; i++) {
		for (int j = 0; j < n; j++) {
			if (j + (1 << i) > n + 1)
				break;
			rmqmn[j][i] = min(rmqmn[j][i - 1], rmqmn[j + (1 << (i - 1))][i - 1]);
		}
	}
}

pair <int, int> askmn(int l, int r) { 
	pair <int, int> mn;
	int sz = (r - l) + 1;
	if (sz == 1) {
		mn = rmqmn[l][0];
	} else {
		int x = 1, y = 0;
		while (x <= sz) {
			x *= 2;
			y++;
		}
		y--;
		mn = min(rmqmn[l][y], rmqmn[r - (1 << y) + 1][y]);
	}
	return mn;
}

void spmx() {
	for (int i = 1; i < LG; i++) {
		for (int j = 0; j < n; j++) {
			if (j + (1 << i) > n + 1)
				break;
			rmqmx[j][i] = max(rmqmx[j][i - 1], rmqmx[j + (1 << (i - 1))][i - 1]);
		}
	}
}

pair <int, int> askmx(int l, int r) { 
	pair <int, int> mx;
	int sz = (r - l) + 1;
	if (sz == 1) {
		mx = rmqmx[l][0];
	} else {
		int x = 1, y = 0;
		while (x <= sz) {
			x *= 2;
			y++;
		}
		y--;
		mx = max(rmqmx[l][y], rmqmx[r - (1 << y) + 1][y]);
	}
	return mx;
}

void solve() {
	cin >> n;
	for (int i = 0; i <= n + 10; i++) {
		dp[i] = N;
		rmqmn[i][0] = {N, N};
		rmqmx[i][0] = {-1, -1};
		ng[i] = n;
		ns[i] = n;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		rmqmn[i][0] = {a[i], i};
		rmqmx[i][0] = {a[i], i};
	}
	spmn();
	spmx();
	vector <int> v, w;
	for (int i = 0; i < n; i++) {
		while (!v.empty() && (a[v.back()] < a[i])) {
			ng[v.back()] = i;
			v.pop_back();
		}
		while (!w.empty() && (a[w.back()] > a[i])) {
			ns[w.back()] = i;
			w.pop_back();
		}
		v.push_back(i);
		w.push_back(i);
	}
	dp[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = dp[i + 1] + 1;
		if (a[i] < a[i + 1]) {
			int bad = ns[i];
			pair <int, int> p = askmx(i + 1, bad - 1);
			dp[i] = min(dp[i], dp[p.S] + 1);
		} else {
			int bad = ng[i];
			pair <int, int> p = askmn(i + 1, bad - 1);
			dp[i] = min(dp[i], dp[p.S] + 1);
		}
	}
	cout << dp[0] << ' ';
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