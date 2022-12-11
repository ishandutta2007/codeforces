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

int seq[MAXN], tot;
char S[MAXN];
int N;

int main()
{
	int T, ans;
	read( T );
	while ( T -- )
	{
		ans = tot = 0;
		scanf( "%s", S + 1 );
		for( int i = 1, r ; S[i] ; i ++ )
			if( S[i] == '1' )
			{
				for( r = i ; S[r] == '1' ; r ++ );
				seq[++ tot] = r - i;
				i = r - 1;
			}
		std :: sort( seq + 1, seq + 1 + tot );
		for( int i = tot ; i > 0 ; i -= 2 ) ans += seq[i];
		write( ans ), putchar( '\n' );
	}
	return 0;
}