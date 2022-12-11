#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
 
typedef long long LL;
 
#define int LL
 
const int lim = 1e6;
const int MAXN = 1e6 + 5;
 
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
 
struct seg
{
	int P, L, R;
	
	seg() { P = L = R = 0; }
	
	void Rea() { read( P ), read( L ), read( R ); }
}H[MAXN], V[MAXN];
 
vector<int> lef[MAXN], rig[MAXN];
 
int sta[MAXN];
int BIT[MAXN];
int lx[MAXN], rx[MAXN], y[MAXN];
int ly[MAXN], ry[MAXN], x[MAXN];
int N, M;
bool spe[MAXN];
 
void up( int &x ) { x += x & ( -x ); }
void down( int &x ) { x -= x & ( -x ); }
void update( int x, const int v ) { for( ; x <= lim ; up( x ) ) BIT[x] += v; } 
int getS( int x ) { int ret = 0 ; for( ; x ; down( x ) ) ret += BIT[x]; return ret; }
int query( const int l, const int r ) { return getS( r ) - getS( l ? l - 1 : l ); }
 
signed main()
{
	int delt = 0;
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) 
	{
		H[i].Rea();
		if( H[i].L == 0 && H[i].R == lim )
		{
			spe[i] = true, delt ++;
		}
		if( H[i].L == 0 ) lef[H[i].R].push_back( i );
		else rig[H[i].L].push_back( i );
	}
	for( int i = 1 ; i <= M ; i ++ ) V[i].Rea(), sta[V[i].P] = i;
	LL ans = delt + 1;
	for( int i = 1 ; i <= N ; i ++ )
		if( H[i].L == 0 )
			update( H[i].P, 1 );
	for( int i = 1 ; i < lim ; i ++ )
	{
		if( sta[i] ) 
		{
			ans += query( V[sta[i]].L, V[sta[i]].R );
			if( V[sta[i]].L == 0 && V[sta[i]].R == lim )
				ans ++;
		}
		for( auto k : lef[i] ) update( H[k].P, -1 );
	}
	memset( BIT, 0, sizeof BIT );
	for( int i = 1 ; i <= N ; i ++ )
		if( ! spe[i] && H[i].R == lim )
			update( H[i].P, 1 );
	for( int i = lim - 1 ; i ; i -- )
	{
		if( sta[i] ) ans += query( V[sta[i]].L, V[sta[i]].R );
		for( auto k : rig[i] ) update( H[k].P, -1 );
	}
 
	write( ans ), putchar( '\n' );
	return 0;
}