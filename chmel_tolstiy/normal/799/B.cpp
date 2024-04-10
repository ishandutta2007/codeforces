#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n), p(n);

	set<pii> s[3];

	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < n; ++i) {
		--a[i], --b[i];
		s[a[i]].insert(pii(p[i], i));
		s[b[i]].insert(pii(p[i], i));
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int c; scanf("%d", &c); --c;
		int r = -1;

		if (s[c].size()) {
			pii x = *s[c].begin();
			r = x.first;
			int z = x.second;
			s[a[z]].erase(x);
			s[b[z]].erase(x);
		}

		printf("%d ", r);
	}
	return false;
}

int main() {
	
    while (solve());
    
    return 0;
}