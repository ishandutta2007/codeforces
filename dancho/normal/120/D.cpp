#include <cstdio>

bool cmp3( int a, int b, int c, int a1, int b1, int c1 )
{
	if ( a == a1 && b == b1 && c == c1 )
		return 1;
	if ( a == a1 && b == c1 && c == b1 )
		return 1;
	if ( a == b1 && b == a1 && c == c1 )
		return 1;
	if ( a == b1 && b == c1 && c == a1 )
		return 1;
	if ( a == c1 && b == a1 && c == b1 )
		return 1;
	if ( a == c1 && b == b1 && c == a1 )
		return 1;
	return 0;
}

int n, m;
int a, b, c;
int C[64][64];

int sm[64];
int ps[64];

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	
	int i, j;
	int ans = 0;
	fscanf( fin, "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			fscanf( fin, "%d", &C[i][j] );
		}
	}
	fscanf( fin, "%d %d %d", &a, &b, &c );
	
	ans = 0;
	ps[0] = 0;
	sm[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		ps[i] = ps[i-1];
		sm[i] = 0;
		for ( j = 1; j <= m; j++ )
		{
			sm[i] = sm[i] + C[i][j];
		}
		ps[i] = ps[i-1] + sm[i];
	}
	
	for ( i = 1; i <= n; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( cmp3( ps[i], ps[j]-ps[i], ps[n]-ps[j], a, b, c ) )
				ans++;
		}
	}
	
	ps[0] = 0;
	sm[0] = 0;
	for ( i = 1; i <= m; i++ )
	{
		ps[i] = ps[i-1];
		sm[i] = 0;
		for ( j = 1; j <= n; j++ )
		{
			sm[i] = sm[i] + C[j][i];
		}
		ps[i] = ps[i-1] + sm[i];
//		printf( "%d %d _ %d\n", i, sm[i], ps[i] );
	}
	
	for ( i = 1; i <= m; i++ )
	{
		for ( j = i+1; j < m; j++ )
		{
//			printf( "CHK %d %d _ %d %d %d\n", i, j, ps[i], ps[j]-ps[i], ps[m]-ps[j] );
			if ( cmp3( ps[i], ps[j]-ps[i], ps[m]-ps[j], a, b, c ) )
				ans++;
		}
	}
	
	fprintf( fout, "%d\n", ans );
	
	fclose( fin );
	fclose( fout );
	return 0;
}