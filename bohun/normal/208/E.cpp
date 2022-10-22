#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n;
const int nax = 100005;
vector <int> v[nax];
int q;
vector <pair<int, int>> qu[nax];
int ans[nax];
int h[nax];
int ile[2 * nax];
int siz[nax];
int in[nax], out[nax];
vector <int> root;
int big[nax];
int tim = 0;
int seg[nax];
int lca[nax][17];
void dfs(int node, int par)
{
	siz[node] = 1;
	int naj = 0, id = 0;
	seg[tim] = node;
	in[node] = tim++;
	for(auto it: v[node])
	{
		lca[it][0] = node;
		h[it] = h[node] + 1;
		dfs(it, node);
		siz[node] += siz[it];
		if(siz[it] > naj)
		{
			naj = siz[it];
			id = it;
		}
	}
	out[node] = tim - 1;
	big[node] = id;
}
void go(int node, int par, int hold = 0)
{
	for(auto it: v[node])
		if(it != big[node])
			go(it, node, 0);
	if(big[node])
		go(big[node], node, 1);
	ile[h[node]]++;
	for(auto it: v[node])
		if(it != big[node])
			for(int i = in[it]; out[it] >= i; ++i)
				ile[h[seg[i]]]++;
	for(auto it: qu[node])
		ans[it.se] = ile[h[node] + it.fi];
	if(!hold)
		for(int i = in[node]; i <= out[node]; ++i)
			ile[h[seg[i]]]--;
}			
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		if(!a)
			root.pb(i);
		else
			v[a].pb(i);
	}
	for(auto it: root)
		dfs(it, -1);	
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if(h[a] - b < 0)
			continue;
		for(int k = 16; 0 <= k; --k)
			if((1 << k) & b)
				a = lca[a][k];
		qu[a].pb({b, i});
	}
	for(auto it: root)
		go(it, -1);
	for(int i = 1; q >= i; ++i)
		printf("%d ", max(0, ans[i] - 1)); 
	
	return 0;
}