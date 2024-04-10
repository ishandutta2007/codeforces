#include <cstdio>
#include <cstring>

int n;
int t[200020];
bool us[20020];

int main()
{
	int i, j, k;
	int bsm = -(1<<29), csm, cnt;
	
	scanf( "%d", &n );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &t[i] );
	}
	
	for ( k = 1; k <= n; k++ )
	{
		if ( n%k == 0 )
		{
			memset( us, 0, sizeof( us ) );
//			printf( "UK %d\n", k );
			for ( i = 0; i < n; i++ )
			{
				if ( us[i] == 0 )
				{
					csm = 0; cnt = 0;
					for ( j = i; ; j=j+k )
					{
						if ( j >= n ) j = j % n;
						if ( us[j] == 1 ) break;
						cnt++;
						csm = csm + t[j];
						us[j] = 1;
					}
					if ( cnt >= 3 )
					{
						if ( bsm < csm ) bsm = csm;
					}
				}
			}
		}
	}
	printf( "%d\n", bsm );
	return 0;
}