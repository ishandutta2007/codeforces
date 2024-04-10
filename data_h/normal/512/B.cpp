#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

const int N = 11111;

int n;
map<int, int> f, g;
int val[N], cost[N];

int __min(int a, int b) {
	if (a == 0 || a > b) {
		return b;
	} else {
		return a;
	}
}

int main() {
	scanf("%d", &n);
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(map<int, int> :: iterator it = f.begin(); it != f.end(); ++it) {
			int x = it->first, c = it->second;
			g[__gcd(x, val[i])] = __min(g[__gcd(x, val[i])], c + cost[i]);
			g[x] = __min(g[x], f[x]);
		}
		f = g;
		/*for(map<int, int> :: iterator it = f.begin(); it != f.end(); ++it) {
			printf("%d %d\n", it->first, it->second);
		}
		puts("");*/
		g.clear();
		//printf("= = =%d\n", (int)f.size());
	}
	if (f[1] == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", f[1]);
	}
	return 0;
}