#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, t[200005][2];
vector <int> v[2];
int main()
{
	scanf("%d", &n);
	for(int j = 0; 2 > j; ++j)
		for(int i = 1; n >= i; ++i)
		{
			scanf("%d", &t[i][j]);
			if(i > 1)
			 v[j].pb(t[i][j] - t[i - 1][j]);
		}
	for(int i = 0; 2 > i; ++i)
		sort(v[i].begin(), v[i].end());
	if(v[0] == v[1] && t[1][0] == t[1][1] && t[n][0] == t[n][1])
		printf("YES\n");
	else
		printf("NO\n");
		
	return 0;
}