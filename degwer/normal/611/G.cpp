#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
typedef pair<ll, ll>pii;
ll area;
ll det(pii a, pii b)
{
	return a.first*b.second - a.second*b.first;
}
ll getarea(pii a, pii b, pii c)
{
	pii s = make_pair(a.first - b.first, a.second - b.second), t = make_pair(a.first - c.first, a.second - c.second);
	return -det(s, t);
}
ll solve(vector<pii>vec)
{
	ll ret = 0;
	int pt = 2;
	ll sx = 0;
	ll sy = 0;
	ll men = 0;
	ll now = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		for (;;)
		{
			ll a = getarea(vec[i], vec[(pt + vec.size() - 1) % vec.size()], vec[pt]);
			if ((men + a)  > area/2)break;
			men += a;
			sx += vec[pt].first;
			sy += vec[pt].second;
			sx %= mod;
			sy %= mod;
			now += men;
			now %= mod;
			pt++;
			pt %= vec.size();
		}
		ll ko = (pt + vec.size() - i - 2) % vec.size();
		ret += ((area%mod)*(ko) + (mod + mod - now - now));
		ret %= mod;
		pii a = vec[i], b = vec[(i + 1) % vec.size()];
		men -= getarea(a, b, vec[(pt + vec.size() - 1) % vec.size()]);
		now += mod + ((b.first - a.first)*(sy - (a.second*ko) % mod) - (b.second - a.second)*(sx - (a.first*ko) % mod)) % mod;
		now %= mod;
		sx += mod - vec[(i + 2) % vec.size()].first;
		sx %= mod;
		sy += mod - vec[(i + 2) % vec.size()].second;
		sy %= mod;
	}
	return ret;
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>vec;
	for (int i = 0; i < num; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		vec.push_back(make_pair(za, zb));
	}
	for (int i = 2; i < num; i++)
	{
		area += getarea(vec[0], vec[i - 1], vec[i]);
	}
	ll a = solve(vec);
	printf("%I64d\n", a);
}