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
#define SIZE 524288
class sparsetable
{
public:
	int seg[20][SIZE];
	int dat[SIZE];
	void init(vector<int>vec)
	{
		for (int i = 1; i < SIZE; i++)
		{
			int c = 0, now = i;
			for (;;)
			{
				if (now == 0)break;
				now /= 2;
				c++;
			}
			dat[i] = c - 1;
		}
		for (int i = 0; i < vec.size(); i++)seg[0][i] = vec[i];
		for (int i = vec.size(); i < SIZE; i++)seg[0][i] = 1000000000;
		for (int i = 1; i < 20; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				seg[i][j] = min(seg[i - 1][j], seg[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int get(int lb, int ub)
	{
		int t = ub - lb + 1;
		if (t <= 0)return 0;
		return min(seg[dat[t]][lb], seg[dat[t]][ub - (1 << dat[t]) + 1]);
	}
};
sparsetable sptb;
vector<int>str, sa, lcp, rsa;
void init()
{
	sa = sais(str);
	lcp = calclcp(str, sa);
	rsa.resize(sa.size());
	for (int i = 0; i < sa.size(); i++)rsa[sa[i]] = i;
	vector<int>t;
	for (int i = 0; i < str.size(); i++)t.push_back(lcp[i]);
	sptb.init(t);
}
int getlcp(int a, int b)//ablcp
{
	return sptb.get(min(rsa[a], rsa[b]) + 1, max(rsa[a], rsa[b]));
}
typedef pair<int, int>pii;
#define DEP 20
class wavelettree
{
public:
	int lko[2000000];
	int rko[2000000];
	vector<int>rui[2000000];
	vector<int>r2[2000000];
	int wpt;
	void makenode()
	{
		lko[wpt] = rko[wpt] = -1;
		rui[wpt].resize(1);
		r2[wpt].resize(1);
		wpt++;
		return;
	}
	void init(vector<pii>vec)
	{
		makenode();
		wpt = 1;
		for (int i = 0; i < vec.size(); i++)
		{
			int node = 0;
			for (int j = DEP - 1; j >= 0; j--)
			{
				if ((vec[i].first & (1 << j)) == 0)
				{
					rui[node].push_back(rui[node][rui[node].size() - 1]);
					if (lko[node] == -1)
					{
						lko[node] = wpt;
						makenode();
					}
					node = lko[node];
				}
				else
				{
					rui[node].push_back(rui[node][rui[node].size() - 1] + 1);
					if (rko[node] == -1)
					{
						rko[node] = wpt;
						makenode();
					}
					node = rko[node];
				}
				r2[node].push_back(r2[node][r2[node].size() - 1] + vec[i].second);
			}
		}
	}
	int rangecount(int beg, int end, int lb, int ub, int node, int d)//[beg,end][lb,ub]l node=0, d=DEP
	{
		if (node == -1)return 0;
		if (lb == 0 && ub == (1 << d) - 1)return r2[node][end + 1] - r2[node][beg];
		int b0, b1, e0, e1;
		b0 = beg - rui[node][beg];
		b1 = rui[node][beg];
		e0 = end - rui[node][end + 1];
		e1 = rui[node][end + 1] - 1;
		if (ub < (1 << (d - 1)))
		{
			return rangecount(b0, e0, lb, ub, lko[node], d - 1);
		}
		else if ((1 << (d - 1)) <= lb)
		{
			return rangecount(b1, e1, lb - (1 << (d - 1)), ub - (1 << (d - 1)), rko[node], d - 1);
		}
		else
		{
			return rangecount(b0, e0, lb, (1 << (d - 1)) - 1, lko[node], d - 1) + rangecount(b1, e1, 0, ub - (1 << (d - 1)), rko[node], d - 1);
		}
	}
	int getkth(int beg, int end, int k, int node, int d)//[beg,end]kl(k1-origin) node=0, d=DEP
	{
		if (d == 0)return 0;
		int b0, b1, e0, e1;
		b0 = beg - rui[node][beg];
		b1 = rui[node][beg];
		e0 = end - rui[node][end + 1];
		e1 = rui[node][end + 1] - 1;
		if (e0 - b0 + 1 >= k)return getkth(b0, e0, k, lko[node], d - 1);
		else return getkth(b1, e1, k - (e0 - b0 + 1), rko[node], d - 1) + (1 << (d - 1));
	}
};
wavelettree wtree;
int st[200000], go[200000];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<string>vec;
	vector<int>spt;
	for (int i = 0; i < num; i++)
	{
		string z;
		cin >> z;
		vec.push_back(z);
		spt.push_back(str.size());
		for (int j = 0; j < z.size(); j++)str.push_back(z[j] - 'a' + 1);
		str.push_back(27);
	}
	str.push_back(0);
	init();
	vector<pii>zv;
	zv.resize(str.size());
	fill(zv.begin(), zv.end(), make_pair(210000, 0));
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			zv[rsa[spt[i] + j]] = make_pair(i, 1);
		}
	}
	wtree.init(zv);
	for (int i = 0; i < num; i++)
	{
		int beg = 0, end = rsa[spt[i]];
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end) / 2;
			if (getlcp(sa[med], spt[i]) < vec[i].size())beg = med + 1;
			else end = med;
		}
		st[i] = beg;
		beg = rsa[spt[i]], end = str.size() - 1;
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end + 1) / 2;
			if (getlcp(sa[med], spt[i]) < vec[i].size())end = med - 1;
			else beg = med;
		}
		go[i] = beg;
	}
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		zc--;
		printf("%d\n", wtree.rangecount(st[zc], go[zc], za, zb, 0, DEP));
	}
}