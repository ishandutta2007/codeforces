#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int nax = 200005;
int n;
int d[nax];
vector <int> v[nax];
int a, b;
int sito[nax];
vector <int> daj[nax];
int ans = 0;
vector <int> e[nax];
bitset <nax> byl;
int dp[nax];
void dfs(int node, int par)
{
	byl[node] = 1;
	dp[node] = 0;
	int max1 = 0, max2 = 0;
	for(auto it: e[node])
	{
		if(it != par and byl[it] == 0)
		{
			dfs(it, node);
			int w = dp[it] + 1;
			if(w > max1)
				swap(max1, w);
			if(w > max2)
				swap(max2, w);
		}
	}
	dp[node] = max1;
	ans = max(ans, max1 + max2 + 1);
}
void go(int val)
{
	if(daj[val].empty())
		return;
	for(auto it: daj[val])
	{
		byl[it] = 0;
		e[it].clear();
		for(auto i: v[it])
			if(d[i] % val == 0)
				e[it].pb(i);
	}
	for(auto it: daj[val])
		{
			if(!byl[it])
				dfs(it, -1);
		}
}
	
int main()
{
	scanf("%d", &n);
	for(int i = 0; n > i; ++i)
		scanf("%d", &d[i]);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 2; nax - 5 >= i; ++i)
	{
		if(sito[i] == 0)
			for(int j = i; nax - 5 >= j; j += i)
				sito[j] = i;
	}
	for(int i = 0; n > i; ++i)
	{
		int g = d[i];
		while(sito[g])
		{
			daj[sito[g]].pb(i);
			g /= sito[g];
		}
	}
	for(int i = 2; 200000 > i; ++i)
		go(i);
	printf("%d", ans);
	
	return 0;
}