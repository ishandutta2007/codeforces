#include <iostream>
#include <utility>
#include <cstdio>
#define mp make_pair
using namespace std; 
typedef long long ll; 
pair<ll, ll> ans;
void work(ll m, ll cnt, ll tot)
{
	if (!m)
	{
		ans = max(ans, mp(cnt, tot)); 
		return; 
	}
	ll x = 1; 
	for (; x * x * x <= m; x++); 
	x--; 
	work(m - x * x * x, cnt + 1, tot + x * x * x); 
	if (x - 1 >= 0)
		work(x * x * x - 1 - (x - 1) * (x - 1) * (x - 1), cnt + 1, tot + (x - 1) * (x - 1) * (x - 1)); 
}
int main()
{
	// freopen("B.in", "r", stdin); 
	ll m; 
	scanf("%lld", &m); 
	work(m, 0, 0); 
	printf("%lld %lld\n", ans.first, ans.second);
	return 0; 
}