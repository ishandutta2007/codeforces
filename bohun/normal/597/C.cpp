#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int j = (1 << 17);
ll t[(1 << 18) + 9][12];
int n, k;
int tab[100005];
void add(int node, ll val, int id)
{
	node += j;
	while(node)
	{
		t[node][id] += val;
		node /= 2;
	}
}
ll sum(int node, int lewo, int prawo, int x, int y, int id)
{
	if(y >= prawo and lewo >= x)
		return t[node][id];
	int mid = (lewo + prawo) / 2;
	ll ans = 0;
	if(mid >= x)
		ans += sum(2 * node, lewo, mid, x, y, id);
	if(y > mid)
		ans += sum(2 * node + 1, mid + 1, prawo, x, y, id);
	return ans;
}
int main()
{	
	scanf("%d %d", &n, &k);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &tab[i]);
	add(0, 1, 0);
	for(int g = 1; n >= g; ++g)
		for(int i = 1; k + 1 >= i; ++i)
			{
				ll X = sum(1, 0, j - 1, 0, tab[g] - 1, i - 1);
				add(tab[g], X, i);
			}
	printf("%lld", sum(1, 0, j - 1, 0, j - 1, k + 1));
}