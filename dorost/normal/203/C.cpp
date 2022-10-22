/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
pair <int, int> p[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, d, a, b;
	cin >> n >> d >> a >> b;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p[i] = {x * a + y * b, i + 1};
	}
	sort(p, p + n);
	int sum = 0, ans = n;
	for (int i = 0; i < n; i++) {
		sum += p[i].F;
		if (sum > d) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << p[i].S << ' ';
	}
}