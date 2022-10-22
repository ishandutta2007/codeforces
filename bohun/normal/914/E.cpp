#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, a, b;
const int nax = 200005;
vector <int> v[nax];
char s[nax];
int col[nax];
ll ans[nax];
ll now[nax];
vector <int> A, B;
int alive[nax];
int dp[nax];
ll dodaj[nax];
int nn;
int mapa[(1 << 21)];
int d[nax];
void licz(int node, int par)
{
	nn++;
	dp[node] = 1;
	for(auto it: v[node])
		if(alive[it] && it != par)
			{
				licz(it, node);
				dp[node] += dp[it];
			}
}
int daj(int node, int par)
{
	for(auto it: v[node])
		if(alive[it] && it != par && dp[it] > nn / 2)
			return daj(it, node);
	return node;
}
int cc ;
void dfs(int node, int par, int val)
{
	now[node] = 0;
	A.pb(node);
	val ^= (1 << col[node]);
	d[node] = val;
	mapa[val]++;
	for(auto it: v[node])
		if(alive[it] && it != par)
			dfs(it, node, val);
}
int fun(int maska)
{
	int pod = (1 << col[cc]);
	ll ans = 0;
	ans = mapa[(maska ^ pod)];
	for(int i = 0; 19 >= i; ++i)
	{
			ans += mapa[(maska ^ (1 << i) ^ pod)];
	}
	return ans;
}
void go(int node, int par)
{
	B.pb(node);
	mapa[d[node]]++;
	for(auto it: v[node])
		if(alive[it] && it != par)
			go(it, node);
}
ll jazda(int node, int par)
{
	ll ile = now[node];
	for(auto it: v[node])
		if(alive[it] && it != par)
		{
			ile += jazda(it, node);
		}
	return dodaj[node] = ile;
}
void decomp(int node)
{
	nn = 0;
	licz(node, -1);
	int c = daj(node, -1);
	alive[c] = 0;
	cc = c;
	// 1. DFS all
	A.clear();
	dfs(c, -1, 0);
	// 2. DFS subtrees
	for(auto it: A)
		now[it] = fun(d[it]);
	for(auto it: A)
		mapa[d[it]] = 0;
	mapa[d[c]] = 0;
	for(auto it: v[c])
		if(alive[it])
		{
			B.clear();
			go(it, c);
			for(auto i: B)
				now[i] -= fun(d[i]);
			for(auto it: B)
				mapa[d[it]] = 0;
		}	
	// 3. count answer
	jazda(c, -1);
	dodaj[c]++;
	dodaj[c] /= 2;
	for(auto it: A)
		{
			ans[it] += dodaj[it];
		}
	for(auto it: v[c])
		if(alive[it])
			decomp(it);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	scanf("%s", s + 1);
	for(int i = 1; n >= i; ++i)
	{
		col[i] = s[i] - 'a';
	}
	for(int i = 1; n >= i; ++i)
		alive[i] = 1;
	decomp(1);
	for(int i = 1; n >= i; ++i)
		printf("%lld ", ans[i]);
	
			
	return 0;
}