#include <cstdio>
#include <cstring>
#include <iostream>
//using namespace std;

int x, n;

int main()
{
	int i, j, k;
	scanf( "%d", &x );
	
	if ( x == 3 )
	{
		printf( "%d\n", 5 );
		return 0;
	}
	
	j = (1<<29);
	if ( x % 4 == 0 )
	{
		k = x / 4;
		for ( i = 1; i <= 1000; i++ )
		{
			if ( (i*i+1)/2 >= k )
				break;
		}
		j = (i+1)*2;
	}
	for ( i = 1; i <= 1000; i++ )
	{
		if ( ( (i*i+1)/2 >= x ) && ( i % 2 == 1 ) )
			break;
	}
	j = std::min( j, i );
	printf( "%d\n", j );
	return 0;
}