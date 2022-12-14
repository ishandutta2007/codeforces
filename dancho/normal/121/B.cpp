#include <cstdio>
#include <cstring>
using namespace std;

int n, k;
char d[100020];

int main()
{
	int i;
	char ld;
	
	scanf( "%d %d", &n, &k );
	scanf( "%s", d );
	ld = 0;
	for ( i = 0; i < n && k > 0; i++ )
	{
		if ( ( d[i] == '4' ) && ( d[i+1] == '7' ) )
		{
			if ( (i+1)%2 == 1 )
			{
				d[i] = '4';
				d[i+1] = '4';
				k--;
			}
			else if ( (i+1)%2 == 0 )
			{
				if ( ld == '4' )
				{
					if ( k % 2 == 1 )
					{
						d[i] = '7';
						d[i+1] = '7';
					}
					break;
				}
				else
				{
					d[i] = '7';
					d[i+1] = '7';
					k--;
				}
			}
		}
		ld = d[i];
	}
	printf( "%s\n", d );
	return 0;
}