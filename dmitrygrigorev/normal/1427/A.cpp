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

	int sum = 0;

	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
		sum += x;
	}

	if (sum == 0) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	if (sum > 0) sort(all(v), greater<int>());
	else sort(all(v));

	for (auto x : v) cout << x << " ";
	cout << endl;

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