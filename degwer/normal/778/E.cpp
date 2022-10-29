#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
vector<int>sais(vector<int>vec)//1-origin0Y
{
	if (vec.empty())
	{
		vector<int>v;
		return v;
	}
	vector<int>dat;
	dat.resize(vec.size());
	dat[vec.size() - 1] = 0;
	for (int i = vec.size() - 2; i >= 0; i--)
	{
		if (vec[i]>vec[i + 1])dat[i] = 1;
		else if (vec[i]<vec[i + 1])dat[i] = 0;
		else dat[i] = dat[i + 1];
	}
	vector<vector<int> >sa;
	int maxi = 0;
	for (int i = 0; i<vec.size(); i++)maxi = max(maxi, vec[i]);
	sa.resize(maxi + 1);
	vector<int>vnum;
	vnum.resize(maxi + 1);
	for (int i = 0; i<vec.size(); i++)vnum[vec[i]]++;
	vector<bool>islms;
	islms.resize(vec.size());
	fill(islms.begin(), islms.end(), false);
	for (int i = 0; i <= maxi; i++)
	{
		sa[i].resize(vnum[i]);
		fill(sa[i].begin(), sa[i].end(), -1);
	}
	vector<int>pt1, pt2;
	pt1.resize(maxi + 1);
	pt2.resize(maxi + 1);
	for (int i = 0; i <= maxi; i++)
	{
		pt2[i] = vnum[i] - 1;
	}
	for (int i = vec.size() - 1; i >= 1; i--)
	{
		if ((dat[i - 1] == 1 && dat[i] == 0) || i == vec.size() - 1)
		{
			sa[vec[i]][pt2[vec[i]]--] = i;
			islms[i] = true;
		}
	}
	for (int i = 0; i <= maxi; i++)
	{
		for (int j = 0; j<vnum[i]; j++)
		{
			if (sa[i][j]>0)
			{
				if (dat[sa[i][j] - 1] == 1)
				{
					sa[vec[sa[i][j] - 1]][pt1[vec[sa[i][j] - 1]]++] = sa[i][j] - 1;
				}
			}
		}
	}
	for (int i = 1; i <= maxi; i++)
	{
		for (int j = pt2[i] + 1; j<vnum[i]; j++)sa[i][j] = -1;
		pt2[i] = vnum[i] - 1;
	}
	for (int i = maxi; i >= 0; i--)
	{
		for (int j = vnum[i] - 1; j >= 0; j--)
		{
			if (sa[i][j]>0)
			{
				if (dat[sa[i][j] - 1] == 0)
				{
					sa[vec[sa[i][j] - 1]][pt2[vec[sa[i][j] - 1]]--] = sa[i][j] - 1;
				}
			}
		}
	}
	vector<int>d;
	d.resize(vec.size());
	int cnt = 0;
	vector<int>bef;
	bef.push_back(0);
	bool fl = false;
	for (int i = 0; i <= maxi; i++)
	{
		for (int j = 0; j<vnum[i]; j++)
		{
			if (islms[sa[i][j]])
			{
				vector<int>zk;
				zk.push_back(vec[sa[i][j]]);
				for (int k = sa[i][j] + 1; k<vec.size(); k++)
				{
					zk.push_back(vec[k]);
					if (islms[k])break;
				}
				if (zk != bef)cnt++;
				else if (vec[sa[i][j]] != 0)fl = true;
				d[sa[i][j]] = cnt;
				bef = zk;
			}
		}
	}
	vector<int>vt;
	for (int i = 0; i<vec.size(); i++)if (islms[i])vt.push_back(d[i]);
	vector<int>gv;
	vector<int>nv;
	if (fl)
	{
		gv = sais(vt);
		vector<int>v;
		for (int i = 0; i<vec.size(); i++)
		{
			if (islms[i])v.push_back(i);
		}
		for (int i = 0; i<gv.size(); i++)
		{
			nv.push_back(v[gv[i]]);
		}
	}
	else
	{
		gv = vt;
		nv.resize(gv.size());
		int pt = 0;
		for (int i = 0; i<gv.size(); i++)
		{
			for (;;)
			{
				if (islms[pt])
				{
					nv[gv[i]] = pt;
					pt++;
					break;
				}
				pt++;
			}
		}
	}
	for (int i = 0; i <= maxi; i++)
	{
		fill(sa[i].begin(), sa[i].end(), -1);
		pt1[i] = 0;
		pt2[i] = vnum[i] - 1;
	}
	for (int i = nv.size() - 1; i >= 0; i--)
	{
		sa[vec[nv[i]]][pt2[vec[nv[i]]]--] = nv[i];
	}
	for (int i = 0; i <= maxi; i++)
	{
		for (int j = 0; j<vnum[i]; j++)
		{
			if (sa[i][j]>0)
			{
				if (dat[sa[i][j] - 1] == 1)
				{
					sa[vec[sa[i][j] - 1]][pt1[vec[sa[i][j] - 1]]++] = sa[i][j] - 1;
				}
			}
		}
	}
	for (int i = 1; i <= maxi; i++)
	{
		for (int j = pt2[i] + 1; j<vnum[i]; j++)sa[i][j] = -1;
		pt2[i] = vnum[i] - 1;
	}
	for (int i = maxi; i >= 0; i--)
	{
		for (int j = vnum[i] - 1; j >= 0; j--)
		{
			if (sa[i][j]>0)
			{
				if (dat[sa[i][j] - 1] == 0)
				{
					sa[vec[sa[i][j] - 1]][pt2[vec[sa[i][j] - 1]]--] = sa[i][j] - 1;
				}
			}
		}
	}
	vector<int>ret;
	for (int i = 0; i <= maxi; i++)
	{
		for (int j = 0; j<vnum[i]; j++)
		{
			ret.push_back(sa[i][j]);
		}
	}
	return ret;
}
vector<int>calclcp(vector<int>str, vector<int>sa)//lcp: SAi-1ilcp
{
	vector<int>rsa;
	rsa.resize(sa.size());
	for (int i = 0; i < sa.size(); i++)rsa[sa[i]] = i;
	vector<int>lcp;
	lcp.resize(sa.size());
	int now = 1;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (now != 0)now--;
		for (;;)
		{
			if (str[i + now] == str[sa[rsa[i] - 1] + now])now++;
			else
			{
				lcp[rsa[i]] = now;
				break;
			}
		}
	}
	return lcp;
}
vector<int>str, sa, lcp, rsa;
void init(string s)
{
	for (int i = 0; i < s.size(); i++)str.push_back(s[i] - '0' + 1);
	str.push_back(0);
	sa = sais(str);
	lcp = calclcp(str, sa);
	rsa.resize(sa.size());
	for (int i = 0; i < sa.size(); i++)rsa[sa[i]] = i;
}
string dat[2000];
vector<int>ord[2000];
int cst[10];
int dp[2000][2000];
int pos[2000][10];
int r1[2000], r2[2000];
int main()
{
	string mok;
	cin >> mok;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)cin >> dat[i];
	for (int i = 0; i < num; i++)
	{
		reverse(dat[i].begin(), dat[i].end());
		for (int j = dat[i].size(); j < mok.size(); j++)dat[i].push_back('0');
		reverse(dat[i].begin(), dat[i].end());
	}
	string zs;
	for (int i = 0; i < num; i++)zs += dat[i], zs.push_back('0' + 10);
	vector<int>toseg, todig;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= dat[i].size(); j++)toseg.push_back(i), todig.push_back(dat[i].size() - j);
		for (int j = 0; j < dat[i].size(); j++)pos[dat[i].size() - j][dat[i][j] - '0']++;
	}
	toseg.push_back(-1);
	todig.push_back(-1);
	init(zs);
	for (int i = 0; i < sa.size(); i++)
	{
		if (toseg[sa[i]] != -1)
		{
			ord[todig[sa[i]]].push_back(toseg[sa[i]]);
		}
	}
	for (int i = 0; i < 10; i++)scanf("%d", &cst[i]);
	for (int i = 0; i < 2000; i++)for (int j = 0; j < 2000; j++)dp[i][j] = -2100000000;
	dp[0][num] = 0;
	for (int i = 0; i < mok.size(); i++)
	{
		int c;
		if (mok[mok.size() - i - 1] == '?')c = -1;
		else c = mok[mok.size() - i - 1] - '0';
		//printf("%d\n", c);
		int now[10];
		for (int j = 0; j < 10; j++)now[j] = 0;
		for (int j = 0; j <= ord[i].size(); j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (c != -1 && c != k)continue;
				if (i == mok.size() - 1 && k == 0)continue;
				int to = 0, pls = 0;
				for (int l = 0; l < 10; l++)
				{
					if (k + l <= 8)to += pos[i + 1][l], pls += now[l] * cst[k + l] + (pos[i + 1][l] - now[l]) * cst[k + l + 1];
					else if (k + l == 9)to += now[l], pls += now[l] * cst[9] + (pos[i + 1][l] - now[l]) * cst[0];
					else pls += now[l] * cst[k + l - 10] + (pos[i + 1][l] - now[l]) * cst[k + l - 9];
				}
				//printf("::%d %d %d %d %d\n", i, j, k, to, pls);
				dp[i + 1][to] = max(dp[i + 1][to], dp[i][j] + pls);
			}
			if (j != ord[i].size())now[dat[ord[i][j]][dat[ord[i][j]].size() - i - 1] - '0']++;
		}
		//for (int j = 0; j <= num; j++)printf("%d ", dp[i + 1][j]); printf("\n");
	}
	for (int i = 0; i < num; i++)
	{
		int s = 0, t = 0;
		int up = 1;
		for (int j = mok.size(); j < dat[i].size(); j++)
		{
			int x = dat[i][dat[i].size() - 1 - j] - '0';
			s += cst[x];
			if (up)
			{
				t += cst[(x + 1) % 10];
				if (x != 9)up = 0;
			}
			else t += cst[x];
		}
		if (up)t += cst[1];
		r1[i] = s, r2[i] = t;
		//printf("%d %d\n", s, t);
	}
	int maxi = 0;
	for (int i = 0; i <= num; i++)
	{
		int s = dp[mok.size()][i];
		for (int j = 0; j < i; j++)s += r1[ord[mok.size()][j]];
		for (int j = i; j < num; j++)s += r2[ord[mok.size()][j]];
		maxi = max(maxi, s);
	}
	printf("%d\n", maxi);
}