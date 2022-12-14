#include <cstdio>
#include <cstring>

char str[1<<20];

int n;
char out[1<<20];

int main()
{
	fgets( str, (1<<20), stdin );
	
	str[strlen( str )-1] = '\0';
	
	n = strlen( str );
	int k = 0, j = 0;
	for ( int i = 0; i < n; i++ )
	{
		if ( str[i] == '\"' )
		{
			if ( k == 1 )
			{
				out[j] = '\0';
				printf( "<%s>\n", out );
				j = 0;
				k = 0;
			}
			else
			{
				if ( j > 0 )
				{
					out[j] = '\0';
					printf( "<%s>\n", out );
				}
				j = 0;
				k = 1;
			}
		}
		else if ( k == 1 )
		{
			out[j++] = str[i];
		}
		else if ( str[i] == ' ' )
		{
			if ( j > 0 )
			{
				out[j] = '\0';
				printf( "<%s>\n", out );
			}
			j = 0;
		}
		else
		{
			out[j++] = str[i];
		}
	}
	
	if ( j > 0 )
	{
		out[j] = '\0';
		printf( "<%s>\n", out );
	}
	return 0;
}