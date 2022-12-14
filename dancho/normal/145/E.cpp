#include <cstdio>
#include <cstring>

int max( const int &a, const int &b )
{
	if ( a > b ) return a;
	return b;
}

void swap( int &a, int &b )
{
	int t = b;
	b = a;
	a = t;
}

int n, m;
char str[ 1<<21 ];
bool ch[ 1<<21 ];
bool st[ 1<<21 ];
int t4[ 1<<21 ], t7[ 1<<21 ];
int b47[ 1<<21 ];
int s47[ 1<<21 ][ 2 ];

void start()
{
	int i;
	for ( i = (1<<20)-1; i > 0; i-- )
	{
		t4[i] = t4[2*i] + t4[2*i+1];
		t7[i] = t7[2*i] + t7[2*i+1];
		b47[i] = max( b47[2*i] + t7[2*i+1], max( t4[2*i]+b47[2*i+1], t4[2*i] + t7[2*i+1] ) );
		b47[i] = max( b47[i], max( t4[i], t7[i] ) );
		s47[i][0] = b47[i];
		s47[i][1] = max( s47[2*i][1] + t4[2*i+1], max( t7[2*i] + s47[2*i+1][1], t7[2*i] + t4[2*i+1] ) );
	}
}

void swi( int nd, int nl, int nr, int l, int r )
{
	if ( ( nr < l ) || ( r < nl ) )
	{
		if ( ch[nd] )
		{
			ch[nd] = 0;
			st[nd] = 1 - st[nd];
			swap( t4[nd], t7[nd] );
			if ( nl != nr )
			{
				ch[2*nd] = 1-ch[2*nd];
				ch[2*nd+1] = 1-ch[2*nd+1];
			}
			b47[nd] = s47[nd][ st[nd] ];
		}
		return;
	}
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		if ( ch[nd] )
		{
			ch[nd] = 0;
//			printf( "CH %d (%d %d) %d %d %d\n", nd, nl, nr, t4[nd], t7[nd], b47[nd] );
			return;
		}
		st[nd] = 1 - st[nd];
		swap( t4[nd], t7[nd] );
		if ( nl != nr )
		{
			ch[2*nd] = 1-ch[2*nd];
			ch[2*nd+1] = 1-ch[2*nd+1];
		}
		b47[nd] = s47[nd][ st[nd] ];
		//printf( "CH %d (%d %d) %d %d %d\n", nd, nl, nr, t4[nd], t7[nd], b47[nd] );
		return;
	}
	if ( ch[nd] )
	{
		ch[nd] = 0;
		st[nd] = 1 - st[nd];
		swap( t4[nd], t7[nd] );
		if ( nl != nr )
		{
			ch[2*nd] = 1-ch[2*nd];
			ch[2*nd+1] = 1-ch[2*nd+1];
		}
		b47[nd] = s47[nd][ st[nd] ];
	}
	swi( 2*nd, nl, (nl+nr)/2, l, r );
	swi( 2*nd+1, (nl+nr)/2+1, nr, l, r );
	t4[nd] = t4[2*nd] + t4[2*nd+1];
	t7[nd] = t7[2*nd] + t7[2*nd+1];
	b47[nd] = max( b47[2*nd] + t7[2*nd+1], max( t4[2*nd]+b47[2*nd+1], t4[2*nd] + t7[2*nd+1] ) );
	int i = nd;
	st[nd] = 0;
	s47[i][ st[i] ] = b47[i];
	s47[i][ 1-st[i] ] = max( s47[2*i][1-st[2*i]] + t4[2*i+1], max( t7[2*i] + s47[2*i+1][1-st[2*i+1]], t7[2*i] + t4[2*i+1] ) );
//	printf( "%d %d (%d %d) : %d %d %d; %d %d %d\n", nd, b47[nd], nl, nr, t4[2*nd], t7[2*nd], b47[2*nd], t4[2*nd+1], t7[2*nd+1], b47[2*nd+1] );
}

void swi( int l, int r )
{
	swi( 1, 0, (1<<20)-1, l, r );
}

int main()
{
	int i, j, k;
	char op[16];
	
	scanf( "%d %d", &n, &m );
	scanf( "%s", str );
	
	memset( t4, 0, sizeof( t4 ) );
	memset( t7, 0, sizeof( t7 ) );
	memset( ch, 0, sizeof( ch ) );
	memset( st, 0, sizeof( st ) );
	memset( b47, 0, sizeof( b47 ) );

	for ( i = 0; i < n; i++ )
	{
		if ( str[i] == '4' )
		{
			t4[ i+(1<<20) ]++;
			b47[ i+(1<<20) ]++;
			s47[ i+(1<<20) ][0]++;
			s47[ i+(1<<20) ][1]++;
		}
		else if ( str[i] == '7' )
		{
			t7[ i+(1<<20) ]++;
			b47[ i+(1<<20) ]++;
			s47[ i+(1<<20) ][0]++;
			s47[ i+(1<<20) ][1]++;
		}
	}
	
	start();
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%s", op );
		if ( op[0] == 's' )
		{
			scanf( "%d %d", &j, &k );
			j--; k--;
			swi( j, k );
		}
		else printf( "%d\n", b47[1] );
	}
	return 0;
}