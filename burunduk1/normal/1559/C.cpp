/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#define _GLIBCXX_DEBUG
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n, p;
	cin >> n;
	vector<int> a(n), ans(n);
	forn(i, n)
		cin >> a[i], ans[i] = i;
	if (a[0] == 1)
		p = 0;
	else if (a.back() == 0)
		p = n;
	else 
		for (p = 1; !(a[p-1] == 0 && a[p] == 1); p++)
			;
	// printf("p = %d\n", p);
	ans.insert(ans.begin() + p, n);
	for (int x : ans) cout << x + 1 << " ";
	cout << "\n";


}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) 
		solve();
}