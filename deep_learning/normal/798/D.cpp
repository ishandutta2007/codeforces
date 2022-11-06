#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std; 
struct Num
{
	int a, b, idx; 
	inline bool operator <(const Num &x) const
	{
		if (a == x.a)
			return b > x.b; 
		return a > x.a; 
	}
} arr[100005]; 
int ans[100005], tot; 
int main()
{
	// freopen("798D.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].a); 
		arr[i].idx = i; 
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].b); 
	sort(arr, arr + n); 
	ans[tot++] = arr[0].idx; 
	int cur = 1;  
	while (cur < n && tot < (n >> 1) + 1)
	{
		if (cur + 1 >= n)
			ans[tot++] = arr[cur].idx; 
		else
			ans[tot++] = arr[cur].b > arr[cur + 1].b ? arr[cur].idx : arr[cur + 1].idx; 
		cur += 2; 
	}
	sort(ans, ans + tot); 
	printf("%d\n", tot);
	for (int i = 0; i < tot; i++)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == tot]);
	return 0; 
}