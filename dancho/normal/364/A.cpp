#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int a;
char s[5020];
long long ps[5020];

long long prod[5020 * 5020];

int main()
{
	long long ans = 0;
	scanf("%d", &a);
	scanf("%s", s);
	int l = strlen(s);
	ps[0] = 0;
	for (int i = 0; i < l; i++)
	{
		ps[i+1] = ps[i] + s[i]-'0';
	}
	
	int k = 0;
	for (int i = 1; i <= l; ++i)
	{
		for (int j = i; j <= l; ++j)
		{
			prod[k++] = ps[j]-ps[i-1];
		}
	}
	std::sort(prod, prod+k);
	
	if (a == 0)
	{
		long long ci = std::upper_bound(prod, prod+k, 0) - std::lower_bound(prod, prod+k, 0);
		
		ans = ci*k*2LL - ci*ci;
		std::cout << ans << std::endl;
		return 0;
	}
	
	for (long long i = 1; i * i <= a; ++i)
	{
		if (a%i == 0)
		{
			long long ci = std::upper_bound(prod, prod+k, i) - std::lower_bound(prod, prod+k, i);
			long long cj = std::upper_bound(prod, prod+k, a/i) - std::lower_bound(prod, prod+k, a/i);
			if (i != a/i)
			{
				ans += (long long) ci*cj*2LL;
			}
			else
			{
				ans += (long long) ci * ci;
			}
		}
	}
	
	std::cout << ans << std::endl;
	return 0;
}