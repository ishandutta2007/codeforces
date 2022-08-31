#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
	}
	vector<vector<int> > cows(n);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cows[a-1].push_back(b);
	}

	int ans = 0, ways = 0;
	vector<int> cnta(n), cntb(n);


	for (int i = 0; i <= n; ++i) {
		cnta.assign(n, 0);
		cntb.assign(n, 0);
		for (int j = 0; j < i; ++j) cnta[v[j]]++;
		for (int j = i; j < n; ++j) cntb[v[j]]++;
		if (i > 0) {
			bool here = false;
			for (int j = 0; j < cows[v[i-1]].size(); ++j) {
				if (cows[v[i-1]][j] == cnta[v[i-1]]) here = true;
			}
			if (!here) continue;
		}

		int tuta = (i>0), tutw = 1;

		for (int j = 0; j < n; ++j) {
			int left = 0, right = 0;
			for (int k = 0; k < cows[j].size(); ++k) {
				if (cows[j][k] <= cnta[j]) left++;
				if (cows[j][k] <= cntb[j]) right++;
			}
			if (i > 0 && v[i-1] == j) {
				if (cntb[j] >= cnta[j]) right--;
				if (right > 0) {
					tuta++;
					tutw = ((ll) tutw * right) % mod;
				}
			}
			else {
				if (left > right) swap(left, right);
				if (right == 0) continue;
				if (left == 0) {
					tuta++;
					tutw = ((ll) tutw * right) % mod;
					continue;
				}
				if (left == 1 && right == 1) {
					tuta++;
					tutw = ((ll) tutw * 2) % mod;
					continue;
				}
				tuta += 2;
				tutw = ((ll) tutw * left) % mod;
				tutw = ((ll) tutw * (right - 1)) % mod;
			}
		}

		if (tuta == ans) {
			ways += tutw;
			ways %= mod;
		}

		else if (tuta > ans) {
			ans = tuta;
			ways = tutw;
		}
	}

	cout << ans << " " << ways << "\n";


}