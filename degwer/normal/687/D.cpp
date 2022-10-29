#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
typedef pair<vector<pi3>, int>pvi;
#define SIZE 2000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
vector<pi3>merge(vector<pi3>va, vector<pi3>vb)
{
	vector<pi3>vec;
	int pt = 0;
	for (int i = 0; i < va.size(); i++)
	{
		for (;;)
		{
			if (pt == vb.size())break;
			if (vb[pt].second > va[i].second)vec.push_back(vb[pt++]);
			else break;
		}
		vec.push_back(va[i]);
	}
	for (int i = pt; i < vb.size(); i++)vec.push_back(vb[i]);
	return vec;
}
pvi get(vector<pi3>vec)
{
	uf.init();
	vector<pi3>ret;
	for (int i = 0; i < vec.size(); i++)
	{
		int s = vec[i].first.first, t = vec[i].first.second;
		if (uf.find(s * 2) != uf.find(t * 2) && uf.find(s * 2) != uf.find(t * 2 + 1))
		{
			uf.unite(s * 2, t * 2 + 1);
			uf.unite(s * 2 + 1, t * 2);
			ret.push_back(vec[i]);
		}
		if (uf.find(s * 2) == uf.find(t * 2))
		{
			return make_pair(ret, vec[i].second);
		}
	}
	return make_pair(ret, -1);
}
pi3 dat[1000000];
vector<pi3>sortv(int lb, int ub)
{
	vector<pii>zv;
	for (int j = lb; j <= ub; j++)
	{
		zv.push_back(make_pair(dat[j].second, j));
	}
	sort(zv.begin(), zv.end());
	reverse(zv.begin(), zv.end());
	vector<pi3>z;
	for (int i = 0; i < zv.size(); i++)
	{
		z.push_back(dat[zv[i].second]);
	}
	return z;
}
#define SIZE 1024
class segtree
{
public:
	pvi seg[SIZE * 2];
	void init(vector<pvi>vec)
	{
		seg[0].second = -1;
		for (int i = 0; i < vec.size(); i++)
		{
			seg[SIZE + i] = vec[i];
		}
		for (int i = vec.size(); i < SIZE; i++)seg[SIZE + i].second = -1;
		for (int i = SIZE - 1; i >= 1; i--)
		{
			pvi t = get(merge(seg[i * 2].first, seg[i * 2 + 1].first));
			seg[i].first = t.first;
			seg[i].second = max(t.second, max(seg[i * 2].second, seg[i * 2 + 1].second));
		}
	}
	pvi calc(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return seg[0];
		if (beg <= lb&&ub <= end)return seg[node];
		pvi a = calc(beg, end, node * 2, lb, (lb + ub) / 2);
		pvi b = calc(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub);
		pvi t = get(merge(a.first, b.first));
		return make_pair(t.first, max(t.second, max(a.second, b.second)));
	}
};
segtree tree;
int main()
{
	int num, way, query;
	scanf("%d%d%d", &num, &way, &query);
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		dat[i] = make_pair(make_pair(za, zb), zc);
	}
	/*for (int i = 0; i < way; i++)
	{
		for (int j = i; j < way; j++)
		{
			printf("%d %d  %d\n:::", i, j, get(sortv(i, j)).second);
			vector<pi3>v = get(sortv(i, j)).first;
			for (int k = 0; k < v.size(); k++)printf("%d %d  ", v[k].first.first, v[k].first.second); printf("\n");
		}
	}*/
	vector<pvi>sgv;
	for (int i = 0; i < (way + num - 1) / num; i++)
	{
		sgv.push_back(get(sortv(num*i, min(way, num*(i + 1)))));
	}
	tree.init(sgv);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		int lb = za / num, ub = zb / num;
		if (lb == ub)
		{
			pvi t = get(sortv(za, zb));
			printf("%d\n", t.second);
		}
		else
		{
			pvi v1 = get(sortv(za, (lb + 1)*num - 1));
			pvi v2 = tree.calc(lb + 1, ub - 1, 1, 0, SIZE - 1);
			pvi v3 = get(sortv(ub*num, zb));
			pvi t = get(merge(v1.first,merge(v2.first,v3.first)));
			/*printf("%d %d %d  %d\n", v1.second, v2.second, v3.second, t.second);
			for (int k = 0; k < v1.first.size(); k++)printf("%d %d  ", v1.first[k].first.first, v1.first[k].first.second); printf("\n");
			for (int k = 0; k < merge(v1.first, merge(v2.first, v3.first)).size(); k++)printf("%d %d  ", merge(v1.first, merge(v2.first, v3.first))[k].first.first, merge(v1.first, merge(v2.first, v3.first))[k].first.second); printf("\n");
			for (int k = 0; k < v3.first.size(); k++)printf("%d %d  ", v3.first[k].first.first, v3.first[k].first.second); printf("\n");
			for (int k = 0; k < t.first.size(); k++)printf("%d %d  ", t.first[k].first.first, t.first[k].first.second); printf("\n");*/
			printf("%d\n", max(max(t.second, v2.second), max(v1.second, v3.second)));
		}
	}
}