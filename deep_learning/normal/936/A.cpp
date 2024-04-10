#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("936A.in", "r", stdin); 
#endif
	ll k, d, t; 
	scanf("%lld%lld%lld", &k, &d, &t); 
	ll per = (k + d - 1) / d; 
	ll a = k, b = per * d - a; 
	ll res = 2 * t / (a + a + b) * (a + b); 
	if (2 * t % (a + a + b) < 2 * a)
		printf("%.6lf\n", res + (double)(2 * t % (a + a + b)) / 2);
	else
		printf("%lld\n", res + a + (2 * t % (a + a + b) - a * 2));
	return 0; 
}