#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int get(ll a)
{
	ll r = 0;
	for (;;)
	{
		if (a == 0)return r;
		r += a % 10, a /= 10;
	}
}
int main()
{
	ll z;
	scanf("%I64d", &z);
	ll t = 1;
	int maxi = 0;
	for (int i = 0; i < 14; i++)
	{
		if (t - 1 > z)break;
		maxi = max(maxi, get(t - 1) + get(z - t + 1));
		t *= 10;
	}
	printf("%d\n", maxi);
}