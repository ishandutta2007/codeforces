#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std; 
struct Number
{
	int val, idx; 
	Number()
	{
	}
	Number(int _val, int _idx)
	{
		val = _val; 
		idx = _idx; 
	}
	inline bool operator <(const Number &a) const
	{
		return val > a.val; 
	}
} arr[200005];
int num[200005], ans[200005]; 
int main()
{
	// freopen("840A.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", num + i); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].val);
		arr[i].idx = i; 
	}
	sort(num, num + n); 
	sort(arr, arr + n); 
	for (int i = 0; i < n; i++)
		ans[arr[i].idx] = num[i]; 
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	return 0;
}