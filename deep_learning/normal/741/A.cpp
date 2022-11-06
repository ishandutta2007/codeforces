#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
int nxt[128], cnt[128]; 
bool vis[128]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("741A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", nxt + i); 
		nxt[i]--; 
		cnt[nxt[i]]++; 
	}
	for (int i = 0; i < n; i++)
	{
		if (!cnt[i])
		{
			printf("-1\n");
			return 0; 
		}
	}
	ll ans = 1; 
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue; 
		int x = i, cnt = 0; 
		while (!vis[x])
		{
			cnt++; 
			vis[x] = true; 
			x = nxt[x]; 
		}
		if (!(cnt & 1))
			cnt >>= 1;
		ans = ans / __gcd(ans, (ll)cnt) * cnt; 
	}
	printf("%lld\n", ans);
	return 0; 
}