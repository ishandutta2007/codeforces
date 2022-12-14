#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

long long n;
long long cnt = 0;
int ld;
long long divs[1<<18];

int main()
{
	std::cin >> n;
	
	if ( n % 3 != 0 )
	{
		std::cout << 0 << "\n";
		return 0;
	}
	n = n / 3;
	
	int i, j;
	long long k;
	ld = 0;
	for ( k = 2; k*k*k <= n; k++ )
	{
		if ( n % k == 0 )
		{
			divs[++ld] = k;
		}
	}
	
	long long slow = 0;
	for ( k = 2; k*k <= n; k++ )
	{
		if ( n % k != 0 ) continue;
		long long m = n/k;
		int le, ri, mi;
		le = 1; ri = ld+1;
		while ( le + 1 < ri )
		{
			mi = (le+ri)/2;
			if ( divs[mi] <= k )
				le = mi;
			else
				ri = mi;
		}
		if ( le > ld )
			le = ld;
		while ( (le > 0 ) && ( k > (m+divs[le]-1)/divs[le] ) )
			le--;
		while ( ( le > 0 ) && ( divs[le] > k ) )
			le--;
		for ( i = le; i > 0; i-- )
		{
			slow++;
			if ( ( divs[i] + k <= m/divs[i] ) )
				break;
			if ( m % divs[i] == 0 )
			{
				if ( divs[i] + k > m/divs[i] )
				{
					if ( (divs[i] + k + m/divs[i])%2 == 0 )
					{
						if ( ( divs[i] == k ) && ( divs[i] == m/divs[i] ) )
							cnt++;
						else if ( ( divs[i] == k ) || ( divs[i] == m/divs[i] ) || ( k == m/divs[i] ) )
							cnt += 3;
						else
							cnt += 6;
					}
				}
				if ( divs[i] + k <= m/divs[i] )
					break;
			}
		}
	}
	
	std::cout << cnt << "\n";
	return 0;
}