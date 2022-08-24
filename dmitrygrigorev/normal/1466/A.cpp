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
	for (auto &x : v) cin >> x;

	set<int> d;
	for (auto x : v) {
		for (auto y : v) {
			d.insert(abs(x-y));
		}
	}

	cout << d.size()-1 << '\n';

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

	for (int i = 0; i <t ; ++i) solve();

}