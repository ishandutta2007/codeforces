#include <bits/stdc++.h>
using ll = long long;
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		ll a, b, c; std::cin >> a >> b >> c;
		std::cout << a + ll(1e9) * b << " " << b << " " << c << "\n";
	}
	return 0;
}