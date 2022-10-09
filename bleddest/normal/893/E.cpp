#include<iostream>
#include<map>

using namespace std;

int m;
int phi;

int add(int x, int y)
{
	x += y;
	((x + y) % m + m) % m;
	while(x >= m)
		x -= m;
	while(x < 0)
		x += m;
	return x;
}

int sub(int x, int y)
{
	return add(x, -y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % m;
}

int binpow(int x, long long y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int divide(int x, int y)
{
	return mul(x, binpow(y, phi - 1));
}

const int N = 1000043;

int fact[N];
int inv_fact[N];

int C(int n, int k)
{
	if(n < 0 || n < k || k < 0)
		return 0;
	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

int d[N];

map<int, int> factorize(int x)
{
	map<int, int> res;
	for(int i = 2; i * i <= x; i++)
	{
		while(x % i == 0)
		{
			res[i]++;
			x /= i;
		}
	}
	if(x != 1)
		res[x]++;
	return res;
}

int get(int x, int y)
{
	map<int, int> f = factorize(x);
	int ans = 1;
	for(auto it = f.begin(); it != f.end(); it++)
	{
		int cur = it->second;
		ans = mul(ans, C(cur + y - 1, cur));
	}
	ans = mul(ans, binpow(2, y - 1));
	return ans;
}

int main()
{
	m = int(1e9) + 7;
	phi = m - 1;
	fact[0] = 1;
	for(int i = 1; i < N; i++)
		fact[i] = mul(fact[i - 1], i);
	for(int i = 0; i < N; i++)
		inv_fact[i] = binpow(fact[i], phi - 1);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", get(x, y));
	}
}