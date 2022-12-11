#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int f[MAXN], q[MAXN], cnt[MAXN];

int ans[MAXN];

int a[MAXN];
int N, tot;

void Insert( const int v ) { tot += ! ( cnt[v] ++ ); }
void Delete( const int v ) { tot -= ! ( -- cnt[v] ); }

int Calc( const int K )
{
	int h = 1, t = 0, l = 1;
	rep( i, 1, N ) cnt[i] = 0; tot = 0;
	
	f[q[++ t] = 0] = 0;
	rep( i, 1, N )
	{
		Insert( a[i] );
		while( tot > K )
		{
			while( h <= t && q[h] < l ) h ++;
			Delete( a[l ++] );
		}
		f[i] = f[q[h]] + 1;
		while( h <= t && f[q[t]] >= f[i] ) t --;
		q[++ t] = i;
	}
	return f[N];
}

void Divide( const int l, const int r, const int aL, const int aR )
{
	if( l > r || aL > aR ) return ;
	if( aL == aR ) { rep( i, l, r ) ans[i] = aL; return ; }
	int mid = l + r >> 1; ans[mid] = Calc( mid );
	Divide( l, mid - 1, ans[mid], aR ), Divide( mid + 1, r, aL, ans[mid] );
}

int main()
{
	read( N );
	rep( i, 1, N ) read( a[i] );
	Divide( 1, N, 1, N );
	rep( i, 1, N ) write( ans[i] ), putchar( i == N ? '\n' : ' ' );
	return 0;
}