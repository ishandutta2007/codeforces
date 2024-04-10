#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;
ll k;
int n;
int lca[nax][40];
ll sum[nax][40];
int mini[nax][40];
int cost[nax];
pair <ll, int> daj(int node)
{
	ll s = 0;
	int ja = 1e9;
	for(int i = 0; 40 > i; ++i)
		if((1LL << i) & k)
		{
			ja = min(ja, mini[node][i]);
			s += sum[node][i];
			node = lca[node][i];
		}
	return {s, ja};
}
int main()
{
	scanf("%d %lld", &n, &k);
	for(int i = 0; n > i; ++i)
		scanf("%d", &lca[i][0]);
	for(int i = 0; n > i; ++i)
		{
			scanf("%d", &cost[i]);
			mini[i][0] = cost[i];
			sum[i][0] = cost[i];
		}
	for(int j = 1; 40 > j; ++j)
		for(int i = 0; n > i; ++i)
		{
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
			sum[i][j] = sum[i][j - 1] + sum[lca[i][j - 1]][j - 1];
			mini[i][j] = min(mini[i][j - 1], mini[lca[i][j - 1]][j - 1]);
		}
	for(int i = 0; n > i; ++i)
	{
		pair <ll, int> r = daj(i);
		printf("%lld %d\n", r.fi, r.se);
	}
	
	return 0;
}