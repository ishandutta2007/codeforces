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
	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		if (v[i] == d) {
			cout << "1\n";
			return;
		}
	}

	cout << max(2, (d + v.back() - 1) / v.back()) << "\n";

}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}