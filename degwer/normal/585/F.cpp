#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class trie
{
public:
	int nex[30000][10];
	bool isst[30000];
	int fail[30000];
	int pt;
	void init()
	{
		pt = 1;
		fill(nex[0], nex[0] + 10, -1);
		isst[0] = false;
	}
	void addstr(string s)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nex[now][s[i] - '0'] == -1)
			{
				fill(nex[pt], nex[pt] + 10, -1);
				isst[pt] = false;
				nex[now][s[i] - '0'] = pt++;
			}
			now = nex[now][s[i] - '0'];
		}
		isst[now] = true;
	}
	vector<int>vec;
	void makefail(int node)
	{
		for (int i = 1; i <= vec.size(); i++)
		{
			int now = 0;
			bool flag = true;
			for (int j = i; j < vec.size(); j++)
			{
				if (nex[now][vec[j]] == -1)
				{
					flag = false;
					break;
				}
				now = nex[now][vec[j]];
			}
			if (flag)
			{
				fail[node] = now;
				break;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (nex[node][i] != -1)
			{
				vec.push_back(i);
				makefail(nex[node][i]);
				vec.pop_back();
			}
		}
	}
};
trie tr;
typedef long long ll;
ll mod = 1000000007;
ll dp[51][30000][2];
ll calc(string s, int mode)
{
	for (int i = 0; i <= 50; i++)for (int j = 0; j < 30000; j++)for (int k = 0; k < 2; k++)dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < tr.pt; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				int now = j;
				int nx;
				for (;;)
				{
					if (tr.nex[now][k] == -1)
					{
						if (now != 0)now = tr.fail[now];
						else
						{
							nx = 0;
							break;
						}
					}
					else
					{
						nx = tr.nex[now][k];
						break;
					}
				}
				if (tr.isst[nx])continue;
				dp[i + 1][nx][1] += dp[i][j][1];
				dp[i + 1][nx][1] %= mod;
				if (k < s[i] - '0')
				{
					dp[i + 1][nx][1] += dp[i][j][0];
					dp[i + 1][nx][1] %= mod;
				}
				else if (k == s[i] - '0')
				{
					dp[i + 1][nx][0] += dp[i][j][0];
					dp[i + 1][nx][0] %= mod;
				}
			}
		}
	}
	ll sa = 0, sb = 0;
	for (int j = 0; j < tr.pt; j++)
	{
		sa += dp[s.size()][j][0];
		sb += dp[s.size()][j][1];
	}
	if (mode == 1)return (sa + sb) % mod;
	else return sb%mod;
}
int main()
{
	string str;
	cin >> str;
	string sl, su;
	cin >> sl >> su;
	int len = sl.size() / 2;
	tr.init();
	for (int i = 0; i < int(str.size()) - len + 1; i++)
	{
		string s;
		for (int j = 0; j < len; j++)s.push_back(str[i + j]);
		tr.addstr(s);
	}
	tr.makefail(0);
	ll ra = calc(su, 1), rb = calc(sl, 0);
	ll ta = 0, tb = 0;
	for (int i = 0; i < sl.size(); i++)
	{
		ta *= 10;
		tb *= 10;
		ta += su[i] - '0';
		tb += sl[i] - '0';
		ta %= mod;
		tb %= mod;
	}
	printf("%I64d\n", (ta - ra + mod + mod - tb + rb + 1) % mod);
}