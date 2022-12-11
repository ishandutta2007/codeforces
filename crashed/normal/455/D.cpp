#include <deque>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 1e5 + 5, MAXB = 405;

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
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

template<typename _T>
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

deque<int> q[MAXB];

int cnt[MAXB][MAXN];
int lef[MAXB], rig[MAXB];
int bel[MAXN];

int val[MAXN];
int N, Q, T, blk, rt;

int QueryBlock( const int id, const int l, const int r, const int v )
{
	int x = l - lef[id], y = r - lef[id], ret = 0;
	for( int k = x ; k <= y ; k ++ ) ret += q[id][k] == v;
	return ret;
}

int QueryAll( const int l, const int r, const int v )
{
	int ret = 0;
	if( l > r ) return 0;
	if( bel[l] == bel[r] ) return QueryBlock( bel[l], l, r, v );
	if( l ^ lef[bel[l]] ) ret += QueryBlock( bel[l], l, rig[bel[l]], v );
	if( r ^ rig[bel[r]] ) ret += QueryBlock( bel[r], lef[bel[r]], r, v );
	for( int i = bel[l] ; i <= bel[r] ; i ++ )
		if( l <= lef[i] && rig[i] <= r )
			ret += cnt[i][v];
	return ret;
}

void Move( const int l, const int r )
{
	if( bel[l] ^ bel[r] )
	{
		for( int k = bel[l] ; k < bel[r] ; k ++ )
		{
			int v = q[k].back();
			cnt[k][v] --, cnt[k + 1][v] ++;
		}
		int v = q[bel[r]][r - lef[bel[r]]];
		cnt[bel[r]][v] --, cnt[bel[l]][v] ++;
	}
	
	if( l ^ r )
	{
		int v = q[bel[r]][r - lef[bel[r]]];
		deque<int> :: iterator it = q[bel[r]].begin();
		advance( it, r - lef[bel[r]] );
		q[bel[r]].erase( it );
		it = q[bel[l]].begin();
		advance( it, l - lef[bel[l]] );
		q[bel[l]].insert( it, v );
		for( int k = bel[l] ; k < bel[r] ; k ++ )
			q[k + 1].push_front( q[k].back() ), q[k].pop_back();
	}
}

void Init()
{
	T = sqrt( N );
	for( int i = 1 ; i <= N ; i += T )
	{
		blk ++, lef[blk] = i, rig[blk] = MIN( N, i + T - 1 );
		for( int k = lef[blk] ; k <= rig[blk] ; k ++ )
			bel[k] = blk, cnt[blk][val[k]] ++, q[blk].push_back( val[k] );
	}
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( val[i] );
	Init();
	
	read( Q );
	int opt, lst = 0, L, R, num;
	while( Q -- )
	{
		read( opt ), read( L ), read( R );
		L = ( L + lst - 1 ) % N + 1;
		R = ( R + lst - 1 ) % N + 1;
		if( L > R ) swapp( L, R );
		if( opt == 1 ) Move( L, R );
		else
		{
			read( num );
			num = ( num + lst - 1 ) % N + 1;
			write( lst = QueryAll( L, R, num ) ), putchar( '\n' );
		}
	}
	return 0;
}