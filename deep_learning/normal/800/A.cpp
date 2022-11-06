#include <iostream>
#include <cstdio>
using namespace std; 
int a[100005], b[100005]; 
int main()
{
	// freopen("800A.in", "r", stdin); 
	int n, p; 
	scanf("%d%d", &n, &p); 
	int x = p; 
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", a + i, b + i); 
		if (x >= 0)
			x -= a[i]; 
	}
	if (x >= 0)
	{
		printf("-1\n");
		return 0; 
	}
	double l = 0, r = 1e18, ans; 
	for (int i = 0; i < 1000; i++)
	{
		double mid = (l + r) / 2;
		double sum = p * mid; 
		for (int j = 0; j < n; j++)
			sum -= max(0.0, mid * a[j] - b[j]); 
		if (sum >= 0)
		{
			ans = mid; 
			l = mid; 
		}
		else
			r = mid;
	}
	printf("%.8lf\n", ans);
	return 0; 
}