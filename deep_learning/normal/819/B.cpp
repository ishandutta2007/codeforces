#include <bits/stdc++.h>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
int arr[1000005], app[10000005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("819B.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n);
	ll ans = 1e18, sum = 0; 
	int pos, cnt = 0, cur = -1; 
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", arr + i); 
		cnt += arr[i] - i <= cur; 
		if (arr[i] - i >= 0)
			app[arr[i] - i]++; 
		sum += my_abs(arr[i] - i); 
	}
	ans = sum; 
	pos = 0; 
	for (int i = 2; i <= n; i++)
	{
		cur++; 
		cnt += app[cur]; 
		cnt--; 
		if (arr[n + 2 - i] - (n + 2 - i) >= 0)
			app[arr[n + 2 - i] - (n + 2 - i)]--;
		app[arr[n + 2 - i] + cur]++; 
		sum -= n - arr[n + 2 - i]; 
		sum += arr[n + 2 - i] - 1; 
		sum += cnt; 
		sum -= n - 1 - cnt; 
		if (sum < ans)
		{
			ans = sum; 
			pos = i - 1; 
		}
	}
	printf("%lld %d\n", ans, pos);
	return 0; 
}