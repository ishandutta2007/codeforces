#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[200000];
vector<int>ko[200000];
int par[200000];
int dp1[200000];
int dp2[200000];
int isa1[200000];
int isa2[200000];
int dat[200000];
bool flag[200000];
int num, gen;
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			par[pat[node][i]] = node;
			dfs(pat[node][i]);
		}
	}
}
void calc1(int node,int med)
{
	bool f = (med <= dat[node]);
	for (int i = 0; i < ko[node].size(); i++)
	{
		calc1(ko[node][i], med);
		f &= isa1[ko[node][i]];
	}
	isa1[node] = f;
	int cnt = 0;
	int maxi = 0;
	for (int i = 0; i < ko[node].size(); i++)
	{
		if (isa1[ko[node][i]])cnt += dp1[ko[node][i]];
		else maxi = max(maxi, dp1[ko[node][i]]);
	}
	if (med <= dat[node])dp1[node] = cnt + maxi + 1;
	else dp1[node] = 0;
}
void calc2(int node, int med)
{
	if (med > dat[node])
	{
		for (int i = 0; i < ko[node].size(); i++)
		{
			isa2[ko[node][i]] = false;
			dp2[ko[node][i]] = 0;
			calc2(ko[node][i], med);
		}
	}
	else
	{
		int cnt = 0;
		int sum = 0, m1 = 0, m2 = 0;
		for (int i = 0; i < ko[node].size(); i++)
		{
			if (isa1[ko[node][i]])
			{
				cnt++;
				sum += dp1[ko[node][i]];
			}
			else
			{
				if (m1 < dp1[ko[node][i]])
				{
					m2 = m1;
					m1 = dp1[ko[node][i]];
				}
				else if (m2 < dp1[ko[node][i]])
				{
					m2 = dp1[ko[node][i]];
				}
			}
		}
		if (isa2[node])
		{
			cnt++;
			sum += dp2[node];
		}
		else
		{
			if (m1 < dp2[node])
			{
				m2 = m1;
				m1 = dp2[node];
			}
			else if (m2 < dp2[node])
			{
				m2 = dp2[node];
			}
		}
		for (int i = 0; i < ko[node].size(); i++)
		{
			if (isa1[ko[node][i]])
			{
				if (cnt == ko[node].size() + 1)isa2[ko[node][i]] = true;
				else isa2[ko[node][i]] = false;
				dp2[ko[node][i]] = sum - dp1[ko[node][i]] + 1 + m1;
			}
			else if (dp1[ko[node][i]] == m1)
			{
				if (cnt == ko[node].size())isa2[ko[node][i]] = true;
				else isa2[ko[node][i]] = false;
				dp2[ko[node][i]] = sum + 1 + m2;
			}
			else
			{
				if (cnt == ko[node].size())isa2[ko[node][i]] = true;
				else isa2[ko[node][i]] = false;
				dp2[ko[node][i]] = sum + 1 + m1;
			}
		}
		for (int i = 0; i < ko[node].size(); i++)calc2(ko[node][i], med);
	}
}
int main()
{
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &dat[i]);
	}
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	dfs(0);
	int beg = 0, end = 1000000;
	for (;;)
	{
		int med = (beg + end + 1) / 2;
		calc1(0, med);
		dp2[0] = 0;
		isa2[0] = true;
		calc2(0, med);
		int maxi = 0;
		for (int i = 0; i < num; i++)
		{
			int c = 0, m = 0;
			for (int j = 0; j < ko[i].size(); j++)
			{
				if (isa1[ko[i][j]])c += dp1[ko[i][j]];
				else m = max(m, dp1[ko[i][j]]);
			}
			if (isa2[i])c += dp2[i];
			else m = max(m, dp2[i]);
			if (dat[i] >= med)maxi = max(maxi, c + m + 1);
		}
		if (maxi < gen)
		{
			end = med - 1;
		}
		else
		{
			beg = med;
		}
		if (beg == end)break;
	}
	printf("%d\n", beg);
}