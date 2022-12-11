#include <cmath>
#include <cstdio>

typedef long long LL;

const int mod = 1e9 + 9;
const int MAXN = 3e5 + 5, MAXB = 1005;

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int alAd[MAXB], upAd1[MAXB], upAd2[MAXB]; 
//upAd1:f(m-1), upAd2:f(m) 
int lef[MAXB], rig[MAXB];
int bel[MAXN], val[MAXN], dist[MAXN];

int fibo[MAXN << 1];
int N, M, T, blk;

void Sub( int &x, const int v ) { x = ( x < v ? x - v + mod : x - v ); }
int Mul( LL x, const int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
void Add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

void Init()
{
	T = sqrt( N );
	for( int i = 1 ; i <= N ; i += T )
	{
		blk ++, lef[blk] = i, rig[blk] = MIN( N, i + T - 1 );
		for( int k = lef[blk] ; k <= rig[blk] ; k ++ )
			bel[k] = blk, dist[k] = k - lef[blk];
	}
	
	fibo[1] = fibo[2] = 1;
	for( int i = 3 ; i <= 2 * N ; i ++ ) 
		fibo[i] = ( fibo[i - 1] + fibo[i - 2] ) % mod;
}

int Diff( const int k )
{
	int id = bel[k];
	return ( ( LL ) alAd[id] + Mul( fibo[dist[k]], upAd1[id] ) + Mul( fibo[dist[k] + 1], upAd2[id] ) ) % mod;
}

void Normalize( const int id )
{
	if( ! upAd2[id] ) return ;
	for( int k = lef[id] ; k <= rig[id] ; k ++ )
		Add( val[k], Diff( k ) );
	alAd[id] = upAd1[id] = upAd2[id] = 0;
}

void UpUpdateBlock( const int id, const int l, const int r, const int sta )
{
	Normalize( id );
	for( int i = l ; i <= r ; i ++ )
		Add( val[i], fibo[sta + i - l] );
}

void UpUpdateAll( const int l, const int r, const int sta )
{
	if( l > r ) return ;
	if( bel[l] == bel[r] ) { UpUpdateBlock( bel[l], l, r, sta ); return ; }
	if( l ^ lef[bel[l]] ) UpUpdateBlock( bel[l], l, rig[bel[l]], sta );
	if( r ^ rig[bel[r]] ) UpUpdateBlock( bel[r], lef[bel[r]], r, sta + lef[bel[r]] - l );
	for( int k = 1 ; k <= blk ; k ++ )
		if( l <= lef[k] && rig[k] <= r )
		{
			int beg = sta + lef[k] - l;
			Add( upAd1[k], fibo[beg - 1] ), Add( upAd2[k], fibo[beg] );
		}
}

void AllUpdateBlock( const int id, const int l, const int r, const int v )
{
	Normalize( id );
	for( int i = l ; i <= r ; i ++ )
		Add( val[i], v );
}

void AllUpdateAll( const int l, const int r, const int v )
{
	if( l > r ) return ;
	if( bel[l] == bel[r] ) { AllUpdateBlock( bel[l], l, r, v ); return ; }
	if( l ^ lef[bel[l]] ) AllUpdateBlock( bel[l], l, rig[bel[l]], v );
	if( r ^ rig[bel[r]] ) AllUpdateBlock( bel[r], lef[bel[r]], r, v );
	for( int k = 1 ; k <= blk ; k ++ )
		if( l <= lef[k] && rig[k] <= r )
			Add( alAd[k], v );
}

int Query( const int x ) { return ( val[x] + Diff( x ) ) % mod; }
int Query( const int L, const int R ) { return ( Query( R ) - Query( L - 1 ) + mod ) % mod; }

signed main()
{
	scanf( "%d %d", &N, &M );
	for( int i = 1 ; i <= N ; i ++ ) 
		scanf( "%d", &val[i] ), Add( val[i], val[i - 1] );
	Init();

	int opt, x, y;
	while( M -- )
	{
		scanf( "%d %d %d", &opt, &x, &y );
		if( opt == 1 ) 
			AllUpdateAll( x, y, mod - fibo[2] ), 
			AllUpdateAll( y + 1, N, ( fibo[y - x + 3] + mod - fibo[2] ) % mod ),
			UpUpdateAll( x, y, 3 );
		else printf( "%d\n", Query( x, y ) );
	}
	return 0;
}