#include <cstdio>
#include <algorithm>

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int a[5];
bool used[10];

bool op( const int t, const bool f )
{
	for( int k = 1 ; k <= 3 ; k ++ )
		if( t & ( 1 << k - 1 ) && f && ! a[k] ) 
			return false;
	for( int k = 1 ; k <= 3 ; k ++ )
		if( t & ( 1 << k - 1 ) ) a[k] += f ? -1 : 1;
	return true;
}

int DFS()
{
	int ret = 0;
	for( int j = 1 ; j < 8 ; j ++ )
		if( ! used[j] && op( j, 1 ) )
		{
			used[j] = true;
			ret = MAX( ret, DFS() + 1 );
			op( j, 0 ), used[j] = false;
		}
	return ret;
}

int main()
{
	int T, ans;
	read( T );
	while( T -- )
	{
		for( int i = 1 ; i <= 3 ; i ++ ) read( a[i] );
		write( DFS() ), putchar( '\n' );
	}
	return 0;
}