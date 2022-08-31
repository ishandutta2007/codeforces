#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {

	int n, k, m;
	cin >> n >> k >> m;

	vector<int> v(m+2);
	v[0] = -1;
	for (int i = 0; i < m; ++i) {
		cin >> v[i+1];
		v[i+1]--;
	}

	v[m+1] = n;

	if ((n - m) % (k - 1) != 0) {
		cout << "NO\n";
		return;
	}

	int sum = 0;
	for (int i = 1; i <= m+1; ++i) {
		int Q = v[i] - v[i-1] - 1;
		sum += Q;
	}

	if (sum < (k-1)/2) {
		cout << "NO\n";
		return;
	}

	int tsum = 0;

	for (int i = 1; i <= m+1; ++i) {
		int Q = v[i] - v[i-1] - 1;
		sum -= Q;

		if (Q > 0 && max(sum, tsum) < (k-1)/2) {
			cout << "NO\n";
			return;
		}

		tsum += Q;

	}

	cout << "YES\n";

}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}