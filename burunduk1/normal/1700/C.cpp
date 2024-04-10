/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

/**
 * d[i]+=1
 * d[i-1]-=1
 * a[0]+=1
 * a[0]-=1
 */

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int64_t s = 0, d0 = 0;
	forn(i, n - 1) {
		auto d = a[i + 1] - a[i];
		if (d > 0)
			s += d;
		else
			s -= d, d0 += d;
	}
	cout << s + abs(a[0] + d0) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int tn;
	cin >> tn;
	while (tn--)
		solve();
}