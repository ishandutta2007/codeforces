/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[m], b[m];
	forn(i, m)
		cin >> a[i] >> b[i], a[i]--, b[i]--;
	vector<int> c[n], q;
	int deg[n];
	function<int(int)> check = [&]( int k ) {
		forn(i, n)
			c[i].clear(), deg[i] = 0;
		forn(i, k)
			c[a[i]].push_back(b[i]), deg[b[i]]++;
		q.clear();
		forn(i, n)
			if (!deg[i])
				q.push_back(i);
		forn(i, n) {
			//printf("k=%d i=%d size=%d\n", k, i, (int)q.size());
			if (q.size() != i + 1) 
				return 0;
			int x = q[i];
			for (int y : c[x])
				if (!--deg[y])
					q.push_back(y);
		}
		return 1;
	};
	if (!check(m)) {
		puts("-1");
		return 0;
	}
	int l = 0, r = m;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	cout << r << endl;
}