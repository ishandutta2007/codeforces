/*input
1
1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100900
int n, x[maxn];

int32_t main() {
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> x[i];

	if (n == 1) {
		cout << "1 1" << "\n";
		cout << x[1] + 10 << "\n", x[1] += x[1] + 10;
		cout << "1 1" << "\n";
		cout << x[1] + 10 << "\n", x[1] += x[1] + 10;
		cout << "1 1" << "\n";
		cout << -x[1] << "\n";
	}
	else {
		cout << "1 1" << "\n";
		if (n == x[1]) 
			 cout << n * 2 - x[1] << "\n", x[1] = n * 2;
		else cout << n * 1 - x[1] << "\n", x[1] = n;
		cout << "2 " << n << "\n";
		for (int i = 2; i <= n; ++ i) {
			int val;
			if (x[i] == 0) val = (n - 1) * n;
			else {
				val = x[i] * (n - 1);
			}
			cout << val << " \n"[i == n];
			x[i] += val;
		}
		cout << "1 " << n << "\n";
		for (int i = 1; i <= n; ++ i) { cout << -x[i] << " \n"[i == n];
		}
	}
	return 0;
}