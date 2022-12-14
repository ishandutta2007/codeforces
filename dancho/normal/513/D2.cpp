#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
pii it[1 << 21];

void it_add(pii val, int pos)
{
	int p = pos + (1 << 20) - 1;
	while (p)
	{
		it[p] = max(it[p], val);
		p /= 2;
	}
}

pii it_get(int nd, int nl, int nr, int l, int r)
{
	if (l <= nl && nr <= r)
		return it[nd];
	if (l > nr || nl > r)
		return make_pair(-1, -1);
	return max(it_get(2 * nd, nl, (nl + nr) / 2, l, r),
			   it_get(2 * nd + 1, (nl + nr) / 2 + 1, nr, l, r));
}

pii it_get(int l, int r)
{
	if (l > r)
		return make_pair(-1, -1);
	return it_get(1, 1, (1 << 20), l, r);
}

int n, c;

int a[1 << 20], b[1 << 20];
char tp[1 << 20];

int hs[1 << 20];
int ne[1 << 20];
int fin[1 << 20];

int li[1 << 20];

int mik[1 << 20], mxk[1 << 20];

bool getDP(int l, int r)
{
	if (hs[l] != -1)
		return hs[l];
	if (l >= r)
	{
		return 1;
	}
	
	hs[l] = 0;
	int k = mik[l];
	if (k < l)
		k = l;
	vector<int> vs;
	while (k <= r && k <= mxk[l])
	{
		pii si = it_get(l + 1, k);
		int s = si.first;
		if (s <= k)
		{
			for (int i = 0; i < (int) vs.size(); ++i)
			{
				fin[vs[i]] = k;
			}
			if (getDP(l + 1, k) && getDP(k + 1, r))
			{
				ne[l] = k;
				hs[l] = 1;
				break;
			}
			break;
		}
		int id = si.second;
		if (id != -1)
		{
			vs.push_back(id);
			if (fin[id] != -1 && a[id] > l && a[id] <= k && fin[id] != k)
			{
				k = fin[id];
				continue;
			}
		}
		if (s > k)
		{
			k = s;
		}
	}
	
	return hs[l];
}

int le[1 << 20], ri[1 << 20];

void cli(int l, int r)
{
	if (l >= r)
		return;
	li[l] = ne[l];
	if (li[l] > l)
	{
		le[l] = l + 1;
		cli(l + 1, li[l]);
	}
	if (li[l] < r)
	{
		ri[l] = li[l] + 1;
		cli(li[l] + 1, r);
	}
}

vector<int> sl;

void sol(int v)
{
	if (le[v] != -1)
		sol(le[v]);
	sl.push_back(v);
	if (ri[v] != -1)
		sol(ri[v]);
}

int main()
{
	memset(it, -1, sizeof(it));
	memset(mik, 0, sizeof(mik));
	memset(mxk, 63, sizeof(mxk));
	scanf("%d %d", &n, &c);
	char buf[32];
	for (int i = 0; i < c; i++)
	{
		scanf("%d %d %s", &a[i], &b[i], buf);
		it_add(make_pair(b[i], i), a[i]);
		tp[i] = buf[0];
		if (tp[i] == 'L')
		{
			mik[a[i]] = max(mik[a[i]], b[i]);
		}
		if (tp[i] == 'R')
		{
			mxk[a[i]] = min(mxk[a[i]], b[i] - 1);
		}
		if (a[i] >= b[i])
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	
	memset(hs, -1, sizeof(hs));
	memset(fin, -1, sizeof(fin));
	bool ok = getDP(1, n);
	
	if (!ok)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	
	memset(li, -1, sizeof(li));
	memset(le, -1, sizeof(le));
	memset(ri, -1, sizeof(ri));
	cli(1, n);
	
	sol(1);
	for (int i = 0; i + 1 < (int) sl.size(); i++)
	{
		printf("%d ", sl[i]);
	}
	printf("%d\n", sl.back());
	
	
	return 0;
}