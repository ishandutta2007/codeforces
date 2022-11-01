/*
  !










*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
struct Segment
{
	int l, r, cost;
	Segment(){
		//		
	}
	Segment(int _l, int _r, int _cost)
	{
		l = _l;
		r = _r;
		cost = _cost;
	}
};
int getComp(vector<int> &xx, int x)
{
	return lower_bound(xx.begin(), xx.end(), x) - xx.begin();
}
struct Event
{
	int pos;
	int type; // -2 - addSeg, -1 - add TV, 1 - del TV, 2 - delSeg;
	int id;
	Event(){
	}
	Event(int _pos, int _type, int _id)
	{
		pos = _pos;
		type = _type;
		id = _id;
	}
};
bool operator<(Event x, Event y)
{
	return make_pair(x.pos, x.type) < make_pair(y.pos, y.type);
}
struct segmentTree
{
	vector<pair<int, int> > t;
	segmentTree(int n)
	{
		t.resize(4 * n + 3);
	}
	void change(int v, int tl, int tr, int pos, pair<int, int> val)
	{
		if (tl == tr)
		{
			t[v] = max(t[v], val);
		}
		else
		{
			int tm = (tl + tr) >> 1;
			if (pos <= tm)
			{
				change(v + v, tl, tm, pos, val);
			}
			else
			{
				change(v + v + 1, tm + 1, tr, pos, val);
			}
			t[v] = max(t[v + v], t[v + v + 1]);
		}
	}
	pair<int, int> getMax(int v, int tl, int tr, int l, int r)
	{
		if (r < tl || l > tr) return make_pair(0, 0);
		if (tl >= l && tr <= r) return t[v];
		int tm = (tl + tr) / 2;
		return max(getMax(v + v, tl, tm, l, r), getMax(v + v + 1, tm + 1, tr, l, r));
	}
};
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	vector<Segment> segs, tvs;
	vector<int> xx;
	xx.push_back(-228);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		segs.push_back(Segment(l, r, 0));
		xx.push_back(l);
		xx.push_back(r);
	}
	for (int i = 1; i <= m; i++)
	{
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		tvs.push_back(Segment(l, r, c));
		xx.push_back(l);
		xx.push_back(r);
	}
	sort(xx.begin(), xx.end());
	xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
	for (int i = 0; i < n; i++)
	{
		segs[i].l = getComp(xx, segs[i].l);
		segs[i].r = getComp(xx, segs[i].r);
	}
	for (int i = 0; i < m; i++)
	{
		tvs[i].l = getComp(xx, tvs[i].l);
		tvs[i].r = getComp(xx, tvs[i].r);
	}
	vector<Event> ev;
	for (int i = 0; i < n; i++)
	{
		ev.push_back(Event(segs[i].l, -2, i));
		ev.push_back(Event(segs[i].r, 2, i));
	}
	for (int i = 0; i < m; i++)
	{
		ev.push_back(Event(tvs[i].l, -1, i));
		ev.push_back(Event(tvs[i].r, 1, i));
	}
	sort(ev.begin(), ev.end());
	ll res = 0;
	int resx = -1, resy = -1;
	set<pair<int, int> > openL, openR;
	int sz = (int)xx.size();
	segmentTree st(sz);
	for (int i = 0; i < (int)ev.size(); i++)
	{
		int id = ev[i].id;
		if (ev[i].type == -2)
		{
			pair<int, int> best = st.getMax(1, 1, sz, segs[id].r, sz);
			if (best.first != 0)
			{
				ll curRes = 1LL * (xx[segs[id].r] - xx[segs[id].l]) * best.first;
				if (curRes > res)
				{
					res = curRes;
					resx = id + 1;
					resy = best.second + 1;
				}
			}
			openR.insert(make_pair(segs[id].r, id));
			openL.insert(make_pair(segs[id].l, id));
		}
		else if (ev[i].type == 2)
		{
			openR.erase(make_pair(segs[id].r, id));
			openL.erase(make_pair(segs[id].l, id));
		}
		else if (ev[i].type == -1)
		{
			if (!openR.empty())
			{
				int cl = xx[tvs[id].l];
				int segId = (*openR.rbegin()).second;
				int cr = xx[segs[segId].r];
				cr = min(cr, xx[tvs[id].r]);
				ll curRes = 1LL * (cr - cl) * tvs[id].cost;
				if (curRes > res)
				{
					res = curRes;
					resx = segId + 1;
					resy = id + 1;
				}
			}
			st.change(1, 1, sz, tvs[id].r, make_pair(tvs[id].cost, id));
		}
		else
		{
			if (!openL.empty())
			{
				int cr = xx[tvs[id].r];
				int segId = (*openL.begin()).second;
				int cl = xx[segs[segId].l];
				cl = max(cl, xx[tvs[id].l]);
				ll curRes = 1LL * (cr - cl) * tvs[id].cost;
				if (curRes > res)
				{
					res = curRes;
					resx = segId + 1;
					resy = id + 1;
				}
			}
		}
	}
	if (res == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", res);
		printf("%d %d\n", resx, resy);
	}
}