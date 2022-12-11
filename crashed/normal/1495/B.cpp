#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

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

int preUp[MAXN], sufUp[MAXN];
int lup[MAXN], rup[MAXN], mxup[MAXN];
int ldn[MAXN], rdn[MAXN], mxdn[MAXN];

int P[MAXN];
int N;

int main()
{
	read( N );
	rep( i, 1, N ) read( P[i] );
	rep( i, 1, N )
	{
		lup[i] = i > 1 && P[i - 1] > P[i] ? lup[i - 1] + 1 : 0;
		ldn[i] = i > 1 && P[i - 1] < P[i] ? ldn[i - 1] + 1 : 0;
	}
	per( i, N, 1 )
	{
		rup[i] = i < N && P[i] < P[i + 1] ? rup[i + 1] + 1 : 0;
		rdn[i] = i < N && P[i] > P[i + 1] ? rdn[i + 1] + 1 : 0;
	}
	preUp[0] = sufUp[0] = - INF;
	rep( i, 1, N ) 
	{	
		mxup[i] = MAX( lup[i], rup[i] );
		mxdn[i] = MAX( ldn[i], rdn[i] );
		preUp[i] = MAX( preUp[i - 1], mxup[i] );
	}
	per( i, N, 1 ) 
		sufUp[i] = MAX( sufUp[i + 1], mxup[i] );
	int ans = 0;
	rep( i, 1, N )
	{
		if( ! ldn[i] || ! rdn[i] ) continue;
		if( MAX( lup[i - ldn[i]], i - ldn[i] > 1 ? preUp[i - ldn[i] - 1] : - INF ) >= mxdn[i] ) continue;
		if( MAX( rup[i + rdn[i]], i + rdn[i] < N ? sufUp[i + rdn[i] + 1] : - INF ) >= mxdn[i] ) continue;
		if( ldn[i] - ( ldn[i] % 2 == 0 ) >= rdn[i] ) continue;
		if( rdn[i] - ( rdn[i] % 2 == 0 ) >= ldn[i] ) continue;
		ans ++;
	}
	write( ans ), putchar( '\n' );
	return 0;
}