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

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	for (int i = 29; i >= 0 ;i--) {
		int a = 0, b = 0;
		for (auto x : v) {
			if (x&(1<<i)) a++;
			else b++;
		}

		if (a%2==0) continue;
		if (a%4 == 1) {
			cout << "WIN\n";
			return;
		}
		if ((a+b)%2 == 0) {
			cout << "WIN\n";
		}
		else cout << "LOSE\n";
		return;
	}

	cout << "DRAW\n";

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