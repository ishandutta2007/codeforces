#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 900
#define NS 167
int now[150400];
int flag[NS];
int dat[NS][150400];
int cnt[150400];
void resolve(int a)
{
	if (flag[a] != -1)
	{
		for (int i = 0; i < SIZE; i++)
		{
			dat[a][now[a*SIZE + i]] = 0;
			now[a*SIZE + i] = flag[a];
		}
		dat[a][flag[a]] = SIZE;
		flag[a] = -1;
	}
}
void update(int lb, int ub, int n)
{
	int b1 = lb / SIZE, b2 = ub / SIZE;
	resolve(b1);
	resolve(b2);
	if (b1 == b2)
	{
		for (int i = lb; i <= ub; i++)
		{
			dat[b1][now[i]]--;
			now[i] = n;
			dat[b1][n]++;
		}
	}
	else
	{
		for (int i = lb; i < (b1 + 1)*SIZE; i++)
		{
			dat[b1][now[i]]--;
			now[i] = n;
			dat[b1][n]++;
		}
		for (int i = b1 + 1; i < b2; i++)
		{
			flag[i] = n;
		}
		for (int i = b2*SIZE; i <= ub; i++)
		{
			dat[b2][now[i]]--;
			now[i] = n;
			dat[b2][n]++;
		}
	}
}
int getv(int p)
{
	if (flag[p / SIZE] != -1)return flag[p / SIZE];
	else return now[p];
}
int countn(int lb, int ub, int num)
{
	int b1 = lb / SIZE, b2 = ub / SIZE;
	int ret = 0;
	if (b1 == b2)
	{
		resolve(b1);
		for (int i = lb; i <= ub; i++)
		{
			ret += (now[i] == num);
		}
		return ret;
	}
	else
	{
		if (flag[b1] == -1)
		{
			if (lb%SIZE < SIZE / 2)
			{
				ret += dat[b1][num];
				for (int i = b1*SIZE; i < lb; i++)ret -= (now[i] == num);
			}
			else
			{
				for (int i = lb; i < (b1 + 1)*SIZE; i++)
				{
					ret += (now[i] == num);
				}
			}
		}
		else if (flag[b1] == num)ret += SIZE - (lb - b1*SIZE);
		for (int i = b1 + 1; i < b2; i++)
		{
			if (flag[i] != -1)ret += SIZE * (flag[i] == num);
			else ret += dat[i][num];
		}
		if (flag[b2] == -1)
		{
			if (ub%SIZE < SIZE / 2)
			{
				for (int i = b2*SIZE; i <= ub; i++)
				{
					ret += (now[i] == num);
				}
			}
			else
			{
				ret += dat[b2][num];
				for (int i = ub + 1; i < (b2 + 1)*SIZE; i++)ret -= (now[i] == num);
			}
		}
		else if (flag[b2] == num)ret += ub - b2*SIZE + 1;
		return ret;
	}
}
long long rrr = 2463534242LL;
int getrand(int mod)
{
	rrr = (rrr ^ (rrr << 13))&((1LL << 32) - 1); rrr = rrr ^ (rrr >> 17);
	rrr = (rrr ^ (rrr << 5))&((1LL << 32) - 1);
	return rrr%mod;
}
typedef pair<int, int>pii;
int main()
{
	int num, query, gen;
	scanf("%d%d%d", &num, &query, &gen);
	fill(now, now + 150400, -1);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		now[i] = z;
		dat[i / SIZE][z]++;
	}
	fill(flag, flag + NS, -1);
	for (int p = 0; p < query; p++)
	{
		int z, za, zb;
		scanf("%d%d%d", &z, &za, &zb);
		za--; zb--;
		if (z == 1)
		{
			int zc;
			scanf("%d", &zc);
			zc--;
			update(za, zb, zc);
		}
		else
		{
			int vec[100];
			int pt = 0;
			for (int i = 0; i < 100; i++)
			{
				int t = getv(getrand(zb - za + 1) + za);
				vec[pt++] = t;
				cnt[t]++;
			}
			vector<pii>v;
			for (int i = 0; i < 100; i++)
			{
				if (cnt[vec[i]] >= 3)v.push_back(make_pair(-cnt[vec[i]], vec[i]));
				cnt[vec[i]] = 0;
			}
			sort(v.begin(), v.end());
			vector<int>ans;
			for (int i = 0; i < min(int(v.size()),8); i++)
			{
				int t = countn(za, zb, v[i].second);
				if (t * 100 >= (zb - za + 1)*gen)
				{
					ans.push_back(v[i].second);
				}
			}
			printf("%d", ans.size());
			for (int i = 0; i < ans.size(); i++)printf(" %d", ans[i] + 1);
			printf("\n");
		}
	}
}