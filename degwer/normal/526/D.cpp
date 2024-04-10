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
#define SIZE 1048576
class segtree
{
public:
	int seg[SIZE * 2];
	void init(vector<int>v)
	{
		for (int i = 1; i < SIZE * 2; i++)seg[i] = 1000000000;
		for (int i = 0; i < v.size(); i++)seg[SIZE + i] = v[i];
		for (int i = SIZE - 1; i >= 0; i--)seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
	void update(int a, int b)
	{
		a += SIZE;
		seg[a] = min(seg[a], b);
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a + a], seg[a + a + 1]);
		}
	}
	int get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return 1000000000;
		if (beg <= lb&&ub <= end)return seg[node];
		return min(get(beg, end, node * 2, lb, (lb + ub) >>1), get(beg, end, node * 2 + 1, ((lb + ub) >>1) + 1, ub));
	}
};
segtree tree;
vector<int>str, sa, lcp, rsa;
void init(string s)
{
	for (int i = 0; i < s.size(); i++)str.push_back(s[i] - 'a' + 1);
	str.push_back(0);
	sa = sais(str);
	lcp = calclcp(str, sa);
	tree.init(lcp);
	rsa.resize(sa.size());
	for (int i = 0; i < sa.size(); i++)rsa[sa[i]] = i;
}
int getlcp(int a, int b)//ablcp
{
	return tree.get(min(rsa[a], rsa[b]) + 1, max(rsa[a], rsa[b]), 1, 0, SIZE - 1);
}
int imos[2000001];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	string s;
	cin >> s;
	for (int i = 0; i < 10; i++)s.push_back('z' + 1);
	init(s);
	string ans;
	for (int i = 0; i <= num; i++)ans.push_back('0');
	for (int i = 0; i <= num; i += gen)
	{
		bool f = true;
		int t = i / gen;
		for (int j = 0; j < gen; j++)
		{
			if (getlcp(j*t, 0) < t)
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			int x = getlcp(i, 0);
			if (x > t)x = t;
			imos[i]++;
			imos[i + x + 1]--;
		}
	}
	for (int i = 0; i < num; i++)imos[i + 1] += imos[i];
	for (int i = 1; i <= num; i++)printf("%d", int(imos[i] > 0));
	printf("\n");
}