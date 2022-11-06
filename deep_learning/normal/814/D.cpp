#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std; 
struct circle
{
	int x, y, r, dep; 
	circle()
	{
		dep = 0; 
	}
	inline bool operator <(const circle &a) const
	{
		if (r == a.r)
		{
			if (x == a.x)
				return y < a.y; 
			return x < a.x; 
		}
		return r > a.r; 
	}
} arr[1005]; 
inline bool in(circle u, circle v)
{
	return (double)(u.x - v.x) * (u.x - v.x) + (double)(u.y - v.y) * (u.y - v.y) < (double)(u.r + v.r) * (u.r+v.r); 
}
int main()
{
	// freopen("814D.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].r);
	sort(arr, arr + n); 
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (in(arr[i], arr[j]))
				arr[j].dep++; 
		}
	}
	double ans = 0; 
	for (int i = 0; i < n; i++)
	{
		if (!arr[i].dep)
			ans += (double)arr[i].r * arr[i].r; 
		else if (arr[i].dep & 1)
			ans += (double)arr[i].r * arr[i].r; 
		else
			ans -= (double)arr[i].r * arr[i].r; 
	}
	printf("%.8lf\n", ans * acos(-1));
	return 0; 
}