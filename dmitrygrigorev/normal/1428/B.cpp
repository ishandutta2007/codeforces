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
	string s;

	cin >> n >> s;

	bool cycle = false;

	int a = 0, b = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '<') a++;
		if (s[i] == '>') b++;
	}

	if (a == 0 || b == 0) cycle = true;
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '-' || s[(i+1)%n] == '-' || cycle) ans++;
	}

	cout << ans << '\n';

}

main(){
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