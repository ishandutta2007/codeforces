#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

const int nax = 100005, mod = 1e9 + 7, inf = 1e9;
int dp[nax][2], n, col[nax];
vector <int> v[nax];
int pot(int a, int b){
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return res;
}
void dfs(int node)
{
	if(ss(v[node]) == 0)
	{
		dp[node][col[node]] = 1;
		return;
	}
	int ilo = 1;
	for(auto it: v[node])
	{
		dfs(it);
		ilo = (ll) ilo * (dp[it][0] + dp[it][1]) % mod;
	}
	if(col[node] == 1)
		dp[node][1] = ilo;
	if(col[node] == 0)
		dp[node][0] = ilo;
	if(col[node] == 0)
	{
		for(auto it: v[node])
		{
			int nowy = (ll) ilo * pot(dp[it][0] + dp[it][1], mod - 2) % mod;
			dp[node][1] = (dp[node][1] + (ll) nowy * dp[it][1] % mod) % mod;
		}
	}
}
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	scanf("%d", &n);
	for(int i = 1; n > i; ++i)
	{
		int a;
		scanf("%d", &a);
		v[a].pb(i);
	}
	for(int i = 0; n > i; ++i)
		scanf("%d", &col[i]);
	dfs(0);
	printf("%d\n", dp[0][1]);		
	
	return 0;
}