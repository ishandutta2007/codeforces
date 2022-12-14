#include <cstdio>
#include <cstring>

int la, lb;
int a[2000020], b[2000020], c[4000020];

//int na, kr;
//int bm[4000020];

int fp[1000020];

int nextPos( int pos, int val )
{
	if ( fp[val] == -1 ) return -1;
	int k = 0;
	k = fp[val];
	while ( k <= pos ) k = k + lb;
	return k;
}

int main()
{
	int i, j, k;
	int l, r, lpos;
	int be = 0;
	
	scanf( "%d %d", &la, &lb );
	for ( i = 1; i <= la; i++ )
	{
		scanf( "%d", &a[i] );
		a[i+la] = a[i];
	}
	
	memset( fp, -1, sizeof( fp ) );
	for ( i = 1; i <= lb; i++ )
	{
		scanf( "%d", &b[i] );
		fp[ b[i] ] = i;
	}
	
	for ( i = 1; i <= la; i++ )
	{
		if ( fp[ a[i] ] != -1 )
		{
			break;
		}
	}
	if ( i > la )
	{
		printf( "0\n" );
		return 0;
	}
	
	for ( j = fp[ a[i] ], k = 1; k <= lb; k++, j++ )
	{
		if ( j >= lb+1 ) j = 1;
		c[k] = b[j];
		c[lb+k] = b[j];
		c[lb+lb+k] = b[j];
		c[lb+lb+lb+k] = b[j];
		fp[ c[k] ] = k;
	}
	
//	na = 1; kr = 0;
	for ( l = r = i, k = fp[ a[i] ]; l <= la && r <= 2*la; )
	{
		if ( l <= r )
			lpos = nextPos( k, a[l] );
		else
		{
			while ( ( fp[ a[l] ] == -1 ) && ( l <= la ) )
				l++;
			if ( l > la ) break;
			r = l;
			k = fp[ a[l] ];
			lpos = nextPos( k, a[l] );
		}
		if ( be < r-l+1 )
			be = r-l+1;

		//printf( "%d %d : %d __ %d\n", l, r, k, nextPos( k, a[r+1] ) );
		
		if ( l <= r )
		{
			int np = nextPos( k, a[r+1] );
			if ( ( fp[ a[r+1] ] != -1 ) && ( np != -1 && np < lpos ) )
			{
				r++;
				k = fp[ a[r] ];
//				bm[++kr] = a[r];
			}
			else if ( fp[ a[l] ] != -1 )
			{
//				na++;
				l++;
			}
		}
		//else r = l;
	}
	
	printf( "%d\n", be );
	return 0;
}