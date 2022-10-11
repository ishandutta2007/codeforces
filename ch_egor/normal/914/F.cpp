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

const int MAX_N = 1000 * 100 + 228;
const int BL = 200;

const int MAX_SZ = BL * 3 + 40;
const int ALPH = 26;

int n, q;
char st[MAX_N];
char now[MAX_N];
int ph[MAX_N];
int len;
int cnt[MAX_N];
int nw[MAX_N];

struct state
{
	int len;
	int link;
	int cnt;
	int next[ALPH];
};

struct hui
{
	state st[MAX_SZ];
	int sz;
	int last;

	void sa_init()
	{
		for (int i = 0; i < sz; ++i) memset(st[i].next, 0, sizeof(int) * ALPH);
		sz = last = 0;
		st[0].len = 0;
		st[0].link = -1;
		st[0].cnt = 0;
		++sz;
	}

	void sa_extend(int c)
	{
		c -= 'a';
		assert(c < 26);
		int cur = sz++;
		st[cur].len = st[last].len + 1;
		st[cur].cnt = 1;
		int p;
		for (p = last; p != -1 && !st[p].next[c]; p = st[p].link) st[p].next[c] = cur;
		if (p == -1) st[cur].link = 0;
		else 
		{
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) st[cur].link = q;
			else 
			{
				int clone = sz++;
				st[clone].len = st[p].len + 1;
				memcpy(st[clone].next, st[q].next, sizeof(int) * ALPH);
				st[clone].link = st[q].link;
				st[clone].cnt = 0;
				for (; p != -1 && st[p].next[c] == q; p = st[p].link) st[p].next[c] = clone;
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}

	void build(int l, int r)
	{
		sa_init();
		for (int i = l; i < r; ++i) sa_extend(::st[i]);
		
		for (int i = 0; i <= st[last].len; ++i) cnt[i] = 0;
		for (int i = 0; i < sz; ++i) ++cnt[st[i].len];
		for (int i = 1; i <= st[last].len; ++i) cnt[i] += cnt[i - 1];
		for (int i = 0; i < sz; ++i) nw[--cnt[st[i].len]] = i;
		
		for (int i = sz - 1; i > 0; --i) st[st[nw[i]].link].cnt += st[nw[i]].cnt;
	}

	int get()
	{
		int cur = 0;
		for (int i = 0; i < len; ++i)
		{
			if (!st[cur].next[now[i] - 'a']) return 0;
			cur = st[cur].next[now[i] - 'a'];
		}

		return st[cur].cnt;
	}
};

int get(int l, int r)
{
	char *cur_s = st + l;
	int cur_len = r - l;

	ph[0] = 0;
	for (int i = 1; i < len; ++i)
	{
		ph[i] = ph[i - 1];
		while (ph[i] > 0 && now[i] != now[ph[i]]) ph[i] = ph[ph[i] - 1];
		if (now[i] == now[ph[i]]) ++ph[i];
	}

	int ans = 0;
	int nw = 0;
	for (int i = 0; i < cur_len; ++i)
	{
		while (nw > 0 && cur_s[i] != now[nw]) nw = ph[nw - 1];
		if (cur_s[i] == now[nw]) ++nw;

		ans += (nw == len);
	}

	return ans;
}

hui huisas[MAX_N / BL + 10];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%s", st);
	n = strlen(st);
	for (int i = 0; i < n; i += BL) huisas[i / BL].build(i, min(i + BL, n));

	scanf("%d", &q);	
		
	int type, l, r;
	while (q--)
	{
		scanf("%d", &type);
		
		if (type == 2)
		{
			scanf("%d %d %s", &l, &r, now);
			--l; --r;
			len = strlen(now);
				
			if (len >= BL || r - l <= BL)
			{
				printf("%d\n", get(l, r + 1));
			}
			else
			{
				int lf = l / BL;
				int rf = r / BL;
				
				int ans = get(l, min((lf + 1) * BL, n)) + get(rf * BL, r + 1);
				
				for (int i = lf + 1; i <= rf; ++i) ans += get(max(i * BL - len + 1, l), min(r + 1, min(i * BL + len - 1, n)));
				for (int i = lf + 1; i < rf; ++i) ans += huisas[i].get();

				printf("%d\n", ans);
			}
		}
		else
		{
			scanf("%d %s", &l, now);
			--l;
			int lf = l / BL;

			st[l] = now[0];
			huisas[lf].build(lf * BL, min((lf + 1) * BL, n));
		}
	}

	return 0;
}