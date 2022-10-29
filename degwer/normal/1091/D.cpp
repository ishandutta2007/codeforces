#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 998244353;
int main()
{
	int n;
	scanf("%d",&n);
	ll ans = 1, k = 1;
	for (int i = 1; i <= n; i++)
	{
		k = k*i%mod;
		ans = (ans*i + k - i) % mod;
	}
	printf("%I64d\n", ans);
}