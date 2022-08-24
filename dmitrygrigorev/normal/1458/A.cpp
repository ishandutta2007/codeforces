#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int gcd(int x, int y) {
	if (y==0) return x;
	return gcd(y, x%y);
}


main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);

	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	int g = 0;
	for (int i = 1; i < n; ++i) {
		g = gcd(g, abs(a[i] - a[0]));
	}

	for (auto x : b) {
		int t = gcd(g, x + a[0]);
		cout << t << " ";
	}

}