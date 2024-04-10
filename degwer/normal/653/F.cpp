#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
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
#define SIZE 524288
class segtree
{
public:
	int seg[SIZE * 2];
	void init()
	{
		for (int i = 1; i < SIZE * 2; i++)seg[i] = 1000000000;
	}
	void update(int a, int b)
	{
		a += SIZE;
		seg[a] = min(seg[a], b);
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	int get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return 1000000000;
		if (beg <= lb&&ub <= end)return seg[node];
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
vector<int>str, sa, lcp, rsa;
void init(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')str.push_back(1);
		else str.push_back(2);
	}
	str.push_back(0);
	sa = sais(str);
	lcp = calclcp(str, sa);
	tree.init();
	rsa.resize(sa.size());
	for (int i = 0; i < sa.size(); i++)rsa[sa[i]] = i;
	for (int i = 0; i < str.size(); i++)tree.update(i, lcp[i]);
}
int getlcp(int a, int b)//ablcp
{
	return tree.get(min(rsa[a], rsa[b]) + 1, max(rsa[a], rsa[b]), 1, 0, SIZE - 1);
}
map<int, vector<int> >ma;
segtree tree2;
int nex[20][500020];
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	init(s);
	tree2.init();
	ma[0].push_back(0);
	int now = 0;
	tree2.update(0, 0);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')now++;
		else now--;
		ma[now].push_back(i + 1);
		tree2.update(i + 1, now);
	}
	now = 0;
	for (int i = 0; i < s.size() + 20; i++)nex[0][i] = s.size() + 1;
	for (int i = 0; i < s.size() + 1; i++)
	{
		int low = lower_bound(ma[now].begin(), ma[now].end(), i) - ma[now].begin();
		if (low == ma[now].size() - 1)nex[0][i] = s.size() + 1;
		else if (tree2.get(ma[now][low], ma[now][low + 1], 1, 0, SIZE - 1) < now)nex[0][i] = s.size() + 1;
		else nex[0][i] = ma[now][low + 1];
		if (s[i] == '(')now++;
		else now--;
		//printf("%d %d\n", i, nex[0][i]);
	}
	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < s.size() + 20; j++)
		{
			nex[i][j] = nex[i - 1][nex[i - 1][j]];
		}
	}
	ll ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int n = 0;
		int t = i;
		for (int j = 19; j >= 0; j--)
		{
			if (nex[j][t] <= s.size())t = nex[j][t], n += (1 << j);
		}
		ans += n;
	}
	for (int i = 0; i < s.size(); i++)
	{
		int g = lcp[i + 1];
		int n = 0;
		int t = sa[i + 1];
		//printf("%d %d\n", t, g);
		for (int j = 19; j >= 0; j--)
		{
			if (nex[j][t] <= g + sa[i + 1])t = nex[j][t], n += (1 << j);
		}
		ans -= n;
	}
	printf("%I64d\n", ans);
}