#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2000 * 100 + 5;
const int MAX_A = 102;
const int BL = 433;

struct dsu
{
	int *vl;

	dsu()
	{
	}
	
	dsu(bool fg)
	{
		assert(fg);
		
		vl = (int*)malloc(sizeof(int) * MAX_A);
		
		for (int i = 0; i < MAX_A; ++i) vl[i] = i;
	}
	
	dsu(const dsu &ds)
	{
		vl = (int*)malloc(sizeof(int) * MAX_A);
		
		memcpy(vl, ds.vl, sizeof(int) * MAX_A);
	}
	
	void mfree()
	{
		free(vl);
	}
	
	void un(int v1, int v2)
	{
		for (int i = 0; i < MAX_A; ++i)
		{
			if (vl[i] == v1) vl[i] = v2;
		}
	}
};

struct block
{
	int l;
	int r;
	dsu ds;
	
	block()
	{
	}

	block(int _l, int _r)
	{
		l = _l;
		r = _r;
		ds = dsu(true);
	}

	block(int _l, int _r, const dsu &_ds)
	{
		l = _l;
		r = _r;
		ds = dsu(_ds);
	}
};

int n, q;
int arr[MAX_N];
vector<block> now;

void rebuild()
{
	for (int i = 0; i < (int)now.size(); ++i)
	{
		for (int j = now[i].l; j <= now[i].r; ++j) arr[j] = now[i].ds.vl[arr[j]];
		now[i].ds.mfree();
	}

	now.clear();
	now.push_back(block(0, n - 1));	
}

void split(int x)
{
	for (int i = 0; i < (int)now.size(); ++i)
	{
		if (now[i].l < x && x <= now[i].r)
		{
			block mem = block(now[i].l, x - 1, now[i].ds);
			now[i].l = x;
			now.resize((int)now.size() + 1);
			for (int j = (int)now.size() - 1; j > i; --j) now[j] = now[j - 1];
			now[i] = mem;
			break;
		}
	}
}

void upd(int l, int r, int x, int y)
{
	split(l);
	split(r + 1);

	for (int i = 0; i < (int)now.size(); ++i)
	{
		if (l <= now[i].l && now[i].r <= r) now[i].ds.un(x, y);
	}
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);


	rebuild();
	scanf("%d", &q);	
	int l, r, x, y;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d%d%d", &l, &r, &x, &y);
		--l; --r;
		upd(l, r, x, y);
		
		if (i != 0 && i % BL == 0) rebuild();
	}
	
	rebuild();
	for (int i = 0; i < n; ++i) printf("%d ", arr[i]);

	return 0;
}