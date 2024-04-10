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

#define MX 5005
#define INF 1100000000
struct Oper {
	int id;
	int l, r;
	int val;
} op[MX];

int a[MX];
bool vis[MX];

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int n, m, i, k, tmp;
	
	scanf("%d%d", &n, &m);
	for (k = 0; k < m; k++) scanf("%d%d%d%d", &op[k].id, &op[k].l, &op[k].r, &op[k].val);
	
	fill_n(a + 1, n, INF);
	for (k = 0; k < m; k++) {
		if (op[k].id == 1)
			for (i = op[k].l; i <= op[k].r; i++) a[i] += op[k].val;
		else {
			tmp = a[op[k].l];
			for (i = op[k].l + 1; i <= op[k].r; i++) tmp = max(tmp, a[i]);
			if (tmp < op[k].val) break;
			for (i = op[k].l; i <= op[k].r; i++) a[i] = min(a[i], op[k].val);
		}
	}
	if (k < m) {
		puts("NO");
		return 0;
	}
	fill_n(a + 1, n, INF);
	for (k = m - 1; k >= 0; k--) {
		if (op[k].id == 1)
			for (i = op[k].l; i <= op[k].r; i++) a[i] -= op[k].val;
		else {
			tmp = a[op[k].l];
			for (i = op[k].l + 1; i <= op[k].r; i++) tmp = max(tmp, a[i]);
			if (tmp < op[k].val) break;
			for (i = op[k].l; i <= op[k].r; i++) {
				vis[i]++;
				a[i] = min(a[i], op[k].val);
			}
		}
	}
	if (k >= 0) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (i = 1; i <= n; i++) {
		if (i > 1) printf(" ");
		printf("%d", vis[i] ? a[i] : 0);
	}
}