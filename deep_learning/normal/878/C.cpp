#include <iostream>
#include <cstdio>
#include <set>
using namespace std; 
int n, k; 
struct athlete
{
	int arr[15], mn[15], mx[15], cnt;  
	athlete()
	{
		for (int i = 0; i < k; i++)
		{
			scanf("%d", arr + i); 
			mn[i] = arr[i]; 
			mx[i] = arr[i]; 
		}
		cnt = 1; 
	}
	inline bool operator <(const athlete &a) const
	{
		for (int i = 0; i < k; i++)
		{
			if (a.mn[i] < mx[i])
				return false; 
		}
		return true; 
	}
	inline athlete operator +=(const athlete &a)
	{
		for (int i = 0; i < k; i++)
		{
			mn[i] = min(mn[i], a.mn[i]); 
			mx[i] = max(mx[i], a.mx[i]); 
		}
		cnt += a.cnt; 
		return *this; 
	}
}; 
set<athlete> se; 
int main()
{
	// freopen("878C.in", "r", stdin); 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < n; i++)
	{
		athlete x;
		set<athlete>::iterator l = se.lower_bound(x), r = se.upper_bound(x); 
		while (l != r)
		{
			x += *l; 
			se.erase(l++); 
		}
		se.insert(x); 
		printf("%d\n", se.rbegin()->cnt);
	}
	return 0; 
}