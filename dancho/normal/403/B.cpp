#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

bool us[1<<20];
vector<int> primes;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int n, m;
int a[1<<20];
int g[1<<20];
set<int> bad;

long long beg = 0;

long long eval(long long x)
{
	long long j = 2, res = 0;
	int l = 0;
	while (j * j <= x)
	{
		while (x % j == 0)
		{
			if (bad.find(j) != bad.end())
				--res;
			else
				++res;
			x /= j;
		}
		j = primes[++l];
	}
	if (x != 1)
	{
		if (bad.find(x) != bad.end())
			--res;
		else
			++res;
	}
	return res;
}

long long getDP(int va, int p)
{
	long long sl = 0;
	beg:;
	if (p < 0)
		return sl;
	if (va == 1)
		return sl;
	// don't take;
	// try to take.
	long long rm = a[0] / va;
	long long gc = g[p] / rm;
	if (eval(gc) < 0)
	{
		sl += -(p + 1) * eval(gc);
		va = va / gc;
		--p;
		goto beg;
	}
	else
	{
		--p;
		goto beg;
	}
	return sl;
}

int main()
{
	memset(us, 0, sizeof(us));
	for (int i = 2; i <= 1<<20; ++i)
	{
		if (!us[i])
		{
			primes.push_back(i);
			for (int j = i + i; j <= 1<<20; j += i)
				us[j] = 1;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		bad.insert(k);
	}

	beg = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			g[i] = a[i];
		else
			g[i] = gcd(g[i-1], a[i]);
		long long x = a[i];
		long long j = 2;
		int l = 0;
		j = primes[l];
		while (j * j <= x)
		{
			while (x % j == 0)
			{
				if (bad.find(j) != bad.end())
					--beg;
				else
					++beg;
				x /= j;
			}
			j = primes[++l];
		}
		if (x != 1)
		{
			if (bad.find(x) != bad.end())
				--beg;
			else
				++beg;
		}
	}
	
	cout << beg + getDP(a[0], n-1) << '\n';
	return 0;
}