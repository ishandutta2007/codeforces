#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int, int>pii;
class trie
{
public:
	int nxt[300][21];
	int cst[300];
	int fail[300];//failure link
	int fc[300];//failure linkvRXg
	int pt;
	void init()
	{
		pt = 1;
		fill(nxt[0], nxt[0] + 21, -1);
	}
	void add(vector<int>s, int t)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nxt[now][s[i]] == -1)
			{
				fill(nxt[pt], nxt[pt] + 21, -1);
				nxt[now][s[i]] = pt++;
			}
			now = nxt[now][s[i]];
		}
		cst[now] += t;
	}
	void makefail(vector<int>s)
	{
		int zz = 0;
		for (int i = 0; i < s.size(); i++)zz = nxt[zz][s[i]];
		int c = 0;
		for (int i = 0; i < s.size(); i++)
		{
			bool f = true;
			int now = 0;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (nxt[now][s[j]] == -1)
				{
					f = false;
					break;
				}
				now = nxt[now][s[j]];
				c += cst[now];
			}
			if (f)
			{
				fail[zz] = now;
				fc[zz] = c;
				break;
			}
		}
	}
	void dfs(int node, vector<int>s)//add(0,"")failure link
	{
		for (int i = 0; i < 21; i++)
		{
			if (nxt[node][i] != -1)
			{
				s.push_back(i);
				makefail(s);
				dfs(nxt[node][i], s);
				s.pop_back();
			}
		}
	}
	pii getnext(int n, int k)//node nkJ
	{
		if (nxt[n][k] == -1)
		{
			int x = 0;
			int c = 0;
			for (;;)
			{
				c += fc[n];
				n = fail[n];
				if (nxt[n][k] != -1)
				{
					x = nxt[n][k];
					c += cst[x];
					break;
				}
				if (n == 0)break;
			}
			return make_pair(x, c);
		}
		else
		{
			int x = nxt[n][k];
			return make_pair(x, cst[x]);
		}
	}
};
trie tr;
typedef long long ll;
ll mod = 1000000007;
vector<int>read()
{
	vector<int>r;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int z;
		scanf("%d", &z);
		r.push_back(z);
	}
	return r;
}
vector<int>dat[200];
int cst[200];
pii ans[300][21];
ll dp[210][210][510][2];
ll calc(vector<int>v, int bas, int gen)
{
	for (int i = 0; i < v.size() + 1;i++)for (int j = 0; j < tr.pt; j++)for (int k = 0; k <= gen; k++)dp[i][j][k][0] = dp[i][j][k][1] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < tr.pt; j++)
		{
			for (int k = 0; k <= gen; k++)
			{
				if (dp[i][j][k][0] + dp[i][j][k][1] == 0)continue;
				for (int l = 0; l < bas; l++)
				{
					if (k + ans[j][l].second <= gen)
					{
						dp[i + 1][ans[j][l].first][k + ans[j][l].second][1] += dp[i][j][k][1];
						dp[i + 1][ans[j][l].first][k + ans[j][l].second][1] %= mod;
						if (dp[i][j][k][0] == 0)continue;
						if (l < v[i])
						{
							dp[i + 1][ans[j][l].first][k + ans[j][l].second][1] += dp[i][j][k][0];
							dp[i + 1][ans[j][l].first][k + ans[j][l].second][1] %= mod;
						}
						else if (l == v[i])
						{
							dp[i + 1][ans[j][l].first][k + ans[j][l].second][0] += dp[i][j][k][0];
							dp[i + 1][ans[j][l].first][k + ans[j][l].second][0] %= mod;
						}
					}
				}
			}
		}
		for (int l = 1; l < bas; l++)
		{
			if (ans[0][l].second <= gen)
			{
				if (i == 0 && l == v[0])dp[i + 1][ans[0][l].first][ans[0][l].second][0]++, dp[i + 1][ans[0][l].first][ans[0][l].second][0] %= mod;
				else if ((i == 0 && l < v[0]) || (i != 0))dp[i + 1][ans[0][l].first][ans[0][l].second][1]++, dp[i + 1][ans[0][l].first][ans[0][l].second][1] %= mod;
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < tr.pt; i++)for (int j = 0; j <= gen; j++)if (j + ans[i][bas].second <= gen)sum += dp[v.size()][i][j][0] + dp[v.size()][i][j][1];
	//cout << sum << " "<<v.size()<<endl;
	return sum%mod;
}
int main()
{
	int num, bas, gen;
	scanf("%d%d%d", &num, &bas, &gen);
	vector<int>v1 = read(), v2 = read();
	for (int i = 0; i < num; i++)dat[i] = read(), scanf("%d", &cst[i]);
	tr.init();
	for (int i = 0; i < num; i++)tr.add(dat[i], cst[i]);
	vector<int>ddd;
	tr.dfs(0, ddd);
	for (int i = 0; i < tr.pt; i++)for (int j = 0; j < bas + 1; j++)ans[i][j] = tr.getnext(i, j);
	/*for (int i = 0; i < tr.pt; i++)
	{
		for (int j = 0; j < bas + 1; j++)printf("%d %d  ", ans[i][j].first, ans[i][j].second);
		printf("\n");
	}*/
	v1[v1.size() - 1]--;
	for (int i = v1.size() - 1; i >= 1; i--)
	{
		if (v1[i] >= 0)break;
		v1[i] = bas - 1;
		v1[i - 1]--;
	}
	if (v1[0] == 0)
	{
		reverse(v1.begin(), v1.end());
		v1.pop_back();
		reverse(v1.begin(), v1.end());
	}
	printf("%I64d\n", (calc(v2, bas, gen) + mod - calc(v1, bas, gen)) % mod);
}