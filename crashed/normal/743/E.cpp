#include <cstdio>

const int INF = 0x3f3f3f3f;
const int MAXN = 1005, MAXS = ( 1 << 8 ) + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int f[MAXN][MAXS];
int nxt[MAXN][MAXN], prev[15];
int a[MAXN];
int N, ans;
bool app[15];

bool in( const int S, const int i ) { return S & ( 1 << i - 1 ); }

void clr()
{
	for( int i = 0 ; i <= N + 2 ; i ++ )
		for( int S = 0 ; S < ( 1 << 8 ) ; S ++ )
			f[i][S] = -INF;
}

bool chk( const int L )
{
	clr(); f[1][0] = 0;
	for( int i = 1 ; i <= N ; i ++ )
		for( int S = 0 ; S < ( 1 << 8 ) ; S ++ )
			if( f[i][S] > -INF )
			{
				f[i + 1][S] = MAX( f[i + 1][S], f[i][S] );
				if( ! in( S, a[i] ) )
				{
					int T = S | ( 1 << a[i] - 1 ), to;
					if( to = nxt[i][L] ) 
						f[to][T] = MAX( f[to][T], f[i][S] + L );
					if( to = nxt[i][L + 1] ) 
						f[to][T] = MAX( f[to][T], f[i][S] + L + 1 );
				}
			}
	int ret = 0;
	for( int i = 1 ; i <= N + 1 ; i ++ ) ret = MAX( ret, f[i][( 1 << 8 ) - 1] );
	ans = MAX( ans, ret ); return ret > 0;
}

void init()
{
	for( int i = 1 ; i <= N ; i ++ )
	{
		int tot = 0;
		for( int j = i ; j <= N ; j ++ )
			if( a[i] == a[j] )
				nxt[i][++ tot] = j + 1;
	}
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) 
		read( a[i] ), ans += ! app[a[i]], app[a[i]] = true;
	init();
	int l = 1, r = N - 1, mid;
	while( r - l > 1 )
	{
		mid = l + r >> 1; 
		if( chk( mid ) ) l = mid;
		else r = mid - 1;
	}
	chk( l ), chk( r );
	write( ans ), putchar( '\n' );
	return 0;
}