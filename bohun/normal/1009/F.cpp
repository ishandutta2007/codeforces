#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;
int n, a, b;
const int nax = 1000005;
vector <int> v[nax];
int ans[nax], siz[nax], big[nax], h[nax];
int war, krol;
int hi[nax + 100];
int seg[nax + 100], in[nax], out[nax];
int tim = 0;
void dfs(int node, int par)
{
	seg[tim] = node;
	in[node] = tim++;
	siz[node] = 1;
	int naj = -1, id = -1;
	for(auto it: v[node])
	{
		if(it != par)
		{
			h[it] = h[node] + 1;
			dfs(it, node);
			if(siz[it] > naj)
			{
				id = it;
				naj = siz[it];
			}
			siz[node] += siz[it];
		}
	}
	out[node] = tim - 1;
	big[node] = id;
}
void akt(int node, int val)
{
	hi[h[node]] += val;
	if(hi[h[node]] > war || (hi[h[node]] == war && h[node] < krol))
	{
		krol = h[node];
		war = hi[h[node]];
	}
}
void go(int node, int par, bool keep)
{
	for(auto it: v[node])
	{
		if(it != par && big[node] != it)
			go(it, node, 0);
	}
	if(big[node] != -1)
		go(big[node], node, 1);
	akt(node, 1);
	for(auto it: v[node])
		if(it != par && it != big[node])
			for(int i = in[it]; out[it] >= i; ++i)
				akt(seg[i], 1);
	ans[node] = krol - h[node];
	big[node] = -1;
	if(keep == 0)
		{
			for(int i = in[node]; out[node] >= i; ++i)
				hi[h[seg[i]]] = 0;
			krol = war = 0;
		}
}
		
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, -1);
	go(1, -1, 0);
	for(int i = 1; n >= i; ++i)
		printf("%d\n", ans[i]);
	return 0;
}