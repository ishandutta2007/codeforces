#include <bits/stdc++.h>
using namespace std;
#define maxn 500000 + 100

long long n, m;
string s1, s2;

int32_t main() {
	cin.tie(0), cout.sync_with_stdio(0);

	cin >> n >> m >> s1 >> s2;

	long long pos = 0, ans = 0, mid = 0;
	while (pos < n && s1[pos] == s2[pos])
		ans ++, pos ++;
	for (int i = pos; i < n; ++ i) {
		if (i == pos) ans += min(m, mid + 2);
		else {
			if (mid < m) mid = mid * 2 + (s1[i] == 'a') + (s2[i] == 'b');
			ans += min(m, mid + 2);
		}
		// cout << "[ans] = " << ans << endl;
	}
	cout << ans << "\n";
	return 0;
}