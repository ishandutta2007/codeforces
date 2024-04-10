/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#define _GLIBCXX_DEBUG
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

/**

a[i] = min --> max

i --> j --> k
a[i] < a[j] > a[k]
     x      0 

i --> k
y <= x

--

a[0] <= a[1] <= a[2] <= ...

c[i] >= a[j] - a[i] | a[i] < a[j] <= a[i] + c[i]
min k | a[i] + c[i] < a[k]
i --> k --> k+1
k+1

i --> [i..k-1]  
i --> k  a[k]-(a[i]+c[i])
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> s(n);
	int64_t ans = 0;
	forn(i, n)
		cin >> s[i].first >> s[i].second, ans += s[i].second;
	sort(all(s));

	vector<int> f(n, INT_MAX);
	f[0] = 0; // f[i] <= f[i+1]
	int k = 0;
	for (int i = 0; i < n - 1; i++) {
		auto relax = [](int &x, int y) {
			x = min(x, y);
		};
		#define a(i) s[i].first
		#define c(i) s[i].second
		while (k < n && a(i) + c(i) >= a(k))
			relax(f[k], f[i]), k++;
		if (k < n)
			relax(f[k], f[i] + (a(k) - (a(i) + c(i))));
	}
	cout << ans + f[n-1] << endl;
	// s[0] --> s[n-1]
}