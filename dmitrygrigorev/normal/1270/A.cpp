#include <bits/stdc++.h>
#define ll long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	bool first = true;
	int x;
	for (int i=0;i<a;++i) cin >> x;
	for (int i=0;i<b;++i) {
		cin >> x;
		if (x == n) first = false;
	}
	if (first) cout << "YES\n";
	else cout << "NO\n";
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