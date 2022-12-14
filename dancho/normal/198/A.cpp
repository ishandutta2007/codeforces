#include <cstdio>
#include <iostream>
#include <cstring>

long long k, b, n, t;
long long p;

int main()
{
	std::cin >> k >> b >> n >> t;
	if ( k != 1 )
	{
		p = n;
		long long sk = 1;
		while ( t*k-t+b >= sk*(b-1+k) )
		{
			//std::cout << p << " " << t*k-t+b << " " << sk*(b-1+k) << "\n";
			if ( p < 0 ) break;
			p--;
			sk = sk * k;
		}
		p++;
		if ( p < 0 ) p = 0;
		std::cout << p << "\n";
	}
	else
	{
		p = n;
		while ( t+b*p >= 1+b*n )
			p--;
		p++;
		if ( p < 0 )
			p = 0;
		std::cout<< p << "\n";
	}
	return 0;
}