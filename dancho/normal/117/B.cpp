#include <cstdio>
#include <cstring>

long long a, b, mod;

int main()
{
	int A, B, M;
	
	scanf( "%d %d %d", &A, &B, &M );
	a = A; b = B; mod = M;
	
	long long i, j, k;
	int o;
	long long li = mod;
	if ( a < li ) li = a;
	
	for ( i = 0; i <= li; i++ )
	{
		j = i*1000000000;
		if ( j >= mod ) j = j % mod;
		if ( j == 0 ) continue;
		k = mod-j;
		if ( k > b )
		{
			o = i;
			printf( "1 %09d\n", o );
			return 0;
		}
	}
	printf( "2\n" );
	return 0;
}