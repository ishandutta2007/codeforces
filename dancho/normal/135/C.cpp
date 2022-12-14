#include <cstdio>
#include <cstring>

int n;
int b0, b1, bp;
char s[100020];

int main()
{
	int i, j, k, l;
	
	scanf( "%s", s );
	n = strlen( s );
	
	b0 = 0; b1 = 0; bp = 0;
	int l0 = -1, l1 = -1, lp = -1;
	for ( i = 0; i < n; i++ )
	{
		if ( s[i] == '0' )
		{
			b0++;
			l0 = i;
		}
		else if ( s[i] == '1' )
		{
			b1++;
			l1 = i;
		}
		else if ( s[i] == '?' )
		{
			bp++;
			lp = i;
		}
	}
	
	//check 00;
	if ( b0 + bp >= b1+1 )
		printf( "00\n" );
	//check 01
	k = n/2-b0;
	if ( ( k <= bp ) && ( k >= 0 ) )
	{
		j = 0; l = n/2;
		for ( i = 0; i < n; i++ )
		{
			if ( l <= 0 ) break;
			if ( s[i] == '0' )
				l--;
			else if ( ( s[i] == '?' ) && ( k > 0 ) )
			{
				l--;
				k--;
			}
		}
		for ( ; i < n; i++ )
		{
			if ( s[i] != '0' )
			{
				printf( "01\n" );
				break;
			}
		}
	}
	
	//check 10
	k = n/2-b0;
	if ( ( k <= bp ) && ( k >= 0 ) )
	{
		j = 0; l = n-n/2;
		k = l-b1;
		for ( i = 0; i < n; i++ )
		{
			if ( l <= 0 ) break;
			if ( s[i] == '1' )
				l--;
			else if ( ( s[i] == '?' ) && ( k > 0 ) )
			{
				l--;
				k--;
			}
		}
		for ( ; i < n; i++ )
		{
			if ( s[i] != '1' )
			{
				printf( "10\n" );
				break;
			}
		}
	}
		
	//check 11
	if ( b1+bp >= b0 + 2 )
		printf( "11\n" );
	
	return 0;
}