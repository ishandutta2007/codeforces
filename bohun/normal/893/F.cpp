#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n, r;
const int nax = 100005;
vector <int> v[nax];
int a, b, m;
vector < pair <int, int> > q[nax];
int tim = 0;
int col[nax], in[nax], out[nax], h[nax];
int j = (1 << 17);
vector < pair < int, int > > t[4 * nax];
void dfs(int node, int par)
{
	t[tim + j].pb({node, col[node]});
	in[node] = tim++;
	for(auto it: v[node])
		if(it != par)
			h[it] = h[node] + 1, dfs(it, node);
	out[node] = tim - 1;
}
bool cmp(pair <int ,int > a, pair <int, int > b)
{
	return h[b.fi] > h[a.fi];
}
void add(int x, int y)
{
	for(auto it: t[y])
		t[x].pb(it);
}
int last = 0;
int daj(int node, int lewo, int prawo, int x, int y)
{
	if(y >= prawo and lewo >= x)
	{
		int l = 0;
		int p = ss(t[node]) - 1;
		while(p > l)
		{
			int s = (l + p + 1) / 2;
			if(h[t[node][s].fi] <= b)
				l = s;
			else
				p = s - 1;
		}
		if(h[t[node][p].fi] > b)
			return 1000000008;
		return t[node][l].se;
		
	}
	int wynik = 1000000005;
	int mid = (lewo + prawo) / 2;
	if(mid >= x)
		wynik = min(wynik, daj(2 * node, lewo, mid, x, y));
	if(y > mid)
		wynik = min(wynik, daj(2 * node + 1, mid + 1, prawo, x, y));
	return wynik;
}
int main()
{
	scanf("%d %d", &n, &r);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &col[i]);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(r, -1);
	for(int i = j - 1; i >= 1; --i)
	{
		add(i, 2 * i);
		add(i, 2 * i + 1);
		sort(t[i].begin(), t[i].end(), cmp);
		int mini = 1000000005;
		for(auto &it: t[i])
		{
			mini = min(mini, col[it.fi]);
			it.se = mini;
		}
	}
	scanf("%d", &m);
	for(int i = 1; m >= i; ++i)
	{
		scanf("%d %d", &a, &b);
		a = (a + last) % n + 1;
		b = (b + last) % n;
		b = h[a] + b;
		printf("%d\n", daj(1, 0, j - 1, in[a], out[a]));
		last = daj(1, 0, j - 1, in[a], out[a]);
	}
			
	return 0;
}