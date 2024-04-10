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
#define SIZE 262144
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
void init()
{
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
#define B 1250
#define NB 81
typedef long long ll;
ll rrui[NB][200010];
ll rans[NB][100010];
int stp[100000];
int toz[100000];
vector<int>kou[100000];
ll ans[100000];
class trie
{
public:
	int nex[100001][26];
	vector<int>dat[100001];
	int pt;
	void init()
	{
		pt = 1;
		fill(nex[0], nex[0] + 26, -1);
	}
	void adds(string s, int d)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nex[now][s[i] - 'a'] == -1)
			{
				nex[now][s[i] - 'a'] = pt;
				fill(nex[pt], nex[pt] + 26, -1);
				pt++;
			}
			now = nex[now][s[i] - 'a'];
		}
		dat[now].push_back(d);
	}
	int getdest(string s)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nex[now][s[i] - 'a'] == -1)break;
			now = nex[now][s[i] - 'a'];
		}
		return now;
	}
	vector<int>eul;
	int ord[100001];
	int fin[100001];
	void calceul(int node)
	{
		ord[node] = eul.size();
		eul.push_back(node);
		for (int i = 0; i < 26; i++)if (nex[node][i] != -1)calceul(nex[node][i]);
		fin[node] = eul.size() - 1;
	}
};
trie tr;
class sqq
{
public:
	ll now[B*NB];
	ll flag[NB];
	void resolve(int b)
	{
		for (int i = 0; i < B; i++)now[B*b + i] += flag[b];
		flag[b] = 0;
	}
	void add(int lb, int ub, int t)
	{
		int a = lb / B, b = ub / B;
		resolve(a);
		resolve(b);
		if (a == b)
		{
			for (int i = lb; i <= ub; i++)now[i] += t;
		}
		else
		{
			for (int i = lb; i < a*B + B; i++)now[i] += t;
			for (int i = a + 1; i <= b - 1; i++)flag[i] += t;
			for (int i = b*B; i <= ub; i++)now[i] += t;
		}
	}
	ll get(ll a)
	{
		return flag[a / B] + now[a];
	}
};
sqq bi;
typedef pair<int, int>pii;
vector<pii>que1[100000], que2[100000];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<string>vec;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}
	for (int i = 0; i < num; i++)
	{
		stp[i] = str.size();
		for (int j = 0; j < vec[i].size(); j++)str.push_back(vec[i][j] - 'a' + 1);
		str.push_back(27);
	}
	str.push_back(0);
	init();
	tr.init();
	for (int i = 0; i < vec.size(); i++)
	{
		tr.adds(vec[i], i);
	}
	int pt = 0;
	for (int i = 0; i < num; i++)
	{
		if (vec[i].size() >= B)
		{
			for (int j = stp[i]; j < stp[i] + vec[i].size(); j++)
			{
				rrui[pt][rsa[j] + 1]++;
			}
			for (int j = 1; j <= str.size(); j++)rrui[pt][j] += rrui[pt][j - 1];
			toz[i] = pt;
			pt++;
		}
		else
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				string zs;
				for (int k = j; k < vec[i].size(); k++)zs.push_back(vec[i][k]);
				kou[i].push_back(tr.getdest(zs));
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		int lb, ub;
		int beg = 0, end = rsa[stp[i]];
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end) / 2;
			if (getlcp(sa[med], sa[rsa[stp[i]]]) < vec[i].size())beg = med + 1;
			else end = med;
		}
		lb = beg;
		beg = rsa[stp[i]], end = str.size() - 1;
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end + 1) / 2;
			if (getlcp(sa[med], sa[rsa[stp[i]]]) < vec[i].size())end = med - 1;
			else beg = med;
		}
		ub = beg;
		for (int j = 0; j < pt; j++)
		{
			rans[j][i + 1] += rrui[j][ub + 1] - rrui[j][lb];
		}
	}
	for (int i = 0; i < pt; i++)
	{
		for (int j = 0; j < num; j++)
		{
			rans[i][j + 1] += rans[i][j];
		}
	}
	for (int p = 0; p < query; p++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		zc--;
		if (vec[zc].size() >= B)
		{
			ans[p] = rans[toz[zc]][zb + 1] - rans[toz[zc]][za];
		}
		else
		{
			que1[za].push_back(make_pair(zc, p));
			que2[zb].push_back(make_pair(zc, p));
		}
	}
	tr.calceul(0);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < que1[i].size(); j++)
		{
			for (int k = 0; k < kou[que1[i][j].first].size(); k++)
			{
				ans[que1[i][j].second] -= bi.get(tr.ord[kou[que1[i][j].first][k]]);
			}
		}
		if (vec[i].size() < B)bi.add(tr.ord[kou[i][0]], tr.fin[kou[i][0]], 1);
		for (int j = 0; j < que2[i].size(); j++)
		{
			for (int k = 0; k < kou[que2[i][j].first].size(); k++)
			{
				ans[que2[i][j].second] += bi.get(tr.ord[kou[que2[i][j].first][k]]);
			}
		}
	}
	for (int i = 0; i < query; i++)
	{
		printf("%I64d\n", ans[i]);
	}
}