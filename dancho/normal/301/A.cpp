#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

bool cmp( int a, int b )
{
	return ia( a ) < ia( b );
}

int n;
int a[1024];

int main()
{
	int i, j, k;
	k = 0;
	j = 0;
	int b0 = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= 2*n-1; i++ )
	{
		scanf( "%d", &a[i] );
		if ( a[i] < 0 ) k++;
		if ( a[i] == 0 ) b0++;
		j += ia( a[i] );
	}
	
	sort( a + 1, a + 2*n-1+1, cmp );
	
	//if ( n+2 <= 2*n-1 )
	{
		if ( n%2 == 1 )
		{
			printf( "%d\n", j );
			return 0;
		}
		else if ( k%2 == 0 )
		{
			printf( "%d\n", j );
			return 0;
		}
		else
		{
			if ( b0 == 0 )
				printf( "%d\n", j-2*ia(a[1]) );
			else
				printf( "%d\n", j );
		}
	}
	return 0;
}