#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
bool flag[200001];
ll dat[200001];
int main()
{
	int num;
	ll gen;
	scanf("%d%I64d", &num, &gen);
	vector<ll>vec;
	for (int i = 0; i <= num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	ll now = 0;
	fill(flag, flag + num + 1, false);
	for (int i = 0; i <= num; i++)
	{
		flag[i] = true;
		now += vec[i];
		dat[i] = now;
		if (now % 2 != 0)break;
		now /= 2;
	}
	now = 0;
	int ans = 0;
	for (int i = num; i >= 0; i--)
	{
		if (abs(vec[i] - (dat[i] + now)) <= gen && flag[i])
		{
			if (i != num || vec[i] != dat[i] + now)
			{
				ans++;
			}
		}
		now += vec[i];
		now *= 2;
		if (abs(now) > 1145141919810893334LL)break;
	}
	printf("%d\n", ans);
}