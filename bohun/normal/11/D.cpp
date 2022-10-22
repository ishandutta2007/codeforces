#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, m, a, b;
vector <int> v[20];
ll dp[(1 << 20)][20];
int k[20][20];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; m >= i; ++i)
	{
		scanf("%d %d", &a, &b);
		--a;
		--b;
		k[a][b] = 1;
		k[b][a] = 1;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 0; n > i; ++i)
		dp[(1 << i)][i] = 1;
	for(int i = 1; (1 << n) > i; ++i)
	{
		int ile = __builtin_popcount(i);
		if(ile == 1)
			continue;
		int naj = 0;
		while(!((1 << naj) & i))
			++naj;
		for(int j = 0; n > j; ++j)
		{
			if(naj == j or ((1 << j) & i) == 0)
				continue;
			for(int g = 0; n > g; ++g)
				if(k[g][j] == 1)
					dp[i][j] += dp[(i ^ (1 << j))][g];
		}
	}
	ll ans = 0;
	for(int i = 0; n > i; ++i)
		for(int maska = 1; (1 << n) > maska; ++maska)
		{
			if(__builtin_popcount(maska) <= 2)
				continue;
			int naj = 0;
			while(!((1 << naj) & maska))
				++naj;
			if(k[i][naj] == 1)
				ans += dp[maska][i];
		}
	cout << ans / 2;
	
	
	
	return 0;
}