#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll d[101010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	string s;
	cin >> s;
	ll r1 = 0, r2 = 0;
	bool f1 = false, f2 = false;
	ll ans = 0;
	for (int i = 0; i < num; i++)
	{
		if (s[i] == 'W')r1 += d[i] * 2, f1 = true;
		if (s[i] == 'G')r2 += d[i] * 2, f2 = true;
		ans += d[i];
		ll rem = d[i];
		if (rem > 0 && r1 > 0)
		{
			ll x = min(rem, r1);
			ans += x, rem -= x, r1 -= x;
		}
		if (rem > 0 && r2 > 0)
		{
			ll x = min(rem, r2);
			ans += x * 2, rem -= x, r2 -= x;
		}
		if (rem > 0 && f1)
		{
			ans += rem * 3, rem = 0;
		}
		if (rem > 0 && f2)
		{
			ans += rem * 5, rem = 0;
		}
	}
	printf("%I64d\n", ans);
}