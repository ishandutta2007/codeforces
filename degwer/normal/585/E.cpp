#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool ispr[10000001];
vector<int>dat[500000];
int pt[10000001];
int cnt[10000001];
int sfr[10000001];
int ans[10000001];
bool gk[10000001];
typedef long long ll;
ll mod = 1000000007;
ll p2[1000001];
int main()
{
	fill(sfr, sfr + 10000001, 1);
	fill(ispr, ispr + 10000001, true);
	fill(gk, gk + 10000001, false);
	for (int i = 2; i <= 10000000; i++)
	{
		if (ispr[i])
		{
			for (int j = i; j <= 10000000; j += i)
			{
				if (j > i)ispr[j] = false;
				sfr[j] *= i;
				gk[j] ^= true;
			}
		}
	}
	int num;
	scanf("%d", &num);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(sfr[z]);
		cnt[sfr[z]]++;
	}
	sort(vec.begin(), vec.end());
	for (int i = 2; i <= 10000000; i++)
	{
		if (ispr[i])
		{
			for (int j = i; j <= 10000000; j += i)
			{
				if (cnt[j] > 0)
				{
					int low = lower_bound(vec.begin(), vec.end(), j) - vec.begin();
					dat[low].push_back(i);
				}
			}
		}
	}
	p2[0] = 1;
	for (int i = 1; i <= 1000000; i++)p2[i] = (p2[i - 1] * 2) % mod;
	for (int i = 1; i <= 10000000; i++)
	{
		if (cnt[i] > 0)
		{
			int low = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
			for (int p = 0; p < (1 << dat[low].size()); p++)
			{
				int t = 1;
				for (int j = 0; j < dat[low].size(); j++)
				{
					if (p&(1 << j))t *= dat[low][j];
				}
				ans[t] += cnt[i];
			}
		}
	}
	/*for (int i = 1; i <= 100; i++)
	{
		if (sfr[i] == i)printf("%d %d\n", i, ans[i]);
	}*/
	ll kou = (p2[num] - 1);
	for (int i = 1; i <= 10000000; i++)
	{
		if (sfr[i] != i)continue;
		if (!gk[i])kou += mod - (p2[ans[i]] - 1);
		else kou += (p2[ans[i]] - 1);
		kou %= mod;
	}
	ll ret = 0;
	for (int i = 0; i < num; i++)
	{
		int t = sfr[vec[i]];
		int low = lower_bound(vec.begin(), vec.end(), t) - vec.begin();
		ll r = kou;
		for (int p = 1; p < (1 << dat[low].size()); p++)
		{
			int s = 1;
			int c = 0;
			for (int j = 0; j < dat[low].size(); j++)
			{
				if (p&(1 << j))s *= dat[low][j], c++;
			}
			if (c % 2 == 0)r += (p2[ans[s]] - 1);
			else r += mod - (p2[ans[s]] - 1);
		}
		ret += r;
		ret %= mod;
	}
	printf("%I64d\n", ret);
}