#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

ll Gcd(ll a, ll b)
{
	if (!b)
		return a;
	return Gcd(b , a % b);
}

ll Lcm(ll a, ll b)
{
	ll gc = Gcd(a, b);
	return (a / gc) * b;
}

int main()
{
	ll n, k;

	scanf("%lld%lld", &n, &k);

	ll dosad = 1;
	for (int i=0; i<n; i++) {
		ll tmp;
		scanf("%lld", &tmp);
		dosad = Gcd(k, Lcm(tmp, dosad));
	}

	printf("%s\n", dosad == k ? "Yes" : "No");

	return 0;
}