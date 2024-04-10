#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int n, m;
char buf[10000];
set<string> a, b;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		a.insert(buf);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", buf);
		b.insert(buf);
	}
	vector<string> common(100007);
	vector<string> :: iterator it = std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), common.begin());
	common.resize(it - common.begin());
	int cs = common.size();
	n -= cs, m -= cs;
	if (cs & 1) {
		m--;
	}
	if (n > m) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}