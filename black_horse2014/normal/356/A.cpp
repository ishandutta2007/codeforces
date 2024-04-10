#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <utility>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define MX 300005
int a[MX];
set<int> S;
set<int> :: iterator it;

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int n, m, i, l, r, x;
	
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) S.insert(i);
	while (m--) {
		scanf("%d%d%d", &l, &r, &x);
		for (it = S.lower_bound(l); it != S.end(); ) {
			if (*it > r) break;
			if (*it == x) {
				it++;
				continue;
			}
			a[*it] = x;
			S.erase(it++);
		}
	}
	printf("%d", a[1]);
	for (i = 2; i <= n; i++) printf(" %d", a[i]);
}