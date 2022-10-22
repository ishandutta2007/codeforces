/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];
vector <ll> ans[160];
bool p[N];

int h(int i, int j) {
	return i * N + j;
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
		p[i] = true;
	for (int i = 2; i <= n; i++) {
		for (int j = i * 2; j <= n; j += i)
			p[j] = false;
	}
	for (int i = 0; i < 160; i++)
		ans[i].clear();
	priority_queue <pair <ll, int>, vector <pair <ll, int>>> pq;
	vector <int> divs;
	for (int i = 1; i < n; i++) {
		if (n % i == 0 && (p[n / i]))
			divs.push_back(i);
	}
	for (int i = 0; i < (int)divs.size(); i++) {
		for (int j = 0; j < divs[i]; j++) {
			ans[i].push_back(0);
			ans[i][j] = a[j];
			for (int k = (j + divs[i]) % n; k != j; k = (k + divs[i]) % n) {
				ans[i][j] += a[k];
			}
			ans[i][j] *= (divs[i]);
			pq.push(make_pair(ans[i][j], h(i, j)));
		}
	}
	cout << (pq.top()).F << ' ';
	while (q--) {
		int p, x;
		cin >> p >> x;
		p--;
		for (int i = 0; i < (int)divs.size(); i++) {
			int j = p % divs[i];
			ans[i][j] += (ll)divs[i] * (x - a[p]);
			pq.push(make_pair(ans[i][j], h(i, j)));
		}
		a[p] = x;
		while (!pq.empty()) {
			pair <ll, int> p = pq.top();
			if (ans[p.S / N][p.S % N] == p.F)
				break;
			pq.pop();
		}
		cout << (pq.top()).F << ' ';
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