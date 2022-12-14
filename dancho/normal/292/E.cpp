#include <cstdio>
#include <cstring>

int n, m;
int a[1<<17], b[1<<17];

int beg[1<<18];
int sz[1<<18];
int st[1<<18];

int x, y, k;

void upd( int nd, int nl, int nr, int sz )
{
	beg[nd] = nl;
	if ( nr < y || nl > y+k-1 )
		return;
	if ( y <= nl && nr < y+k )
	{
		st[nd] = x + nl-y;
		return;
	}
	if ( st[nd] )
	{
		st[2*nd] = st[nd];
		st[2*nd+1] = st[nd] + sz/2;
	}
	st[nd] = 0;
	
	upd( 2*nd, nl, (nl+nr)/2, sz/2 );
	upd( 2*nd+1, (nl+nr)/2+1, nr, sz/2 );
}

int query( int p )
{
	int sp = p;
	p = p + (1<<17)-1;
	int r = 0;
	while ( p )
	{
		if ( st[p] )
		{
			r = st[p] + sp - beg[p];
		}
		p = p / 2;
	}
	return r;
}

int main()
{
	int i, j;
	int t;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &b[i] );
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d", &t );
		if ( t == 1 )
		{
			scanf( "%d %d %d", &x, &y, &k );
			upd( 1, 1, (1<<17), (1<<17) );
		}
		else if ( t == 2 )
		{
			scanf( "%d", &j );
			int l = query( j );
			if ( l )
				printf( "%d\n", a[l] );
			else
				printf( "%d\n", b[j] );
		}
	}
	return 0;
}