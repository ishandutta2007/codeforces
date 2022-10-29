#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 100000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
int main()
{
	int num;
	scanf("%d", &num);
	invinit();
	ll r = 1;
	int s = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		r = r*com(s + z - 1, z - 1) % mod;
		s += z;
	}
	printf("%I64d\n", r);
}