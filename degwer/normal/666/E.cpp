#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<time.h>
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
sparsetable sp;
//segtree tree;
vector<int>str, sa, lcp, rsa;
void init(string s)
{
	for (int i = 0; i < s.size(); i++)str.push_back(s[i] - 'a' + 1);
	str.push_back(0);
	sa = sais(str);
	lcp = calclcp(str, sa);
	//tree.init();
	sp.init(lcp);
	rsa.resize(sa.size());
	for (int i = 0; i < sa.size(); i++)rsa[sa[i]] = i;
	//for (int i = 0; i < str.size(); i++)tree.update(i, lcp[i]);
}
int getlcp(int a, int b)//ablcp
{
	return sp.get(min(rsa[a], rsa[b]) + 1, max(rsa[a], rsa[b]));
}
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
typedef pair<pi3, pii>pi5;
pii ans[500000];
class segtreedy
{
public:
	vector<int>seg;
	vector<int>idx;
	vector<int>lko;
	vector<int>rko;
	vector<pii>vec;
	void init()
	{
		seg.push_back(0);
		lko.push_back(-1);
		rko.push_back(-1);
		idx.push_back(-1);
	}
	void add(int pl, int node, int lb, int ub, int num)
	{
		if (ub < pl || pl < lb)return;
		if (lb == ub)
		{
			seg[node] += num;
			idx[node] = -pl;
			vec.push_back(make_pair(pl, num));
			return;
		}
		if (lko[node] == -1)
		{
			lko[node] = seg.size();
			seg.push_back(0);
			lko.push_back(-1);
			rko.push_back(-1);
			idx.push_back(-1);
		}
		if (rko[node] == -1)
		{
			rko[node] = seg.size();
			seg.push_back(0);
			lko.push_back(-1);
			rko.push_back(-1);
			idx.push_back(-1);
		}
		add(pl, lko[node], lb, (lb + ub) / 2, num);
		add(pl, rko[node], (lb + ub) / 2 + 1, ub, num);
		seg[node] = max(seg[lko[node]], seg[rko[node]]);
		if (seg[node] == seg[lko[node]])idx[node] = idx[lko[node]];
		else idx[node] = idx[rko[node]];
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(0, -1);
		if (beg <= lb&&ub <= end)
		{
			//if (idx[node] == -1)return make_pair(seg[node], -lb);
			return make_pair(seg[node], idx[node]);
		}
		if (lko[node] == -1)
		{
			lko[node] = seg.size();
			seg.push_back(0);
			lko.push_back(-1);
			rko.push_back(-1);
			idx.push_back(-1);
		}
		if (rko[node] == -1)
		{
			rko[node] = seg.size();
			seg.push_back(0);
			lko.push_back(-1);
			rko.push_back(-1);
			idx.push_back(-1);
		}
		return max(get(beg, end, lko[node], lb, (lb + ub) / 2), get(beg, end, rko[node], (lb + ub) / 2 + 1, ub));
	}
	void destroy()
	{
		seg.clear();
		lko.clear();
		rko.clear();
		vec.clear();
	}
};
segtreedy dat[600000];
int main()
{
	time_t clll = clock();
	string s;
	cin >> s;
	vector<string>vec;
	string conc;
	int num;
	scanf("%d", &num);
	vector<int>toidx;
	for (int i = 0; i < num; i++)
	{
		string z;
		cin >> z;
		vec.push_back(z);
		conc += z;
		conc.push_back('z' + 1);
		for (int j = 0; j < z.size(); j++)toidx.push_back(i + 1);
		toidx.push_back(0);
	}
	int spt = conc.size();
	conc += s;
	for (int i = 0; i < s.size(); i++)toidx.push_back(0);
	init(conc);
	int query;
	scanf("%d", &query);
	vector<pi5>que;
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		zc--, zd--;
		int lb, ub;
		int beg = 0, end = rsa[spt + zc];
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end) / 2;
			if (getlcp(sa[med], spt + zc) >= zd - zc + 1)end = med;
			else beg = med+1;
		}
		lb = beg;
		beg = rsa[spt + zc], end = conc.size() - 1;
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end+1) / 2;
			if (getlcp(sa[med], spt + zc) >= zd - zc + 1)beg = med;
			else end = med-1;
		}
		ub = beg;
		que.push_back(make_pair(make_pair(make_pair(ub - lb + 1, lb), i), make_pair(za, zb)));
	}
	//for (int i = 0; i < conc.size(); i++)printf("%d", i % 10); printf("\n");
	//cout << conc << endl;
	//for (int i = 0; i < conc.size(); i++)printf("%d %c %d %d\n", i, conc[sa[i]], sa[i], lcp[i]);
	sort(que.begin(), que.end());
	for (int i = 0; i < conc.size(); i++)
	{
		dat[i].init();
		if (toidx[sa[i]] != 0)dat[i].add(toidx[sa[i]], 0, 0, SIZE - 1, 1);
	}
	//if (double(clock() - clll) / CLOCKS_PER_SEC>2.9)return 0;
	//for (int i = 0; i < conc.size(); i++)printf("%d ", toidx[sa[i]]);
	//printf("\n");
	set<pii>se;
	for (int i = 0; i < conc.size(); i++)if (toidx[sa[i]] != 0)se.insert(make_pair(i, i));
	se.insert(make_pair(conc.size(), conc.size()));
	se.insert(make_pair(conc.size() + 1, conc.size()));
	for (int i = 0; i < que.size(); i++)
	{
		int now = que[i].first.first.second;
		int end = que[i].first.first.second + que[i].first.first.first - 1;
		//printf("%d %d\n", now, end);
		set<pii>::iterator it = se.lower_bound(make_pair(now,-1));
		for (;;)
		{
			int pt1 = (*it).second;
			it++;
			if ((*it).first >= end + 1)break;
			int pt2 = (*it).second;
			se.erase(it++);
			it--;
			se.erase(it++);
			if (dat[pt1].vec.size() > dat[pt2].vec.size())swap(pt1, pt2);
			for (int j = 0; j < dat[pt1].vec.size(); j++)
			{
				//printf(" %d %d\n", dat[pt1].vec[j].first, dat[pt1].vec[j].second);
				dat[pt2].add(dat[pt1].vec[j].first, 0, 0, SIZE - 1, dat[pt1].vec[j].second);
			}
			dat[pt1].destroy();
			se.insert(make_pair(now, pt2));
			it--;
		}
		it = se.lower_bound(make_pair(now, -1));
		if ((*it).first > end)
		{
			ans[que[i].first.second] = make_pair(0, -que[i].second.first);
			continue;
		}
		pii t = dat[(*it).second].get(que[i].second.first, que[i].second.second, 0, 0, SIZE - 1);
		if (t.first == 0)t.second = -que[i].second.first;
		ans[que[i].first.second] = t;
		//for (int i = 0; i < 5; i++)printf("%d %d  ", dat[(*it).second].get(i, i, 0, 0, SIZE - 1).first, dat[(*it).second].get(i, i, 0, 0, SIZE - 1).second); printf("\n");
	}
	for (int i = 0; i < query; i++)
	{
		printf("%d %d\n", -ans[i].second, ans[i].first);
	}
}