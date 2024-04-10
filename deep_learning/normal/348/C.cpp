#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define B_SZ 320
#define MAX_N 100005
#define pb push_back
using namespace std;
typedef long long ll; 
ll arr[MAX_N], res[B_SZ], delta[B_SZ]; 
vector<int> num[MAX_N];  
int big[B_SZ], is_big[MAX_N], cnt[MAX_N], sz[MAX_N], same[B_SZ][MAX_N]; 
int main()
{
	// freopen("348C.in", "r", stdin); 
	int n, m, q, tot = 0; 
	memset(is_big, -1, sizeof(is_big)); 
	scanf("%d%d%d", &n, &m, &q); 
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d", sz + i); 
		for (int j = 0; j < sz[i]; j++)
		{
			int x; 
			scanf("%d", &x); 
			num[i].pb(--x); 
		}
		if (sz[i] >= B_SZ)
		{
			big[tot] = i; 
			is_big[i] = tot++; 
		}
	}
	for (int i = 0; i < tot; i++)
	{
		for (int j = 0; j < sz[big[i]]; j++)
		{
			res[i] += arr[num[big[i]][j]]; 
			cnt[num[big[i]][j]]++; 
		}
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < sz[j]; k++)
				same[i][j] += cnt[num[j][k]]; 
		}
		for (int j = 0; j < sz[big[i]]; j++)
			cnt[num[big[i]][j]]--; 
	}
	while (q--)
	{
		char tp; 
		scanf("\n%c", &tp); 
		if (tp == '+')
		{
			int x, y; 
			scanf("%d%d", &x, &y); 
			x--; 
			if (is_big[x] != -1)
				delta[is_big[x]] += y; 
			else
			{
				for (int j = 0; j < sz[x]; j++)
					arr[num[x][j]] += y; 
				for (int j = 0; j < tot; j++)
					res[j] += y * same[j][x]; 
			}
		}
		else
		{
			ll ans = 0; 
			int x; 
			scanf("%d", &x); 
			x--; 
			if (is_big[x] != -1)
			{
				ans = res[is_big[x]]; 
				for (int j = 0; j < tot; j++)
					ans += delta[j] * same[j][x]; 
			}
			else
			{
				for (int j = 0; j < sz[x]; j++)
					ans += arr[num[x][j]]; 
				for (int j = 0; j < tot; j++)
					ans += delta[j] * same[j][x]; 
			}
			printf("%lld\n", ans);
		}
	}
	return 0; 
}