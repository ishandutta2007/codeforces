#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m, d;
int par[200005];
vector < pair < int ,int > > ones, ed, opt, need;
int Find(int x)
{
	if(par[x] != x)
		par[x] = Find(par[x]);
	return par[x];
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x != y)
		par[x] = y;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> d;
	for(int i = 1; m >= i; ++i)
	{
		int a, b;
		cin >> a >> b;
		if(a == 1 or b == 1)
			ones.pb({a, b});
		else
			ed.pb({a, b});
	}
	if(ss(ones) < d)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 1; n >= i; ++i)
		par[i] = i;
	for(auto it : ed)
	{
		Union(it.fi, it.se);
	}
	int ans = 0;
	for(auto it: ones)
	{
		if(Find(it.fi) != Find(it.se))
		{
			opt.pb(it);
			ans++;
			Union(it.fi, it.se);
		}
		else
		{
			need.pb(it);
		}
	}
	if(ans > d)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i = 1; d - ans >= i; ++i)
	{
		opt.pb(need[i - 1]);
	}
	for(int i = 1; n >= i; ++i)
		par[i] = i;
	for(auto it: opt)
		Union(it.fi, it.se);
	for(auto it: opt)
		cout << it.fi << " " << it.se << endl;
	for(auto it: ed)
	{
		if(Find(it.fi) != Find(it.se))
		{
			cout << it.fi << " " << it.se << endl;
			Union(it.fi, it.se);
		}
	}
	
	
	return 0;
}