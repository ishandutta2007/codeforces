#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;
const int nax = 1e5 + 5;
int n;
int val[nax];
vector < int > v[nax];
int a, b;
int dp[nax], alive[nax];
ll ans = 0;
int nn = 0;
int A[50][2], B[50][2];
void go(int e)
{
    for(int i = 0; 20 > i; ++i)
       B[i][(((1 << i) & e) > 0)]++;
}
void licz(int u, int par)
{
    nn++;
    dp[u] = 1;
    for(auto it: v[u])
    {
        if(it != par and alive[it])
        {
            licz(it, u);
            dp[u] += dp[it];
        }
    }
}
int daj(int u, int par)
{
    for(auto it: v[u])
    {
        if(it != par and alive[it] and dp[it] > nn/2)
            return daj(it, u);
    }
    return u;
}
void add(int u, int par, int ok, int ile)
{
    ile ^= val[u];
    go(ile);
    for(auto it: v[u])
    {
        if(par != it and alive[it])
        {
            if(ok == u)
            {
                for(int i = 0; 20 > i; ++i)
                    {
                        A[i][0] += B[i][0];
                        A[i][1] += B[i][1];
                        B[i][0] = B[i][1] = 0;
                    }
            }
            add(it, u, ok, ile);
        }
    }
    if(u != ok)
    for(int i = 0; 20 > i; ++i)
    {
        int bit = (((1 << i) & val[ok]) > 0);
        int bi = (((1 << i) & ile) > 0);
        ans += (ll)(1 << i) * A[i][(bit ^ !bi)];
    }
}
void decomp(int u)
{
    nn = 0;
    licz(u, -1);
    int cen = daj(u, -1);
    alive[cen] = 0;
    for(int i = 0; 20 > i; ++i)
        A[i][0] = B[i][0] = A[i][1] = B[i][1] = 0;
    add(cen, -1, cen, 0);
    for(auto it: v[cen])
    {
        if(alive[it])
            decomp(it);
    }
}
int main(int argc, char** argv) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> val[i];
	for(int i = 2; n >= i; ++i)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 1; n >= i; ++i)
	    alive[i] = 1;
	for(int i = 1; n >= i; ++i)
	    ans += val[i];
	decomp(1);
	cout << ans;
		
	return 0;
}