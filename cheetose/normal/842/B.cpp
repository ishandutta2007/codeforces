#include<cstdio>
#include<cmath>
int main() {
	int r, d, n;
	scanf("%d%d%d", &r, &d, &n);
	int ans = 0;
	while (n--)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		double dist = sqrt((double)x*x + y*y);
		if (dist + k <= (double)r && dist - k >= (double)(r - d)) ans++;
	}
	printf("%d", ans);
}