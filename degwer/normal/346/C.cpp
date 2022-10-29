#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
ll d[100000];
ll dat[2000000];
int main()
{
	int num;
	scanf("%I64d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	set<ll>se;
	for (int i = 0; i < num; i++)
	{
		if (se.find(d[i]) != se.end())continue;
		se.insert(d[i]);
		for (ll x = (b + d[i] - 1) / d[i]; x <= a / d[i]; x++)
		{
			dat[min(a, x*d[i] + d[i] - 1) - b] = max(dat[min(a, x*d[i] + d[i] - 1) - b], min(a, x*d[i] + d[i] - 1) - x*d[i]);
		}
	}
	for (int i = a - b - 1; i >= 0; i--)dat[i] = max(dat[i], dat[i + 1] - 1);
	int cnt = 0;
	ll now = a;
	for (;;)
	{
		if (now == b)break;
		cnt++;
		if (dat[now - b] == 0)now--;
		else now -= dat[now - b];
	}
	printf("%d\n", cnt);
}