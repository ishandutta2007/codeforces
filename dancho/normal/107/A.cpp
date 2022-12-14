#include <cstdio>
#include <cstring>

int fr[1024], to[1024], cap[1024];
int n, p;

int bo;
int out[1024][3];

int main()
{
	int i, j, k, d;
	
	memset( fr, -1, sizeof( fr ) );
	memset( to, -1, sizeof( to ) );
	
	scanf( "%d %d", &n, &p );
	for ( i = 1; i <= p; i++ )
	{
		scanf( "%d %d %d", &j, &k, &d );
		to[j] = k;
		fr[k] = j;
		cap[j] = d;
	}
	bo = 0;
	
	for ( i = 1; i <= n; i++ )
	{
		if ( fr[i] == -1 )
		{
			j = i;
			k = (1<<29);
			while ( to[j] != -1 )
			{
				if ( cap[j] < k ) k = cap[j];
				j = to[j];
			}
			if ( i != j )
			{
			bo++;
			out[bo][0] = i;
			out[bo][1] = j;
			out[bo][2] = k;
			}
		}
	}
	
	printf( "%d\n", bo );
	for ( i = 1; i <= bo; i++ )
	{
		printf( "%d %d %d\n", out[i][0], out[i][1], out[i][2] );
	}
	return 0;
}