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
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) {
			cout << "-1\n";
			return;
		}
	}

	int ans = 0;

	for (int i = 0; i < 20; ++i) {
		int Q = 100;
		for (int j = 0; j < a.size(); ++j) {
			if (a[j] - 'a' == i) {
				if (b[j] - 'a' > i) {
					Q = min(Q, b[j] - 'a');
				}
			}
		}

		if (Q==100) continue;
		ans++;

		for (int j = 0; j < a.size(); ++j) {
			if (a[j] - 'a' == i) {
				a[j] = (char) ('a' + Q);
			}
		}

	}

	cout << ans << "\n";





}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}