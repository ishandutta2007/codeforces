#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;
int n, m, q;
vector <int> v[nax];
int a, b, c;
int d[nax];
int lca[nax][17], h[nax];
vector <int> wynik[nax][17], zbior[nax];
void dfs(int node, int par)
{
	wynik[node][0] = zbior[par];
	for(auto it: v[node])
		if(it != par)
		{
			h[it] = h[node] + 1;
			lca[it][0] = node;
			dfs(it, node);
		}
}
void czysc(vector <int> &s)
{
	while(ss(s) > 10)
		s.pop_back();
}
int daj(int x, int y)
{
	if(h[x] < h[y])
		swap(x, y);
	for(int i = 16; 0 <= i; --i)
		if(h[x] - (1 << i) >= h[y])
			x = lca[x][i];
	if(x == y)
		return x;
	for(int i = 16; 0 <= i; --i)
		if(lca[x][i] != lca[y][i])
		{
			x = lca[x][i];
			y = lca[y][i];
		}
	return lca[x][0];
}
vector <int> A;
void go(int node, int up)
{
	if(up <= 0)
		return ;
	vector <int> B;
	for(int i = 16; i >= 0; --i)
		if((1 << i) & up)
		{
			for(auto it: wynik[node][i])
				B.pb(it);
			node = lca[node][i];
		}
	sort(B.begin(), B.end());
	czysc(B);
	for(auto it: B)
		A.pb(it);
}
	
int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 1; m >= i; ++i)
	{
		scanf("%d", &d[i]);
		zbior[d[i]].push_back(i);
	}
	for(int i = 1; n >= i; ++i)
		sort(zbior[i].begin(), zbior[i].end()), czysc(zbior[i]);
	dfs(1, -1);
	for(int j = 1; j <= 16; ++j)
		for(int i = 1; n >= i; ++i)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
	
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
		{
			for(auto it: wynik[i][j - 1])
				wynik[i][j].pb(it);
			for(auto it: wynik[lca[i][j - 1]][j - 1])
				wynik[i][j].pb(it);
			sort(wynik[i][j].begin(), wynik[i][j].end());
			czysc(wynik[i][j]);
		}
	
	for(int i = 1; q >= i; ++i)
	{
		A.clear();
		scanf("%d %d %d", &a, &b, &c);
		int hh = h[daj(a, b)];
		int w = daj(a, b);
		go(a, h[a] - hh - 1);
		go(b, h[b] - hh - 1);
		if(a != w)
		for(auto it: zbior[a])
			A.pb(it);
		if(b != w)
		for(auto it: zbior[b])
			A.pb(it);
		for(auto it: zbior[w])
			A.pb(it);
		int k = min(c, ss(A));
		sort(A.begin(), A.end());
		czysc(A);
		printf("%d ", k);
		for(int i = 0; k > i; ++i)
			printf("%d ", A[i]);
		printf("\n");
	}
	
		
		
	return 0;
}