#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;  
ll arr[1000005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("833A.in", "r", stdin); 
#endif
	for (int i = 1; i < 1000005; i++)
		arr[i] = (ll)i * i * i; 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		ll a, b; 
		scanf("%lld%lld", &a, &b); 
		int x = lower_bound(arr, arr + 1000005, a * b) - arr; 
		if (arr[x] != a * b || a % x || b % x)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0; 
}