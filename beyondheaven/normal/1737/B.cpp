#include <bits/stdc++.h>
using ll = long long;

ll find(ll x)
{
	ll l = 1, r = x, ans = 0;
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		if(mid <= x / mid) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

ll calc(ll r)
{
	ll x = find(r);
	ll pre = 3 * (x - 1);
	ll len = r - x * x + 1;
	return pre + (len + x - 1) / x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		ll l, r; std::cin >> l >> r;
		std::cout << calc(r) - (l == 1 ? 0 : calc(l - 1)) << "\n";
	}
	return 0;
}