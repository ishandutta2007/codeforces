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

	set<int> ms;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int y = i + x;
		y %= n;
		if (y < 0) y += n;
		ms.insert(y);
	}

	if (ms.size() == n) cout << "YES\n";
	else cout << "NO\n";

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}