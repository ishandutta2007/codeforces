#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>r;
ll get(ll a, ll k)
{
	return (1 + a*k - a + 1)*k / 2;
}
int main()
{
	ll x;
	scanf("%I64d", &x);
	for (ll i = 1; i*i <= x; i++)
	{
		if (x%i == 0)
		{
			r.push_back(get(i, x / i));
			if (i*i < x)r.push_back(get(x / i, i));
		}
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++)printf("%I64d ", r[i]);
}