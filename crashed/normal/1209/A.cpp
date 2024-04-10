#include <cstdio>
#include <algorithm>

const int MAXN = 105;

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

int a[MAXN];
int N;
bool used[MAXN];

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	std :: sort( a + 1, a + 1 + N );
	int cnt = 0;
	for( int i = 1 ; i <= N ; i ++ )
		if( ! used[i] )
		{
			for( int j = i ; j <= N ; j ++ )
				if( ! ( a[j] % a[i] ) ) used[j] = true;
			cnt ++;
		}
	write( cnt ), putchar( '\n' );
	return 0;
}