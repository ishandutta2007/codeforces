#include <iostream>
#include <utility>
#include <cstdio>
#define mp make_pair
using namespace std; 
typedef long long ll; 
pair<int, ll> st[100005]; 
int arr[100005]; 
int main()
{
	// freopen("878B.in", "r", stdin); 
	int n, k, m, tp = 0; 
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = 0; i < n; i++)
	{
		if (!tp || st[tp - 1].first != arr[i])
			st[tp++] = mp(arr[i], 1); 
		else
			(++st[tp - 1].second) %= k; 
		if (tp && !st[tp - 1].second)
			tp--; 
	}
	ll x = 0, y = 0; 
	for (int i = 0; i < tp; i++)
		x += st[i].second;  
	int l = 0, r = tp - 1;  
	while (l < r && st[l].first == st[r].first && !((st[l].second + st[r].second) % k))
		y += st[l++].second + st[r--].second;  
	ll ans = 0; 
	if (l == r)
	{  
		if(!(st[l].second * m % k))
			ans -= y;
		ans += x * m - y * (m - 1) - (st[l].second * m / k * k);
	}  
	else
	{
		if(st[l].first == st[r].first)
			y += (st[l].second + st[r].second) / k * k;
		ans = x * m - y * (m - 1);  
	}
	printf("%lld\n", ans);
	return 0; 
}