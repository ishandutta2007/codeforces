#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int>bun[1000001];
int dat[1000001];
typedef pair<int, int>pii;
int ans[1000001];
int rans[1000001];
int ko[1000001];
int sqf[1000001];
int tou[1000001];
ll mod = 1000000007;
int num;
int get(int t)
{
	if (t == 1)return 1;
	return num / t;
}
int main()
{
	scanf("%d", &num);
	for (int i = 2; i <= num; i++)
	{
		if (bun[i].empty())
		{
			for (int j = i; j <= num; j += i)
			{
				bun[j].push_back(i);
			}
		}
	}
	bun[1].push_back(1);
	for (int i = 1; i <= num; i++)
	{
		int t = 1;
		for (int j = 0; j < bun[i].size(); j++)t *= bun[i][j];
		sqf[i] = t;
		tou[t]++;
	}
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &dat[i]);
		tou[sqf[dat[i]]]--;
	}
	for (int i = 1; i <= num; i++)
	{
		if (dat[i] != 0)
		{
			if (bun[i].size() != bun[dat[i]].size())
			{
				printf("0\n");
				return 0;
			}
			for (int j = 0; j < bun[i].size(); j++)
			{
				if (get(bun[i][j]) != get(bun[dat[i]][j]))
				{
					printf("0\n");
					return 0;
				}
				if (ans[bun[i][j]] == 0 && rans[bun[dat[i]][j]] == 0)ans[bun[i][j]] = bun[dat[i]][j], rans[bun[dat[i]][j]] = bun[i][j];
				else if (ans[bun[i][j]] != bun[dat[i]][j])
				{
					printf("0\n");
					return 0;
				}
				else if (rans[bun[dat[i]][j]] != bun[i][j])
				{
					printf("0\n");
					return 0;
				}
			}
		}
	}
	for (int i = 1; i <= num; i++)
	{
		if (bun[i].size() == 1 && ans[i] == 0)
		{
			if (bun[i][0] == i)
			{
				ko[get(i)]++;
			}
		}
	}
	ll r = 1;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= ko[i]; j++)
		{
			r *= j;
			r %= mod;
		}
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= tou[i]; j++)
		{
			r *= j;
			r %= mod;
		}
	}
	printf("%I64d\n", r);
}