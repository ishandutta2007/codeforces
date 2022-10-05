#include<bits/stdc++.h>
using namespace std;

double a, b, ans = 1e99;
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%lf%lf", &a, &b);
		ans = min(ans, m*a/b);
	}
	printf("%.12lf\n", ans);
	return 0;
}