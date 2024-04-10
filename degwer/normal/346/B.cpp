#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
class trie
{
public:
	int nxt[100000][27];
	int cst[100000];
	int fail[100000];//failure link
	int fc[100000];//failure linkvRXg
	int pt;
	void init()
	{
		pt = 1;
		fill(nxt[0], nxt[0] + 27, -1);
	}
	void add(string s, int t)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nxt[now][s[i] - 'A'] == -1)
			{
				fill(nxt[pt], nxt[pt] + 27, -1);
				nxt[now][s[i] - 'A'] = pt++;
			}
			now = nxt[now][s[i] - 'A'];
		}
		cst[now] += t;
	}
	void makefail(string s)
	{
		int zz = 0;
		for (int i = 0; i < s.size(); i++)zz = nxt[zz][s[i] - 'A'];
		int c = 0;
		for (int i = 0; i < s.size(); i++)
		{
			bool f = true;
			int now = 0;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (nxt[now][s[j] - 'A'] == -1)
				{
					f = false;
					break;
				}
				now = nxt[now][s[j] - 'A'];
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
	void dfs(int node, string s)//add(0,"")failure link
	{
		for (int i = 0; i < 27; i++)
		{
			if (nxt[node][i] != -1)
			{
				s.push_back('A' + i);
				makefail(s);
				dfs(nxt[node][i], s);
				s.pop_back();
			}
		}
	}
	pii getnext(int n, char k)//node nkJ
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
int dp[102][102][102];
int fx[102][102][102], fy[102][102][102], fk[102][102][102];
char fl[102][102][102];
int nxt[102][27];
int main()
{
	string sa, sb, fbd;
	cin >> sa >> sb >> fbd;
	tr.init();
	tr.add(fbd, 1);
	tr.dfs(0, "");
	for (int i = 0; i < tr.pt; i++)for (int j = 0; j < 27; j++)nxt[i][j] = tr.getnext(i, j).first;
	int maxi = 0, x, y, n;
	for (int i = 0; i < sa.size(); i++)
	{
		for (int j = 0; j < sb.size(); j++)
		{
			for (int k = 0; k < tr.pt - 1; k++)
			{
				if (dp[i + 1][j][k] < dp[i][j][k])
				{
					dp[i + 1][j][k] = dp[i][j][k];
					fx[i + 1][j][k] = i;
					fy[i + 1][j][k] = j;
					fk[i + 1][j][k] = k;
					fl[i + 1][j][k] = ' ';
				}
				if (dp[i][j + 1][k] < dp[i][j][k])
				{
					dp[i][j + 1][k] = dp[i][j][k];
					fx[i][j + 1][k] = i;
					fy[i][j + 1][k] = j;
					fk[i][j + 1][k] = k;
					fl[i][j + 1][k] = ' ';
				}
				if (sa[i] == sb[j])
				{
					int t = nxt[k][sa[i] - 'A'];
					//printf("%d %c %d\n", k, sa[i], t);
					if (t != tr.pt - 1 && dp[i + 1][j + 1][t] < dp[i][j][k] + 1)
					{
						dp[i + 1][j + 1][t] = dp[i][j][k] + 1;
						fx[i + 1][j + 1][t] = i;
						fy[i + 1][j + 1][t] = j;
						fk[i + 1][j + 1][t] = k;
						fl[i + 1][j + 1][t] = sa[i];
						if (maxi < dp[i + 1][j + 1][t])
						{
							maxi = dp[i + 1][j + 1][t];
							x = i + 1, y = j + 1, n = t;
						}
					}
				}
			}
		}
	}
	if (maxi == 0)printf("0\n");
	else
	{
		string ans;
		for (;;)
		{
			if (ans.size() == maxi)break;
			int zx = fx[x][y][n], zy = fy[x][y][n], zk = fk[x][y][n];
			if (fl[x][y][n] != ' ')ans.push_back(fl[x][y][n]);
			x = zx, y = zy, n = zk;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}