#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 300005;

int n;
int a, b;
vector <int> v[nax];
int d[nax];
int ile = 0;
int dp[nax];
int ha[nax];
void dfs(int node)
{
	if(ss(v[node]) == 0)
	{
		++ile;
		dp[node] = 0;
		return ;
	}
	int naj = 1000000000;
	for(auto it: v[node])
	{
		dfs(it);
		ha[node] += dp[it] + 1;
	}
	for(auto it: v[node])
	{
		if(d[node] == 0)
			naj=  min(naj, dp[it] + ha[node] - (dp[it] + 1));
		else
			naj = min(naj, dp[it]);
	}
		
	dp[node] = naj;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
			
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> d[i];
	for(int i = 2; n >= i; ++i)
	{
		cin >> a;
		v[a].pb(i);
	}
	dfs(1);
	cout << ile - dp[1];
	
	
	
	
	
	// fflush(stdout)
	return 0;
}