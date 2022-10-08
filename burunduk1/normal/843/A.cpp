/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	scanf("%d", &n);
	pair<int, int> a[n];
	forn(i, n) 
		scanf("%d", &a[i].first), a[i].second = i;
	sort(a, a + n);

	vector<vector<int>> ans;
	vector<int> u(n, 0);
	forn(i, n) {
		if (!u[i]) {
			vector<int> p;
			for (int j = i; !u[j]; j = a[j].second)
				p.push_back(j), u[j] = 1;
			ans.push_back(p);
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto &a : ans) {
		printf("%d", (int)a.size());
		for (int x : a)
			printf(" %d", x + 1);
		puts("");
	}
}