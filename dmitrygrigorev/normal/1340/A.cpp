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
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
	}

	vector<int> pos(n);
	for (int i = 0; i < n; ++i) pos[v[i]] = i;

	int cur = 0;
	while (cur < n) {
		int x = pos[cur];
		if (x >= n-cur) {
			cout << "No\n";
			return;
		}

		int delta = n-cur-x;

		for (int i = 0; i < delta; ++i) {
			if (pos[cur + i] != pos[cur] + i) {
				cout << "No\n";
				return;
			}
		}

		cur += delta;

	}

	cout << "Yes\n";

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