#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std; 
typedef long long ll; 
struct person
{
	int st, v, dir; 
} arr[100005];
int n, s; 
inline bool chk(double num)
{
	ll l1 = 1e6, l2 = 0, r1 = 1e6, r2 = 0;
	bool f1 = false, f2 = false; 
	for (int i = 0; i < n; i++)
	{
		if (arr[i].dir == 1)
		{
			if (arr[i].st - (double)(arr[i].v + s) * num >= -1e-6)
				continue; 
			f1 = true; 
			if (arr[i].st - (double)arr[i].v * num <= 1e-6)
			{
				l1 = 0; 
				l2 = 1e6; 
				continue; 
			}
			double t = (arr[i].st - (double)arr[i].v * num) / s; 
			l1 = min(l1, (ll)arr[i].st); 
			l2 = max(l2, (ll)(arr[i].st + floor((s - arr[i].v) * (num - t)))); 
		}
		else
		{
			if (arr[i].st + (double)(arr[i].v + s) * num <= 1e6)
				continue; 
			f2 = true; 
			if (arr[i].st + (double)arr[i].v * num >= 1e6)
			{
				r1 = 0; 
				r2 = 1e6; 
				continue; 
			}
			double t = (1e6 - arr[i].st - (double)arr[i].v * num) / s; 
			r1 = min(r1, (ll)(arr[i].st - floor((s - arr[i].v) * (num - t)))); 
			r2 = max(r2, (ll)arr[i].st); 
		}
	}
	// cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl; 
	if (!f1 || !f2 || l1 > l2 || r1 > r2)
		return false;
	return l1 <= r2 && l2 >= r1; 
}
int main()
{
	// freopen("832C.in", "r", stdin); 
	scanf("%d%d", &n, &s); 
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &arr[i].st, &arr[i].v, &arr[i].dir); 
	// chk(5e5); 
	double l = 0, r = 1e6, ans; 
	for (int i = 0; i < 100; i++)
	{
		double m = (l + r) / 2; 
		if (chk(m))
		{
			r = m; 
			ans = m; 
		}
		else
			l = m; 
	}
	printf("%.8lf\n", ans);
	return 0; 
}