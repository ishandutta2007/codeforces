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
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
ll mod[100005]; 
int arr[100005], cnt; 
inline ll quick_pow(ll a, ll n, ll MOD)
{
	ll res = 1; 
	while (n)
	{
		if (n & 1)
			res = min(res * a % MOD + MOD, res * a); 
		a = min(a * a % MOD + MOD, a * a); 
		n >>= 1; 
	}
	return res; 
}
ll query(int l, int r, int cur)
{
	if (l > r)
		return 1; 
	if (cur >= cnt)
		return min(arr[l], 2); 
	return quick_pow(arr[l], query(l + 1, r, cur + 1), mod[cur]); 
}
inline int phi(int n)
{
	int res = n, x = n; 
	for (int i = 2; i * i <= n; i++)
	{
		if (x % i)
			continue; 
		while (!(x % i))
			x /= i; 
		res = res / i * (i - 1); 
	}
	if (x != 1)
		res = res / x * (x - 1); 
	return res; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("906D.in", "r", stdin); 
#endif
	int n, m; 
	scanf("%d%d", &n, &m); 
	while (m != 1)
	{
		mod[cnt++] = m; 
		m = phi(m); 
	}
	mod[cnt] = 1; 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	int q; 
	scanf("%d", &q); 
	while (q--)
	{
		int l, r; 
		scanf("%d%d", &l, &r); 
		printf("%lld\n", query(--l, --r, 0) % mod[0]);
	}
	return 0; 
}