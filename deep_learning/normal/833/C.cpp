#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;  
int cnt[15], tmp[15], arrl[105], arrr[105]; 
bool flg; 
ll ans; 
inline int calc(int mask, int l, int r)
{
	if (l > r)
		return 0; 
	return (mask & ((1 << r + 1) - 1)) >> l; 
}
void dfs(int cur, int rem)
{
	if (cur == 10)
	{
		if (rem)
			return; 
		memcpy(tmp, cnt, sizeof(tmp)); 
		if (cnt[0] == 17 && cnt[1] == 1 && flg)
		{
			ans++; 
			return; 
		}
		int cur = 0; 
		for (int i = 0; i < 10; i++)
		{
			if (tmp[i])
				cur |= 1 << i; 
		}
		bool zero = false, diff = false; 
		for (int i = 17; i >= 0; i--)
		{
			if (diff)
			{
				if (calc(cur, arrl[i] + 1, 9))
				{
					ans++; 
					return; 
				}
			}
			else if (calc(cur, arrl[i] + 1, arrr[i] - 1))
			{
				ans++; 
				return; 
			}
			if (!tmp[arrl[i]])
			{
				zero = true; 
				break; 
			}
			if (!--tmp[arrl[i]])
				cur -= 1 << arrl[i]; 
			if (arrl[i] != arrr[i])
				diff = true; 
		}
		if (!zero)
		{
			ans++; 
			return; 
		}
		memcpy(tmp, cnt, sizeof(tmp)); 
		cur = 0; 
		for (int i = 0; i < 10; i++)
		{
			if (tmp[i])
				cur |= 1 << i; 
		}
		zero = false;
		diff = false; 
		for (int i = 17; i >= 0; i--)
		{
			if (diff)
			{
				if (calc(cur, 0, arrr[i] - 1))
				{
					ans++; 
					return; 
				}
			}
			if (!tmp[arrr[i]])
			{
				zero = true; 
				break; 
			}
			if (!--tmp[arrr[i]])
				cur -= 1 << arrr[i]; 
			if (arrl[i] != arrr[i])
				diff = true; 
		}
		if (!zero)
		{
			ans++; 
			return; 
		}
		return; 
	}
	for (int i = 0; i <= rem; i++)
	{
		cnt[cur] = i; 
		dfs(cur + 1, rem - i); 
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("833C.in", "r", stdin); 
#endif
	ll l, r; 
	scanf("%lld%lld", &l, &r); 
	if (l == r)
	{
		printf("1\n");
		return 0; 
	}
	if (r == 1000000000000000000ll)
	{
		r--; 
		flg = true; 
	}
	for (int i = 0; i < 18; i++)
	{
		arrl[i] = l % 10; 
		arrr[i] = r % 10; 
		l /= 10; 
		r /= 10; 
	}
	dfs(0, 18); 
	printf("%lld\n", ans);
	return 0; 
}