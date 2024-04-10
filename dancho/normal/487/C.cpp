#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

long long qpow(long long v, long long st, long long m)
{
	//~ printf("QP %lld %lld %lld ", v, st, m);
	long long r = 1;
	while (st)
	{
		if (st & 1)
		{
			r = r * v;
			if (r >= m)
				r %= m;
		}
		v = v * v;
		if (v >= m)
			v %= m;
		st /= 2;
	}
	//~ printf("-> %lld\n", r);
	return r;
}

vector<int> divs;

int n;
int main()
{
	scanf("%d", &n);
	if (n == 1)
	{
		printf("YES\n1\n");
		return 0;
	}
	if (n == 4)
	{
		printf("YES\n");
		printf("1\n3\n2\n4\n");
		return 0;
	}
	if (!isPrime(n))
	{
		printf("NO\n");
		return 0;
	}
	
	int q = n - 1;
	int x = q;
	for (int i = 2; i <= q; ++i)
	{
		if (x % i == 0)
		{
			//~ printf("DIV %d\n", i);
			divs.push_back(i);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	
	//~ printf("%d %d\n", (int) divs.size());
	
	int g;
	for (g = 1; g <= n; ++g)
	{
		bool ok = true;
		for (int i = 0; i < (int) divs.size() && ok; ++i)
		{
			//~ printf("GG %d %d : %d -> %lld\n", g, divs[i], q / divs[i], qpow(g, q / divs[i], n));
			if (qpow(g, q / divs[i], n) == 1)
				ok = false;
		}
		if (ok)
			break;
	}
	
	//~ printf("G %d\n", g);
	
	printf("YES\n");
	vector<int> ans(n);
	ans[0] = 1;
	ans[n - 1] = n;
	for (int i = 1; i < n - 1 - i; ++i)
	{
		//~ printf("SET [%d] %d %d : %lld %lld\n", g, i, n - 1 - i, qpow(g, i, n), qpow(g, n - i - 1, n));
		if (i & 1)
		{
			ans[i] = qpow(g, i, n);
			ans[n - 1 - i] = qpow(g, n - i - 1, n);
		}
		else
		{
			ans[i] = qpow(g, n - i - 1, n);
			ans[n - 1 - i] = qpow(g, i, n);
		}
	}
	if (n > 2)
		ans[n / 2] = qpow(g, (n - 1) / 2, n);
		
	set<int> us;
	int k = 1;
	for (int i = 0; i < n; ++i)
	{
		k = ((long long) k * ans[i]) % n;
		if (us.find(k) != us.end())
			fprintf(stderr, "DUP!!\n");
		us.insert(k);
		printf("%d\n", ans[i]);
	}
	
	return 0;
}