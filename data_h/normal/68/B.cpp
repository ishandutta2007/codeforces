#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 20000;
int n, k;
double a[MAXN];

int check(double aver) {
	double res = 0;
	for(int i = 1; i <= n; i++) {
		if (a[i] < aver)
			res -= (aver - a[i]);
		else
			res += (a[i] - aver) * (100 - k) / 100.0;
	}
	return res >= 0;
}

int main() {

	scanf("%d %d", &n, &k);
	double Max = 0;
	for(int i = 1; i <= n; i++)
		scanf("%lf", &a[i]), Max = max(Max, a[i]);
	double l = 0, r = Max, mid;
	for(int i = 1; i <= 100; i++) {
		mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%.9lf", (l + r) / 2);
	return 0;
}