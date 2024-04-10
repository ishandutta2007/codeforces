#include <cstdio>

const int mod = 998244353;
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

double P[MAXN];
int N, M;

struct ATOM
{
	double plr, prl;
	ATOM() { plr = prl = 1; }
	ATOM( const double P ) { plr = prl = P; }
	ATOM( const double P1, const double P2 ) { plr = P1, prl = P2; }
	
	ATOM operator + ( const ATOM & b ) const 
	{
		double tmp = 1 / ( 1 - ( 1 - prl ) * ( 1 - b.plr ) ); 
		return ATOM( plr * b.plr * tmp, b.prl * prl * tmp ); 
	}
	
	void operator += ( const ATOM &b ) { *this = *this + b; }
};

ATOM val[MAXN << 2];

void upt( const int x ) { val[x] = val[x << 1] + val[x << 1 | 1]; }

void build( const int x, const int l, const int r )
{
	if( l > r ) return ;
	if( l == r ) { val[x] = ATOM( P[l], 1 - P[l] ); return; }
	int mid = l + r >> 1;
	build( x << 1, l, mid ), build( x << 1 | 1, mid + 1, r );
	upt( x );
}

void update( const int x, const int l, const int r, const int pos, const ATOM nVal )
{
	if( l == r ) { val[x] = nVal; return;  }
	int mid = l + r >> 1;
	if( pos <= mid ) update( x << 1, l, mid, pos, nVal );
	else update( x << 1 | 1, mid + 1, r, pos, nVal );
	upt( x );
}

ATOM query( const int x, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) return val[x];
	int mid = l + r >> 1; ATOM ret = ATOM();
	if( segL <= mid ) ret += query( x << 1, l, mid, segL, segR );
	if( mid < segR ) ret += query( x << 1 | 1, mid + 1, r, segL, segR );
	return ret;
}

int main()
{
	int opt, d, x, y;
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) read( x ), read( y ), P[i] = 1.0 * x / y;
	build( 1, 1, N );
	while( M -- )
	{
		read( opt );
		if( opt == 1 ) 
		{
			read( d ), read( x ), read( y ); double p = 1.0 * x / y;
			update( 1, 1, N, d, ATOM( p, 1 - p ) );
		}
		if( opt == 2 ) read( x ), read( y ), printf( "%.10lf\n", query( 1, 1, N, x, y ).plr );
	}
	return 0;
}