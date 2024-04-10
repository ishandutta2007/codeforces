#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	ll s = max(1LL, b - a), t = min(a, b - 1);
	printf("%I64d\n", max(0LL, (t - s + 1) / 2));
}