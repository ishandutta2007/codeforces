#include <cstdio>

int dpb[1000020], dp4[1000020], dp7[1000020];

int main()
{
	int i;
	int n;
	scanf( "%d", &n );
	dpb[4] = 1; dp4[4] = 1;
	dpb[7] = 1; dp7[7] = 1;
	for ( i = 5; i <= n; i++ )
	{
		if ( dpb[i-4] != 0 )
		{
			dpb[i] = dpb[i-4] + 1;
			dp4[i] = dp4[i-4] + 1;
			dp7[i] = dp7[i-4];
		}
		if ( ( i-7 > 0 ) && ( dpb[i-7] != 0 ) )
		{
			if ( dpb[i] == 0 || dpb[i-7] < dpb[i-4] )
			{
				dpb[i] = dpb[i-7] + 1;
				dp4[i] = dp4[i-7];
				dp7[i] = dp7[i-7] + 1;
			}
			else if ( dpb[i-7] == dpb[i-4] )
			{
				if ( dp4[i-7] > dp4[i-4] + 1 )
				{
					dpb[i] = dpb[i-7] + 1;
					dp4[i] = dp4[i-7];
					dp7[i] = dp7[i-7] + 1;
				}
			}
		}
	}
	if ( dpb[n] == 0 )
	{
		printf( "-1\n" );
		return 0;
	}
	for ( i = 1; i <= dp4[n]; i++ )
		printf( "4" );
	for ( i = 1; i <= dp7[n]; i++ )
		printf( "7" );
	printf( "\n" );
	return 0;
}