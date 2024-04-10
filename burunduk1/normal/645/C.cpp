/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> v;
	forn(i, n)
		if (s[i] == '0')
			v.push_back(i);
	int j = 0, ans = n;
	forn(i, v.size() - k) {
		while (v[j + 1] - v[i] <= v[i + k] - v[j + 1])
			j++;
		ans = min(ans, min(max(v[j] - v[i], v[i + k] - v[j]), max(v[j + 1] - v[i], v[i + k] - v[j + 1])));
	}
	cout << ans << endl;
}