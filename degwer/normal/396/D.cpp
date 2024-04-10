#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1048576
typedef long long ll;
ll mod = 1000000007;
class BIT
{
public:
	int bit[SIZE + 1];
	void add(int a, int b)
	{
		a++;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		a++;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
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
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	for (int i = 0; i < num; i++)bi.add(i + 1, 1);
	ll ans = 0;
	ll ad = 0;
	invinit();
	for (int i = 0; i < num; i++)
	{
		ll n = num - i - 1;
		ll x = bi.get(vec[i]) - 1;
		ll t = kai[n] * ((n*(n - 1) % mod*inv[4] % mod * x % mod) + (x*(x - 1) % mod*inv[2] % mod));
		t += ad*x%mod*kai[n] % mod;
		ans += t;
		ans %= mod;
		ad += x;
		ad %= mod;
		bi.add(vec[i], -1);
	}
	ll slf = 0;
	for (int i = 0; i < num; i++)
	{
		slf += bi.get(SIZE - 1) - bi.get(vec[i]);
		bi.add(vec[i], 1);
	}
	ans += slf;
	ans %= mod;
	printf("%I64d\n", ans);
}