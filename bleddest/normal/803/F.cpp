#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>

const int MOD = int(1e9) + 7;

using namespace std;

struct modInt
{
	int x;
	modInt() : x(0) {};
	modInt(int x) : x(x) {};
};

modInt operator +(const modInt& x, const modInt& y)
{
	int z = x.x + y.x;
	while (z >= MOD)
		z -= MOD;
	while (z < 0)
		z += MOD;
	return modInt(z);
}

modInt operator -(const modInt& x, const modInt& y)
{
	int z = x.x - y.x;
	while (z >= MOD)
		z -= MOD;
	while (z < 0)
		z += MOD;
	return modInt(z);
}

modInt operator *(const modInt& x, const modInt& y)
{
	return modInt((x.x * 1ll * y.x) % MOD);
}

modInt operator ^(const modInt& x, const modInt& y)
{
	modInt res(1);
	modInt xx = x;
	int yx = y.x;
	while (yx > 0)
	{
		if (yx % 2 == 1)
			res = res * xx;
		xx = xx * xx;
		yx /= 2;
	}
	return res;
}

modInt operator /(const modInt& x, const modInt& y)
{
	return x * (y ^ (MOD - 2));
}

bool operator <(const modInt& x, const modInt& y)
{
	return x.x < y.x;
}

ostream& operator <<(ostream& out, const modInt& x)
{
	return out << x.x;
}

const int N = 200043;

int min_divisor[N];
int mu[N];
int D[N];
int a[N];
int cnt[N];
int n;

void precalc()
{
	for (int i = 2; i < N; i++)
		for (int j = i; j < N; j += i)
			if (min_divisor[j] == 0)
				min_divisor[j] = i;
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			D[i] += cnt[j];
	mu[1] = 1; 
	for (int i = 2; i < N; i++)
	{
		int d = min_divisor[i];
		if (d == min_divisor[i / d])
			mu[i] = 0;
		else
			mu[i] = mu[i / d] * (-1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	precalc();
	modInt ans = 0;
	for (int i = 1; i <= 100000; i++)
		ans = (ans + modInt(mu[i]) * ((modInt(2) ^ D[i]) - 1));
	cout << ans << endl;
	return 0;
}