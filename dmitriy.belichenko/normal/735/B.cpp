


#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	int n, n1, n2;
	double sum1 = 0, sum2 = 0;
	cin >> n >> n1 >> n2;
	int mn = min(n1, n2);
	int mx = max(n1, n2);
	n1 = mn;
	n2 = mx;
	int a[100005];
	for (int i = 0; i < 100005; i++)
	{
		a[i] = INT_MAX;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n1; i++)
	{
		sum1 += a[i];
	}
	for (int i = n1; i < n1 + n2; i++)
	{
		sum2 += a[i];
	}
	double q = (double)((double)sum1 / (double)n1);
	double w = (double)((double)sum2 / (double)n2);
	//	cout << sum1 << " " << sum2;
	//double	ans = ;
	printf("%.20f", q + w);

	return 0;
}