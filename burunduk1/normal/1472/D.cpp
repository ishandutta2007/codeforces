/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) cin >> a[i];
		sort(all(a), greater<int>());
		vector<int64_t> sum(2);
		forn(i, n) 
			if (a[i] % 2 == i % 2)
				sum[i % 2] += a[i];
		if (sum[0] > sum[1])
			cout << "Alice\n";
		else if (sum[0] < sum[1])
			cout << "Bob\n";
		else
			cout << "Tie\n";
	}
}