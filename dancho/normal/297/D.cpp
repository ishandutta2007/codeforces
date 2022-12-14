#include <cstdio>
#include <cstring>

int h, w, k;

char lr[1024][1024];
char lc[1024][1024];

char nlr[1024][1024], nlc[1024][1024];

int col[1024][1024], ncol[1024][1024];

void flip()
{
	int i, j;
	for ( i = 0; i < w; i++ )
	{
		for ( j = 0; j < h-1; j++ )
			nlr[i][j] = lc[j][i];
		if ( i+1 < w )
		{
			for ( j = 0; j < h; j++ )
				nlc[i][j] = lr[j][i];
		}
	}
	
	memcpy( lr, nlr, sizeof( lr ) );
	memcpy( lc, nlc, sizeof( lc ) );
	i = h;
	h = w;
	w = i;
}

void flipcol()
{
	int i, j;
	for ( i = 0; i < h; i++ )
	{
		for ( j = 0; j < w; j++ )
			ncol[j][i] = col[i][j];
	}
	
	memcpy( col, ncol, sizeof( col ) );

	i = h;
	h = w;
	w = i;
}

int main()
{
	int i, j, s;
	bool bf = 0;
	scanf( "%d %d %d", &h, &w, &k );
	for ( i = 0; i < h; i++ )
	{
		scanf( "%s", lr[i] );
		if ( i+1 < h )
			scanf( "%s", lc[i] );
	}
	
	if ( k == 1 )
	{
		s = 0;
		int all = 0;
		for ( i = 0; i < h; i++ )
			for ( j = 0; j < w-1; j++ )
			{
				all++;
				if ( lr[i][j] == 'N' )
					s++;
			}
					
		for ( i = 0; i < h-1; i++ )
			for ( j = 0; j < w; j++ )
			{
				all++;
				if ( lc[i][j] == 'N' )
					s++;
			}
		
		if ( s*4 < all )
		{
			printf( "YES\n" );
			for ( i = 0; i < h; i++ )
			{
				for ( j = 0; j < w; j++ )
				{
					if ( j + 1 < w )
						printf( "%d ", 1 );
					else
						printf( "%d\n", 1 );
				}
			}
		}
		else
			printf( "NO\n" );
	}
	else
	{
		if ( h*(w-1) < (h-1)*w )
		{
			flip();
			bf = 1;
		}
		
		col[0][0] = 1;
		for ( j = 1; j < w; j++ )
		{
			if ( lr[0][j-1] == 'E' )
				col[0][j] = col[0][j-1];
			else
				col[0][j] = 3-col[0][j-1];
		}
		
		for ( i = 1; i < h; i++ )
		{
			col[i][0] = 1;
			for ( j = 1; j < w; j++ )
			{
				if ( lr[i][j-1] == 'E' )
					col[i][j] = col[i][j-1];
				else
					col[i][j] = 3-col[i][j-1];
			}
			s = 0;
			for ( j = 0; j < w; j++ )
			{
				if ( lc[i-1][j] == 'E' && col[i][j] != col[i-1][j] )
					s++;
				else if (lc[i-1][j] == 'N' && col[i][j] == col[i-1][j] )
					s++;
			}
			if ( w - s < s )
			{
				for ( j = 0; j < w; j++ )
					col[i][j] = 3-col[i][j];
			}
		}
		
		if ( bf )
		{
			flipcol();
		}
		printf( "YES\n" );
		for ( i = 0; i < h; i++ )
		{
			for ( j = 0; j < w; j++ )
			{
				if ( j + 1 < w )
					printf( "%d ", col[i][j] );
				else
					printf( "%d\n", col[i][j] );
			}
		}
	}
	return 0;
}