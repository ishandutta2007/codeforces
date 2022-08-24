#include <bits/stdc++.h>
#define ll long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0;i<n;++i) cin >> v[i];

	for (int i = 0; i + 1 < n; ++i) {
		if (min(v[i], v[i+1]) + 2 <= max(v[i], v[i+1])) {
			cout << "YES\n";
			cout << i+1 << " " << i+2 << "\n";
			return;
		}
	}
	cout << "NO\n";

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
	for (int i=0; i < t; ++i) solve();

}