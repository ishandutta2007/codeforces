#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
int dat[28];
vector<int>cm[28];
int g(int a)
{
	if (a == 0)return 0;
	if (a == 1)return 4;
	return 7;
}
void init()
{
	int pt = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			for (int k = j; k < 3; k++)
			{
				for (int l = k; l < 3; l++)
				{
					for (int m = l; m < 3; m++)
					{
						for (int n = m; n < 3; n++)
						{
							vector<int>t;
							t.push_back(g(i));
							t.push_back(g(j));
							t.push_back(g(k));
							t.push_back(g(l));
							t.push_back(g(m));
							t.push_back(g(n));
							cm[pt] = t;
							dat[pt++] = g(i) + g(j) + g(k) + g(l) + g(m) + g(n);
						}
					}
				}
			}
		}
	}
}
typedef long long ll;
int f1[21][6];
int f2[21][6];
bool dp[21][6];
vector<ll>calc(ll x)
{
	vector<int>v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < 21; i++)for (int j = 0; j < 6; j++)dp[i][j] = false;
	dp[0][0] = true;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (dp[i][j])
			{
				for (int k = 0; k < 28; k++)
				{
					if ((j + dat[k]) % 10 == v[i])
					{
						dp[i + 1][(j + dat[k]) / 10] = true;
						f1[i + 1][(j + dat[k]) / 10] = j;
						f2[i + 1][(j + dat[k]) / 10] = k;
					}
				}
			}
		}
	}
	vector<ll>ret;
	if (!dp[20][0])return ret;
	ret.resize(6);
	int now = 0;
	for (int i = 20; i > 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			ret[j] *= 10;
			ret[j] += cm[f2[i][now]][j];
		}
		now = f1[i][now];
	}
	return ret;
}
int main()
{
	init();
	int data;
	scanf("%d", &data);
	for (int p = 0; p < data; p++)
	{
		ll z;
		scanf("%I64d", &z);
		vector<ll>t = calc(z);
		if (t.empty())printf("-1\n");
		else
		{
			for (int i = 0; i < 6; i++)printf("%I64d ", t[i]); printf("\n");
		}
	}
}