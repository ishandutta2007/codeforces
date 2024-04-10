#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cassert>
using namespace std;

const int N = 1e5 + 7;

int n, p[N];
set<int> s;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		s.insert(p[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] == i) {
			s.erase(i);
			ans ++;
		}
	}
	assert(s.size() % 2 == 0);
	printf("%d\n", ans + s.size() / 2);
	return 0;
}