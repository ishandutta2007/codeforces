#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MAXN = 200000, inf = 1010000000;

struct Sec
{
	int l, r, val, sl, sr;
	Sec(){}
	Sec(int _l, int _r, int _val, int _sl, int _sr) : l(_l), r(_r), val(_val), sl(_sl), sr(_sr) {} 
	friend int operator < (Sec a, Sec b)
	{
		if (a.l != b.l)
			return a.l < b.l;
		return a.r < b.r;
	}
};

set <Sec> s;

int n, t;
struct node
{
	int l, r, h, val;
	friend int operator<(node a, node b)
	{
		return a.h > b.h;
	}
}p[MAXN];

inline void update(int &v, int l, int r, Sec it)
{
	int rr = min(r, it.sr);
	int ll = max(l, it.sl);
	if (!(it.l <= ll && rr <= it.r))
		return;
	v = max(v, min(it.val, min(it.r, r) - max(it.l, l)));
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &p[i].h, &p[i].l, &p[i].r);
	}
	sort(p + 1, p + n + 1);
	s.clear();
	s.insert(Sec(-inf, inf, 2 * inf, -inf, inf));
	set<Sec> :: iterator it, tmp;
	for(int i = 1; i <= n; i++)
	{
		int l = p[i].l, r = p[i].r, v = 0;
		it = s.upper_bound(Sec(l, inf, 0, -inf, inf));
		if (it != s.begin()) it--;
		//for(; it != s.end() && it->r <= l; ++it);
		for(; it != s.end(); )
		{
			if (it->r <= l)
			{
				++it;
				continue;
			}
			if (it->l >= r)
				break;
			if (l <= it->l && it->r <= r)
			{
				update(v, l, r, *it);
				tmp = it;
				++it;
				s.erase(tmp);
			} else
			{
				update(v, l, r, *it);
				int bv = it->val; tmp = it;
				if (tmp->l < l)
				{					
					s.insert(Sec(tmp->l, l, bv, tmp->sl, tmp->sr));
					it = s.find(Sec(tmp->l, l, bv, tmp->sl, tmp->sr));
				}
				if (tmp->r > r)
				{
					s.insert(Sec(r, tmp->r, bv, tmp->sl, tmp->sr));
					it = s.find(Sec(r, tmp->r, bv, tmp->sl, tmp->sr));
				}
				s.erase(tmp);
			}
		}
		s.insert(Sec(l, r, v, l, r));
		/*
		printf("insert sec %d %d %d\n", l, r, v);
		for(it = s.begin(); it != s.end(); ++it)
		{
			printf("%d %d %d\n", it->l, it->r, it->val);
		}
		printf("---------------------------------\n");
		*/
	}
	int ans = 0;
	for(it = s.begin(); it != s.end(); ++it)
	if (it->val != 2 * inf && it->l == it->sl && it->r == it->sr)
		ans = max(ans, min(it->val, it->r - it->l));
	printf("%d\n", ans);
	return 0;
}