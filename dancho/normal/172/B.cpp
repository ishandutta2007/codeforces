#include <cstdio>
#include <cstring>

int a, b, m, r0;
int r[200020];
int la[200020];

int main()
{
	int i;
	
	scanf( "%d %d %d %d", &a, &b, &m, &r0 );
	
	r[0] = r0;
	memset( la, -1, sizeof( la ) );
	for ( i = 1; i <= m+m; i++ )
	{
		r[i] = (a*r[i-1]+b)%m;
		if ( la[ r[i] ] == -1 )
		{
			la[ r[i] ] = i;
		}
		else
		{
			printf( "%d\n", i-la[ r[i] ] );
			break;
		}
	}
	
	return 0;
}