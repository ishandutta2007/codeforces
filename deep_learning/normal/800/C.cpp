#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back 
using namespace std; 
typedef long long ll; 
bool forbid[200005]; 
int dp[200005], pre[200005]; 
vector<int> cnt[200005], adj[200005], vec; 
ll gcd(ll x, ll y)
{
	if (!y)
		return x; 
	return gcd(y, x % y); 
}
void ex_gcd(ll a, ll b, ll &x, ll &y)
{
	if (!b)
	{
		x = 1; 
		y = 0; 
		return; 
	}
	ll x1, y1, t = a % b, k = a / b; 
	ex_gcd(b, t, x1, y1); 
	x = y1; 
	y = x1 - k * y1; 
}
int main()
{
	// freopen("C.in", "r", stdin); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		forbid[x] = true; 
	}
	for (int i = 1; i < m; i++)
	{
		if (!forbid[i])
			cnt[gcd(i, m)].pb(i); 
	}
	for (int i = 1; i < m; i++)
	{
		if (cnt[i].size())
		{
			for (int j = i + i; j < m; j += i)
			{
				if (cnt[j].size())
					adj[i].pb(j); 
			}
		}
	}
	int mx = 0, pos = 0; 
	for (int i = 1; i < m; i++)
	{
		dp[i] = max(dp[i], (int)cnt[i].size()); 
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (dp[i] + cnt[adj[i][j]].size() > dp[adj[i][j]])
			{
				dp[adj[i][j]] = dp[i] + cnt[adj[i][j]].size(); 
				pre[adj[i][j]] = i;
			}
		}
		if (dp[i] > mx)
		{
			mx = dp[i]; 
			pos = i; 
		}
	}
	printf("%d\n", mx + !forbid[0]);
	while (pos)
	{
		for (int j = 0; j < cnt[pos].size(); j++)
			vec.pb(cnt[pos][j]); 
		pos = pre[pos]; 
	}
	reverse(vec.begin(), vec.end()); 
	ll cur = 1; 
	for (int i = 0; i < vec.size(); i++)
	{
		ll x, y, res = gcd(cur, m); 
		ex_gcd(cur / res, m / res, x, y); 
		x = ((x * vec[i] / res) % m + m) % m; 
		printf("%d ", x);
		cur = (cur * x) % m; 
		// cout << cur << endl; 
	}
	if (!forbid[0])
		printf("0 ");
	printf("\n");
	return 0; 
}