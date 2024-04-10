/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<ll, ll> > segs;
bool inside(ll x, ll l, ll r)
{
	return x >= l && x <= r;
}
bool check(ll l, ll r)
{
	for (int i = 0; i < (int)segs.size(); i++)
	{
		if (inside(l, segs[i].first, segs[i].second) || inside(r, segs[i].first, segs[i].second)) return false;
		if (inside(segs[i].first, l, r) || inside(segs[i].second, l, r)) return false;
	}
	return true;
}
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		ll l, x;
		scanf("%lld %lld", &l, &x);
		vector<ll> toCheck;
		if (check(l, l + x - 1))
		{
			printf("%lld %lld\n", l, l + x - 1);
			segs.push_back(make_pair(l, l + x - 1));
			continue;
		}
		toCheck.push_back(1);
		for (int j = 0; j < (int)segs.size(); j++)
		{
			toCheck.push_back(segs[j].second + 1);
		}
		sort(toCheck.begin(), toCheck.end());
		for (int j = 0; j < (int)toCheck.size(); j++)
		{
			ll cl = toCheck[j], cr = cl + x - 1;
			if (check(cl, cr))
			{
				printf("%lld %lld\n", cl, cr);
				segs.push_back(make_pair(cl, cr));
				break;
			}
		}
	}
	return 0;
}