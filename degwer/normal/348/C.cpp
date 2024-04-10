#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define B 320
#define NB 320
typedef long long ll;
ll arr[100000];
vector<ll>dat[100000];
vector<ll>ist[100000];
ll beg[100000];
ll ans[100000];
ll add[100000];
int main()
{
	int len, num, query;
	scanf("%d%d%d", &len, &num, &query);
	for (int i = 0; i < len; i++)scanf("%I64d", &arr[i]);
	for (int i = 0; i < num; i++)
	{
		int zn;
		scanf("%d", &zn);
		for (int j = 0; j < zn; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			dat[i].push_back(z);
			beg[i] += arr[z];
		}
	}
	vector<int>ind;
	for (int i = 0; i < num; i++)
	{
		if (dat[i].size() >= B)
		{
			vector<int>v;
			v.resize(len);
			for (int j = 0; j < dat[i].size(); j++)v[dat[i][j]] = 1;
			for (int j = 0; j < num; j++)
			{
				int cnt = 0;
				for (int k = 0; k < dat[j].size(); k++)cnt += v[dat[j][k]];
				ist[j].push_back(cnt);
			}
			ind.push_back(i);
		}
	}
	for (int p = 0; p < query; p++)
	{
		char za;
		int zb;
		scanf(" %c%d", &za, &zb);
		zb--;
		if (za == '?')
		{
			if (dat[zb].size() >= B)printf("%I64d\n", beg[zb] + ans[zb]);
			else
			{
				ll sum = 0;
				for (int i = 0; i < dat[zb].size(); i++)sum += arr[dat[zb][i]];
				for (int i = 0; i < ist[zb].size(); i++)sum += add[ind[i]] * ist[zb][i];
				printf("%I64d\n", sum);
			}
		}
		else
		{
			ll zc;
			scanf("%I64d", &zc);
			for (int i = 0; i < ist[zb].size(); i++)ans[ind[i]] += zc*ist[zb][i];
			if (dat[zb].size() >= B)add[zb] += zc;
			else for (int i = 0; i < dat[zb].size(); i++)arr[dat[zb][i]] += zc;
		}
	}
}