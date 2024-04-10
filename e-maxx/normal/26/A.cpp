#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;

	vector<char> prime (n+1);
	int ans = 0;
	for (int i=2; i<=n; ++i) {
		int divs = 0,  num = i,  diff = 0;
		for (int j=2; j*j<=num; ++j) {
			bool any = false;
			while (num % j == 0 && prime[j]) {
				++divs;
				num /= j;
				any = true;
			}
			diff += any;
		}
		if (num > 1)  ++diff;
		prime[i] = divs == 0;
		ans += diff == 2;
	}
	cout << ans;

}