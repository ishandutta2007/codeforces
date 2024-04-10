#include <cmath>
#include <cstdio>

typedef long double LB;

const int MAXM = 1e5 + 5;

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

LB fac[MAXM];
int N, M, K;

LB C( const int n, const int m ) { return fac[n] - fac[m] - fac[n - m]; }

int main()
{
	read( N ), read( M ), read( K );
	fac[0] = 0;
	for( int i = 1 ; i <= M ; i ++ ) fac[i] = fac[i - 1] + log( i );
	int t;
	LB ans = 0, tmp;
	for( int i = 0 ; i <= N ; i ++ )
		for( int j = 0 ; j <= N ; j ++ )
			if( ( t = i * N + j * N - i * j ) <= K )
			{
				tmp = C( N, i ) + C( N, j ) + C( M - t, K - t ) - C( M, K );
				ans += exp( tmp );
				if( ans > 1e99 ) { puts( "1e99" ); return 0; }
			}
	printf( "%.10lf\n", ( double ) ans );
	return 0;
}
/*
1 1 1
*/