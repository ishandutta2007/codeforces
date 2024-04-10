#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("939B.in", "r", stdin); 
#endif
	ll n, ans = 2e18, cnt; 
	int k, pos; 
	scanf("%lld%d", &n, &k); 
	for (int i = 0; i < k; i++)
	{
		ll x; 
		scanf("%lld", &x); 
		if (n % x < ans)
		{
			ans = n % x; 
			pos = i; 
			cnt = n / x; 
		}
	}
	printf("%d %lld\n", pos + 1, cnt);
	return 0; 
}