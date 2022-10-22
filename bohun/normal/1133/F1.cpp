#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m;
pair < int ,int > e[200005];
int d[200005];
int par[200005];
bool used[200005];
int f(int u)
{
	if(par[u] != u)
		par[u] = f(par[u]);
	return par[u];
}
void onion(int x,int y)
{
	if(f(x) == f(y))
		return ;
	par[f(x)] = f(y);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		int a,b;
		cin >> a >> b;
		e[i] = {a, b};
		d[a]++;
		d[b]++;
	}
	int maks = 0;
	int where = 0;
	for(int i = 1; n >= i; ++i)
	{
		par[i] = i;
		if(d[i] >= maks)
			{
				maks = d[i];
				where = i;
			}
	}
	for(int i = 1; m >= i; ++i)
	{
		if(e[i].fi == where or e[i].se == where)
		{
			cout << e[i].fi << " " << e[i].se << endl;
			onion(e[i].fi, e[i].se);
			used[i] = 1;
		}
	}
	for(int i = 1; m >= i; ++i)
	{
		if(used[i])
			continue;
		if(f(e[i].fi) !=  f(e[i].se))
		{
			cout << e[i].fi << " " << e[i].se << endl;
			onion(e[i].fi, e[i].se);
		}
	}
	
	
	return 0;
}