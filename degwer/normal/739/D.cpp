#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
int get(string s)
{
	if (s == "?")return 400;
	int t = 0;
	for (int i = 0; i < s.size(); i++)t = t * 10 + s[i] - '0';
	return t;
}
typedef pair<int, int>pii;
vector<int>dat[500][500];
vector<int>fr;
vector<int>zdat[500][500];
vector<int>zfr;
int ans[300];
#define SIZE 1000
vector<int>pat[SIZE];
vector<int>cap[SIZE];
vector<int>rev[SIZE];
void adde(int a, int b, int c)
{
	pat[a].push_back(b);
	pat[b].push_back(a);
	cap[a].push_back(c);
	cap[b].push_back(0);
	rev[a].push_back(pat[b].size() - 1);
	rev[b].push_back(pat[a].size() - 1);
}
int frv[SIZE], fre[SIZE];
bool flag[SIZE];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i<pat[node].size(); i++)
	{
		if (cap[node][i]>0 && (!flag[pat[node][i]]))
		{
			frv[pat[node][i]] = node;
			fre[pat[node][i]] = i;
			dfs(pat[node][i]);
		}
	}
}
int nod;
int maxflow(int st, int go)
{
	int ret = 0;
	for (;;)
	{
		fill(flag, flag + nod, false);
		dfs(st);
		if (!flag[go])return ret;
		int mini = 1000000000;
		int now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			now = frv[now];
			mini = min(mini, cap[now][t]);
		}
		ret += mini;
		//flow++;
		now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			int nx = now;
			now = frv[now];
			cap[now][t] -= mini;
			cap[nx][rev[now][t]] += mini;
		}
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	int mmxx = 0;
	for (int i = 0; i < num; i++)
	{
		string za, zb;
		cin >> za >> zb;
		int a = get(za), b = get(zb);
		if (a < 400 || b < 400)zdat[b][a].push_back(i);
		else zfr.push_back(i);
		if (b < 400 && a < 400)mmxx = max(mmxx, a);
	}
	vector<pii>adv;
	for (int i = mmxx + 1; i <= num; i++)
	{
		for (int j = 0; j < zdat[400][i].size(); i++)
		{
			adv.push_back(make_pair(i, zdat[400][i][j]));
		}
		zdat[400][i].clear();
	}
	//for (int i = 0; i < adv.size(); i++)printf("....%d %d\n", adv[i].first,adv[i].second);
	for (int p = 1; p <= num; p++)
	{
		for (int i = 0; i < 500; i++)for (int j = 0; j < 500;j++)dat[i][j] = zdat[i][j];
		fr = zfr;
		int sum = 0;
		for (int i = 0; i < 500; i++)sum += dat[p][i].size();
		for (int i = 0; i < adv.size(); i++)dat[p][adv[i].first].push_back(adv[i].second);
		vector<pii>nee;
		for (int i = 1; i <= num; i++)
		{
			int s = 0;
			for (int j = 0; j < 500; j++)s += dat[i][j].size();
			if (s == 0)continue;
			int maxi = 0;
			for (int j = 1; j <= num; j++)if (dat[i][j].size() > 0)maxi = j;
			for (int j = 1; j <= maxi; j++)if (dat[i][j].size() == 0)nee.push_back(make_pair(i, j));
			int x = max(1, int(dat[i][0].size() + i - 1) / i)*i;
			for (int j = 0; j < x - dat[i][0].size(); j++)nee.push_back(make_pair(i, 0));
		}
		if (nee.size() > num)continue;
		for (int i = 0; i < SIZE; i++)
		{
			pat[i].clear();
			rev[i].clear();
			cap[i].clear();
		}
		nod = SIZE;
		for (int i = 0; i < nee.size(); i++)
		{
			adde(i, nee[i].first + 330, 1);
			adde(i, nee[i].second + 660, 1);
		}
		for (int i = 0; i < nee.size(); i++)adde(998, i, 1);
		for (int i = 0; i <= num; i++)adde(i + 330, 999, dat[i][400].size());
		for (int i = 0; i <= num; i++)adde(i + 660, 999, dat[400][i].size());
		int ret = maxflow(998, 999);
		if (ret + fr.size() < nee.size())continue;
		//printf("%d:\n", p);
		for (int i = 0; i < nee.size(); i++)
		{
			//printf("   %d %d\n", nee[i].first, nee[i].second);
			bool f = false;
			for (int j = 0; j < pat[i].size(); j++)
			{
				if (pat[i][j] != 998 && cap[i][j] == 0)
				{
					if (pat[i][j] < 660)
					{
						dat[nee[i].first][nee[i].second].push_back(dat[nee[i].first][400][dat[nee[i].first][400].size() - 1]);
						dat[nee[i].first][400].pop_back();
					}
					else
					{
						dat[nee[i].first][nee[i].second].push_back(dat[400][nee[i].second][dat[400][nee[i].second].size() - 1]);
						dat[400][nee[i].second].pop_back();
					}
					f = true;
					break;
				}
			}
			if (!f)
			{
				dat[nee[i].first][nee[i].second].push_back(fr[fr.size() - 1]);
				fr.pop_back();
			}
		}
		for (int i = 0; i <= num; i++)
		{
			for (int j = 0; j < dat[i][400].size(); j++)dat[i][1].push_back(dat[i][400][j]);
			if (i != 0)for (int j = 0; j < dat[400][i].size(); j++)dat[p][i].push_back(dat[400][i][j]);
			else for (int j = 0; j < dat[400][i].size(); j++)dat[1][i].push_back(dat[400][i][j]);
		}
		for (int i = 0; i < fr.size(); i++)dat[1][0].push_back(fr[i]);
		//for (int i = 0; i <= num; i++)for (int j = 0; j <= num; j++)for (int k = 0; k < dat[i][j].size();k++)printf("%d %d %d\n", i, j, dat[i][j][k]);
		for (int i = 1; i <= num; i++)
		{
			for (int j = 0; j < dat[i][0].size(); j++)
			{
				ans[dat[i][0][j]] = dat[i][0][(j + 1) % i + (j / i)*i];
			}
			for (int j = 1; j <= num; j++)
			{
				for (int k = 0; k < dat[i][j].size(); k++)
				{
					if (dat[i][j - 1].size() == 0)
					{
						goto l01;
					}
					//printf(" %d %d\n", dat[i][j][k], dat[i][j - 1][0]);
					ans[dat[i][j][k]] = dat[i][j - 1][0];
				}
			}
		}
		for (int i = 0; i < num; i++)printf("%d ", ans[i] + 1);
		printf("\n");
		return 0;
	l01:;
	}
	printf("-1\n");
}