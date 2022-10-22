#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) ((int)v.size())
using namespace std;
int n;
char s[5005][5005];
int pop[5005];
int col[5005];
int kon, pocz;
void dfs(int u)
{
	col[u] = 1;
	for(int j = 1; n >= j; ++j)
	{
		int it = j;
		if(s[u][j] == '0')
			continue;
		if(col[it] == 0)
		{
			pop[it] = u;
			dfs(it);
		}
		if(col[it] == 1 and pocz == 0)
		{
			pocz = it;
			kon = u;
		}
	}
	col[u] = 2;
}
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		scanf("%s", s[i] + 1);
	}
	for(int i = 1; n >= i; ++i)
		if(!col[i])
			dfs(i);
	if(pocz == 0)
		{
			cout << -1;
			return 0;
		}
	vector < int > e;
	int u = kon;
	while(u != pocz)
	{
		e.pb(u);
		u = pop[u];
	}
	e.pb(pocz);
	reverse(e.begin(), e.end());
	for(int j = 2; ss(e) > j; ++j)
		{
			if(s[e[j]][e[0]] == '1')
				{	
					cout << e[0] << " " << e[j - 1] << " " << e[j];
					return 0;
				}
		}
	
	return 0;
}