#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
int n, m, arr[102400]; 
bool app[204800]; 
ll d, fst; 
bool exist(int x)
{
	int pos = lower_bound(arr, arr + n, x) - arr; 
	return pos < n && arr[pos] == x; 
}
ll quick_pow(ll a, int n)
{
	ll res = 1; 
	while (n > 0)
	{
		if (n & 1)
			res = (res * a) % m; 
		a = (a * a) % m; 
		n >>= 1; 
	}
	return res; 
}
void work()
{
	if (n == 1)
	{
		fst = arr[0]; 
		d = 1; 
		return; 
	}
	int tmp = arr[1] - arr[0], cnt = 0; 
	for (int i = 0; i < n; i++)
	{
		if (exist((arr[i] + tmp) % m))
			cnt++; 
	}
	d = quick_pow(n - cnt, m - 2) * tmp % m; 
	for (int i = 0; i < n; i++)
	{
		if (!exist((arr[i] + (m - d) % m) % m))
		{
			if (fst == -1)
				fst = arr[i]; 
			else
			{
				fst = -1; 
				return;
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("763C.in", "r", stdin); 
#endif
	fst = -1; 
	scanf("%d%d", &m, &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	sort(arr, arr + n); 
	if (n == 1 || n == m)
	{
		printf("%d 1\n", arr[0]);
		return 0; 
	}
	if (2 * n < m)
		work(); 
	else
	{
		for (int i = 0; i < n; i++)
			app[arr[i]] = true; 
		n = 0; 
		for (int i = 0; i < m; i++)
		{
			if (!app[i])
				arr[n++] = i; 
		}
		work(); 
		if (fst != -1)
			fst = (fst + d * n % m) % m; 
	}
	if (fst == -1)
		printf("-1\n");
	else
		printf("%lld %lld\n", fst, d);
	return 0; 
}