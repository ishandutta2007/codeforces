#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
class trie
{
public:
	int nxt[210][26];
	int cst[210];
	int fail[210];
	int fc[210];
	int pt;
	void init()
	{
		pt = 1;
		fill(nxt[0], nxt[0] + 26, -1);
	}
	void add(string s, int t)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nxt[now][s[i] - 'a'] == -1)
			{
				fill(nxt[pt], nxt[pt] + 26, -1);
				nxt[now][s[i] - 'a'] = pt++;
			}
			now = nxt[now][s[i]-'a'];
		}
		cst[now] += t;
	}
	void makefail(string s)
	{
		int zz = 0;
		for (int i = 0; i < s.size(); i++)zz = nxt[zz][s[i] - 'a'];
		int c = 0;
		for (int i = 0; i < s.size(); i++)
		{
			bool f = true;
			int now = 0;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (nxt[now][s[j] - 'a'] == -1)
				{
					f = false;
					break;
				}
				now = nxt[now][s[j] - 'a'];
				c += cst[now];
			}
			if (f)
			{
				fail[zz] = now;
				fc[zz] = c;
			//	printf("%d %d %d\n", zz, now, c);
				break;
			}
		}
	}
	void dfs(int node, string s)
	{
		for (int i = 0; i < 26; i++)
		{
			if (nxt[node][i] != -1)
			{
				s.push_back('a' + i);
			//	cout << s << " " << nxt[node][i] << endl;
				makefail(s);
				dfs(nxt[node][i], s);
				s.pop_back();
			}
		}
	}
};
trie tr;
ll dp[50][210][210];
ll cc[200];
int main()
{
	int num;
	ll gen;
	scanf("%d%I64d", &num, &gen);
	for (int i = 0; i < num; i++)scanf("%I64d", &cc[i]);
	vector<string>vec;
	tr.init();
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
		tr.add(s, cc[i]);
	}
	tr.dfs(0, "");
	for (int i = 0; i < 50; i++)for (int j = 0; j < tr.pt; j++)for (int k = 0; k < tr.pt; k++)dp[i][j][k] = -4000000000000000000LL;
	for (int i = 0; i < tr.pt; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			int now = i;
			int c = 0;
			for (;;)
			{
				if (tr.nxt[now][j] != -1)
				{
					now = tr.nxt[now][j];
					c += tr.cst[now];
					break;
				}
				if (now == 0)break;
				c += tr.fc[now];
				now = tr.fail[now];
			}
			dp[0][i][now] = c;
			//if(now!=0)printf("%d %d  %d\n", i, now, c);
		}
	}
	for (int i = 1; i < 50; i++)
	{
		for (int j = 0; j < tr.pt; j++)
		{
			for (int k = 0; k < tr.pt; k++)
			{
				for (int l = 0; l < tr.pt; l++)
				{
					dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][k] + dp[i - 1][k][l]);
				}
			}
		}
	}
	ll now[210];
	fill(now, now + 210, -4000000000000000000LL);
	now[0] = 0;
	for (int i = 0; i < 50; i++)
	{
		if (gen&(1LL << i))
		{
			ll n[210];
			fill(n, n + 210, -4000000000000000000LL);
			for (int j = 0; j < tr.pt; j++)
			{
				for (int k = 0; k < tr.pt; k++)
				{
					n[k] = max(n[k], now[j] + dp[i][j][k]);
				}
			}
			for (int j = 0; j < tr.pt; j++)now[j] = n[j];
		}
	}
	ll maxi = 0;
	for (int i = 0; i < tr.pt; i++)
	{
		int t = i;
		for (;;)
		{
			if (t == 0)break;
			now[i] += tr.fc[t];
			t = tr.fail[t];
		}
		maxi = max(maxi, now[i]);
	}
	printf("%I64d\n", maxi);
}