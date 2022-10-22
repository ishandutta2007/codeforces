#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 100005, mod = 1e9 + 7;
const ll inf = 1e18;
int n, m, q;
int a, b;
vector <int> v[nax];
vector <int> d[nax];
int h[nax], lca[nax][17];
vector <int> s[nax][17];
void dfs(int node, int par)
{
	for(auto it: v[node])
	{
		if(it == par)
			continue;
		h[it] = h[node] + 1;
		lca[it][0] = node;
		dfs(it, node);
	}
	for(auto it: d[node])
	{
		s[node][0].pb(it);
	}
	sort(s[node][0].begin(), s[node][0].end());
	while(ss(s[node][0]) > 10)
	{
		s[node][0].pop_back();
	}
}

int daj(int x, int y)
{
	if(h[x] < h[y])
		swap(x, y);
	for(int i = 16; 0 <= i; --i)
	{
		if(h[x] - (1 << i) >= h[y])
			x = lca[x][i];
	}
	if(x == y)
		return x;
	for(int i = 16; 0 <= i; --i)
	{
		if(lca[x][i] != lca[y][i])
		{
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}
void add(vector <int> &C, vector <int> &A, vector <int> &B)
{
	for(auto it: A)
		C.pb(it);
	for(auto it: B)
		C.pb(it);
	sort(C.begin(), C.end());
	while(ss(C) > 10)
	{
		C.pop_back();
	}
}
		
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; n - 1 >= i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d", &a);
		d[a].pb(i);
	}
	dfs(1, -1);
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
		{
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
			add(s[i][j], s[i][j - 1], s[lca[i][j - 1]][j - 1]);
		}
	while(q--)
	{
		int ile ;
		scanf("%d %d %d", &a, &b, &ile);
		int e = daj(a, b);
		int ha = h[a] - h[e];
		int hb = h[b] - h[e];
		int aa, bb;
		aa = a;
		bb = b;
		vector <int> w;
		for(int i = 0; 16 >= i; ++i)
		{
			if(ha & (1 << i))
			{
				for(auto it: s[aa][i])
					w.pb(it);
				aa = lca[aa][i];
			}
			if(hb & (1 << i))
			{
				for(auto it: s[bb][i])
					w.pb(it);
				bb = lca[bb][i];
			}
		}
		for(auto it: s[e][0])
			w.pb(it);
		sort(w.begin(), w.end());
		printf("%d ", min(ss(w), ile));
		while(ss(w) > 10 || ss(w) > ile)
			w.pop_back();
		for(int i = 0; min(ss(w), ile) > i; ++i)
		{
			printf("%d ", w[i]);
		}
		printf("\n");
	}
			
	
			
	
		
		
    return 0;
}