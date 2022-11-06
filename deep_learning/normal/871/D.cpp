#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
using namespace std; 
typedef long long ll; 
int phi[10000005], mn[10000005], app[10000005], p[10000005], bad_cnt; 
bool bad[10000005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("871D.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++)
		phi[i] = i; 
	for (int i = 2; i <= n; i++)
	{
		if (mn[i])
			continue;
		mn[i] = i; 
		phi[i] = i - 1; 
		for (int j = i + i; j <= n; j += i)
		{
			if (!mn[j])
				mn[j] = i; 
			phi[j] = phi[j] / i * (i - 1); 
		}
	}
	ll one = 0, two = 0; 
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || (mn[i] == i && 2 * i > n))
		{
			bad[i] = true; 
			bad_cnt++; 
		}
		if (i == 1)
			continue; 
		if (mn[i] == i)
			p[i] = 1; 
		else if (mn[i / mn[i]] == mn[i])
			p[i] = p[i / mn[i]]; 
		else
			p[i] = p[i / mn[i]] + 1; 
		if (!bad[i])
		{
			one += i - 1 - phi[i]; 
			app[mn[i]]++; 
		}
	}
	int cnt = 1;
	for (int i = 2; i <= n; i++)
	{
		if (mn[i] != i)
			two += phi[i] - cnt + p[i]; 
		else
			cnt++; 
		app[i] += app[i - 1]; 
	}
	for (int i = 2; i <= n; i++)
	{
		if (mn[i] != i || bad[i])
			continue; 
		two += app[n / i]; 
		for (int j = i; j <= n; j += i)
			two -= mn[j] <= n / i; 
	}
	for (int i = 2; i <= n; i++)
	{
		int x = mn[i], y = i / x; 
		if (y != 1 && mn[y] == y && x != y)
			two--; 
	}
	// cout << one << " " << two << " " << (ll)(n - bad_cnt) * (n - bad_cnt - 1) / 2 - one - two << endl; 
	printf("%lld\n", one + two * 2 + ((ll)(n - bad_cnt) * (n - bad_cnt - 1) / 2 - one - two) * 3);
	return 0; 
}