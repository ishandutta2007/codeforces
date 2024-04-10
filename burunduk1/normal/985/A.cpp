/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, k;
	cin >> n, k = n / 2;
	vector<int> a(k);
	forn(i, k) cin >> a[i], a[i]--;
	sort(a.begin(), a.end());
	int s1 = 0, s2 = 0;
	forn(i, k)  {
		s1 += abs(a[i] - (2 * i + 0));
		s2 += abs(a[i] - (2 * i + 1));
	}
	cout << min(s1, s2) << endl;
}