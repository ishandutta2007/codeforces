#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b, c;
	
	scanf("%lld%lld%lld", &a, &b, &c);
	
	printf("%lld\n", max(max(c * 2 + min(a, b) * 2, c * 2 + min(a * 2 + 1, b * 2 - 1)), c * 2 + min(a * 2 - 1, b * 2 + 1)));
	
	return 0;
}