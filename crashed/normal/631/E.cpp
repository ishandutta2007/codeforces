#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 5;

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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

struct Linear
{
	LL k, b;
	Linear() { k = b = 0; }
	Linear( LL K, LL B ) { k = K, b = B; }
	LL operator () ( const LL x ) const { return k * x + b; }
};

Linear f[MAXN], func[MAXN];

LL su[MAXN], val[MAXN];
int A[MAXN], pos[MAXN], coe[MAXN];
int N, tot;

void Build( const int l, const int r )
{
	if( l > r ) return ; 
	int mid = l + r >> 1;
	f[mid] = Linear( 0, -INF );
	Build( l, mid - 1 );
	Build( mid + 1, r );
}

void Update( const int l, const int r, Linear nw )
{
	if( l > r ) return ;
	int mid = l + r >> 1;
	if( f[mid]( val[mid] ) < nw( val[mid] ) ) swapp( f[mid], nw );
	if( f[mid]( val[l] ) <= nw( val[l] ) ) Update( l, mid - 1, nw );
	else Update( mid + 1, r, nw );
}

LL Query( const int l, const int r, const int p )
{
	if( l > r ) return -INF;
	int mid = l + r >> 1; LL ret = f[mid]( val[p] );
	if( p < mid ) ret = MAX( Query( l, mid - 1, p ), ret );
	if( mid < p ) ret = MAX( Query( mid + 1, r, p ), ret );
	return ret;
}

void Discrete()
{
	tot = 0; for( int i = 1 ; i <= N ; i ++ ) val[++ tot] = A[i];
	sort( val + 1, val + 1 + tot ); tot = unique( val + 1, val + 1 + tot ) - val - 1;
	for( int i = 1 ; i <= N ; i ++ ) pos[i] = lower_bound( val + 1, val + 1 + tot, A[i] ) - val;
}

int main()
{
	read( N ); LL ans = 0, base = 0;
	for( int i = 1 ; i <= N ; i ++ ) read( A[i] ), coe[i] = i, base += 1ll * i * A[i];
	
	Discrete(), Build( 1, tot ), func[0] = Linear( 0, 0 ), Update( 1, tot, func[0] );
	for( int i = 1 ; i <= N ; i ++ ) func[i] = Linear( i, - ( su[i] = su[i - 1] + A[i] ) );
	for( int i = 1 ; i <= N ; i ++ ) ans = MAX( ans, Query( 1, tot, pos[i] ) + su[i] - 1ll * i * A[i] ), Update( 1, tot, func[i] );
	Build( 1, tot ), func[N + 1] = Linear( N + 1, 0 ), Update( 1, tot, func[N + 1] );
	for( int i = N ; i ; i -- ) func[i] = Linear( i, su[i] = su[i + 1] + A[i] );
	for( int i = N ; i ; i -- ) ans = MAX( ans, Query( 1, tot, pos[i] ) - su[i] - 1ll * i * A[i] ), Update( 1, tot, func[i] );
	
	write( ans + base ), putchar( '\n' );
	return 0;
}