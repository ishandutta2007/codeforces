#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <cstdlib>
#include <cstdio>
#endif
using namespace std; 
int arr[100005]; 
int main()
{
	// freopen("798C.in", "r", stdin); 
	int n, x; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		if (i)
			x = __gcd(x, arr[i]); 
		else
			x = arr[i];
	}
	if (x > 1)
	{
		printf("YES\n0\n");
		return 0; 
	}
	int ans = 0; 
	for (int i = 1; i < n; i++)
	{
		if ((arr[i - 1] & 1) && (arr[i] & 1))
		{
			arr[i - 1] = 0; 
			arr[i] = 0; 
			ans++; 
		}
	}
	for (int i = 1; i < n; i++)
	{
		if ((arr[i - 1] & 1) ^ (arr[i] & 1))
		{
			arr[i - 1] = 0; 
			arr[i] = 0; 
			ans += 2; 
		}
	}
	printf("YES\n%d\n", ans);
	return 0; 
}