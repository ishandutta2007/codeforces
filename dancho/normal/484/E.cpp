#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

struct sell
{
	int a, b, c;
};

struct event
{
	// type = 1: insert ; type = 0: remove
	int pos, time, type, ss;

	bool operator<(const event& e) const
	{
		if (time != e.time)
			return time < e.time;
		return type < e.type;
	}
};

struct node
{
	int le, ri;
	int s, l, r;
	int sz;
};

int n;
int h[1 << 17];
pii he[1 << 17];

int m;

vector<event> ve;

int lnd;
int nn[1 << 23];
node nds[1 << 23];

map<pii, int> nc;

map<int, int> ps;
int rts[1 << 17];

int it_insert(int nd, int nl, int nr, int pos)
{
	if (pos < nl || pos > nr)
	{
		if (nn[nd] == -1)
		{
			nn[nd] = lnd++;
			nds[ nn[nd] ].s = 0;
			nds[ nn[nd] ].l = 0;
			nds[ nn[nd] ].r = 0;
			nds[ nn[nd] ].sz = nr - nl + 1;
			nds[ nn[nd] ].le = nds[ nn[nd] ].ri = -1;
		}
		return nn[nd];
	}
	// Else, update node.
	nn[nd] = lnd++;
	if (nl == pos && nr == pos)
	{
		nds[ nn[nd] ].le = nds[ nn[nd] ].ri = -1;
		nds[ nn[nd] ].s = 1;
		nds[ nn[nd] ].l = 1;
		nds[ nn[nd] ].r = 1;
		nds[ nn[nd] ].sz = 1;
		return nn[nd];
	}
	nds[ nn[nd] ].le = it_insert(2 * nd, nl, (nl + nr) / 2, pos);
	nds[ nn[nd] ].ri = it_insert(2 * nd + 1, (nl + nr) / 2 + 1, nr, pos);
	//~ printf("%d : %d %d\n", nd, nn[nd * 2], nn[nd * 2 + 1]);
	//~ printf("IT_INS %d ; %d %d :: %d [%d] LR %d (%d) %d (%d)\n", nn[nd], nl, nr, nds[ nn[nd] ].s, pos, nds[ nn[nd] ].le, nds[ nds[ nn[nd] ].le ].s, nds[ nn[nd] ].ri, nds[ nds[ nn[nd] ].ri ].s);
	nds[ nn[nd] ].s = max(nds[ nds[ nn[nd] ].le ].s, nds[ nds[ nn[nd] ].ri ].s);
	nds[ nn[nd] ].s = max(nds[ nn[nd] ].s, nds[ nds[ nn[nd] ].le ].r + nds[ nds[ nn[nd] ].ri ].l);
	if (nds[ nds[ nn[nd] ].le ].s == nds[ nds[ nn[nd] ].le ].sz)
		nds[ nn[nd] ].l = nds[ nds[ nn[nd] ].ri ].l + nds[ nds[ nn[nd] ].le ].sz;
	else
		nds[ nn[nd] ].l = nds[ nds[ nn[nd] ].le ].l;

	if (nds[ nds[ nn[nd] ].ri ].s == nds[ nds[ nn[nd] ].ri ].sz)
		nds[ nn[nd] ].r = nds[ nds[ nn[nd] ].le ].r + nds[ nds[ nn[nd] ].ri ].sz;
	else
		nds[ nn[nd] ].r = nds[ nds[ nn[nd] ].ri ].r;

	nds[ nn[nd] ].sz = nds[ nds[ nn[nd] ].ri ].sz + nds[ nds[ nn[nd] ].le ].sz;
	//~ printf("IT_INS %d ; %d %d :: %d [%d] LR %d (%d) %d (%d)\n", nn[nd], nl, nr, nds[ nn[nd] ].s, pos, nds[ nn[nd] ].le, nds[ nds[ nn[nd] ].le ].s, nds[ nn[nd] ].ri, nds[ nds[ nn[nd] ].ri ].s);
	return nn[nd];
}

node it_query(int ndno, int nl, int nr, int le, int ri)
{
	if (ndno == -1)
	{
		node r;
		r.s = r.l = r.r = 0;
		r.sz = 0;
		return r;
	}
	if (ndno > lnd)
	{
		node r;
		r.s = r.l = r.r = 0;
		r.sz = 0;
		return r;
	}
	//~ printf("QUERY %d : %d %d ; %d %d :: %d\n", ndno, nl, nr, le, ri, nds[ ndno ].mn);
	if (ri < nl || nr < le)
	{
		node r;
		r.s = r.l = r.r = 0;
		r.sz = 0;
		return r;
	}
	if (le <= nl && nr <= ri)
	{
		//~ printf("FINAL! ");
		//~ printf("QUERY %d : %d %d ; %d %d :: %d\n", ndno, nl, nr, le, ri, nds[ ndno ].mn);
		return nds[ ndno ];
	}
	node r1 = it_query(nds[ ndno ].le, nl, (nl + nr) / 2, le, ri),
		 r2 = it_query(nds[ ndno ].ri, (nl + nr) / 2 + 1, nr, le, ri);
	node r;
	r.s = max(r1.s, r2.s);
	r.s = max(r.s, r1.r + r2.l);
	r.sz = r1.sz + r2.sz;
	if (r1.s == r1.sz)
		r.l = r1.sz + r2.l;
	else
		r.l = r1.l;

	if (r2.s == r2.sz)
		r.r = r2.sz + r1.r;
	else
		r.r = r2.r;
	return r;
}

int it_query(int rt, int le, int ri)
{
	return it_query(rt, 1, (1 << 19), le, ri).s;
}

int it_insert(int pos)
{
	// Maybe overkill?
	return it_insert(1, 1, (1 << 19), pos);
}

int main()
{
	memset(nn, -1, sizeof(nn));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
		he[i] = make_pair(h[i], i);
	}
	sort(he + 1, he + n + 1, greater<pii>());

	for (int i = 1; i <= n; ++i)
	{
		//~ printf("ADD %d %d __ %d\n", i, he[i].second, he[i].first);
		rts[i] = it_insert(he[i].second);
		//~ printf("res %d\n", nds[rts[i]].s);
	}

	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		int l, r, w;
		scanf("%d %d %d", &l, &r, &w);
		int le, ri, mi;
		le = 0; ri = n;
		while (le + 1 < ri)
		{
			mi = (le + ri) / 2;
			//~ printf("IT_QUERY %d %d\n", he[mi].first, it_query(rts[mi], l, r));
			if (it_query(rts[mi], l, r) >= w)
				ri = mi;
			else
				le = mi;
		}
		printf("%d\n", he[ri].first);
	}

	return 0;
}