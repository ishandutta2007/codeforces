#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int maxn = (1<<20)-10;

void itadd(int it[], int pos, int val)
{
	for (int i = pos; i <= maxn; i += (i&(-i)))
	{
		it[i] += val;
	}
}

int itget(int it[], int pos)
{
	int res = 0;
	for (int i = pos; i > 0; i -= (i&(-i)))
	{
		res += it[i];
	}
	return res;
}

int itget(int it[], int le, int ri)
{
	return itget(it, ri) - itget(it, le-1);
}

struct el
{
	int tp;
	int l, r;
	int o;
	bool operator<(const el& e) const
	{
		if (r == e.r)
		{
			return tp < e.tp;
		}
		return r < e.r;
	}
};

int n;
char s[1<<20];
int m;

int st[1<<20], stop;

int le;
el e[1<<20];

int out[1<<20];

int rsm[1<<20];
int lsm[1<<20];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	
	stop = 0;
	le = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')')
		{
			if (stop > 0)
			{
				//pair(st[stop], i)
				e[le].tp = 1;
				e[le].l = st[stop]+1;
				e[le].r = i+1;
				++le;
				--stop;
			}
		}
		else if (s[i] == '(')
		{
			st[++stop] = i;
		}
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		e[le].tp = 2;
		e[le].o = i;
		scanf("%d %d", &e[le].l, &e[le].r);
		le++;
	}
	
	sort(e, e + le);
	for (int i = 0; i < le; i++)
	{
		//~ printf("E %d %d %d\n", e[i].tp, e[i].l, e[i].r);
		if (e[i].tp == 1)
		{
			itadd(rsm, e[i].r, 1);
			itadd(lsm, e[i].l, 1);
		}
		else if (e[i].tp == 2)
		{
			int lend = itget(lsm, 1, e[i].l-1) - itget(rsm, 1, e[i].l-1);
			out[e[i].o] = itget(rsm, e[i].l, e[i].r) - lend;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", out[i] * 2);
	}
	
	
	return 0;
}