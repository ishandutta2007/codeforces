/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<vector<int>> sumr(n + 1, vector<int>(3)), suml = sumr;
	forn(i, n) {
		sumr[i + 1] = sumr[i], sumr[i + 1][(s[i] - 'a' + i) % 3]++;
		suml[i + 1] = suml[i], suml[i + 1][(3 - (s[i] - 'a') + i) % 3]++;
	}
	while (q--) {
		int l, r, ma = 0;
		cin >> l >> r, l--;
		forn(i, 3) {
			ma = max(ma, suml[r][i] - suml[l][i]);
			ma = max(ma, sumr[r][i] - sumr[l][i]);
		}
		cout << r - l - ma << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn = 1;
	// cin >> tn;
	while (tn--)
		solve();
}