#include <bits/stdc++.h>
using namespace std;
set<int> a[200020];
vector<int> z;
int n, m;
set<int> s;
int dfs(int i) {
	int sz = 1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ) {
		if (a[i].count(*it) == 0) {
			int x = *it;
			s.erase(x);
			sz += dfs(x);
			it = s.lower_bound(x);
		} else {
			it++;
		}
	}
	return sz;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].insert(y);
		a[y].insert(x);
	}
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	while (s.size()) {
		int x = *s.begin();
		s.erase(x);
		z.push_back(dfs(x));
	}
	sort(z.begin(), z.end());
	printf("%d\n", (int)z.size());
	for (int i: z) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}