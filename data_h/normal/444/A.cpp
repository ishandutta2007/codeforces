#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 111111;

double ans = 0;
int n, m;
int v[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}	
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ans = max(ans, 1.0 * (v[a] + v[b]) / c);
	}
	printf("%.12f\n", ans);
	return 0;
}