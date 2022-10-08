/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n;
	cin >> n;
	multiset<int> ls, rs;
	forn(i, n) {
		int l, r;
		cin >> l >> r;
		ls.insert(l);
		rs.insert(r);
	}

	int64_t ans = 0;
	forn(i, n) {
		int l = *ls.begin();
		int r = *rs.begin();
		ls.erase(ls.begin());
		rs.erase(rs.begin());
		ans += max(l, r);
	}
	cout << n + ans << endl;
}