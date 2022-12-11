#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<int, int> Ristr;

const int mod = 998244353;
const int MAXN = 3e5 + 5, MAXM = 25, MAXS = ( 1 << 20 ) + 5;

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

vector<int> ad[MAXN], del[MAXN]; 

int f[MAXM << 1][MAXS];
int fr[MAXM], to[MAXM];

int fac[MAXN], ifac[MAXN];

int id[MAXN];
int N, M, cnt;
bool app[MAXM << 1], in[MAXN];

int Qkpow( int, int );
int Lowbit( const int x ) { return x & ( -x ); }
int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
int Sub( int x, int v ) { return x < v ? x + mod - v : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }
int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

int Count( const int S )
{
	for( int i = 1 ; i <= M << 1 ; i ++ ) app[i] = false;
	for( int i = 1 ; i <= M ; i ++ )
		if( S & ( 1 << i - 1 ) )
			app[id[fr[i]]] = true, app[id[to[i]]] = true;
	int tot = 0;
	for( int i = 1 ; i <= M << 1 ; i ++ )
		tot += app[i];
	return tot;
}

int Qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = Mul( ret, base );
		base = Mul( base, base ), indx >>= 1;
	}
	return ret;
}

void Init()
{
	int upper = 1 << M, coe, tot;
	for( int S = 0 ; S < upper ; S ++ )
	{
		coe = 1, tot = Count( S );
		for( int i = 1 ; i <= M ; i ++ )
			if( S & ( 1 << i - 1 ) )
				coe = mod - coe;
		f[tot][S] = Add( f[tot][S], coe );
	}
	for( int i = 0 ; i <= M << 1 ; i ++ )
		for( int k = 1 ; k < upper ; k <<= 1 )
			for( int S = k ; S < upper ; S ++ )
				if( S & k )
					f[i][S] = Add( f[i][S], f[i][S ^ k] ); 
	fac[0] = 1; for( int i = 1 ; i <= N ; i ++ ) fac[i] = Mul( fac[i - 1], i );
	ifac[N] = Inv( fac[N] ); for( int i = N - 1 ; ~ i ; i -- ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main()
{
	read( N ), read( M );
	for( int i = 1, l, r ; i <= N ; i ++ )
		read( l ), read( r ), ad[l].push_back( i ), del[r + 1].push_back( i );
	for( int i = 1 ; i <= M ; i ++ )
		read( fr[i] ), read( to[i] ), id[fr[i]] = ++ cnt, id[to[i]] = ++ cnt;
	Init();
	int cur = 0, ans = 0, all = 0;
	for( int s = 1 ; s <= N ; s ++ )
	{
		cur = 0;
		for( int i = 0 ; i < ( int ) ad[s].size() ; i ++ ) in[ad[s][i]] = true, all ++;
		for( int i = 0 ; i < ( int ) del[s].size() ; i ++ ) in[del[s][i]] = false, all --;
		for( int i = 1 ; i <= M ; i ++ ) if( in[fr[i]] && in[to[i]] ) cur |= 1 << i - 1;
		for( int c = 0 ; c <= M << 1 ; c ++ )
			ans = Add( ans, Mul( C( all - c, s - c ), f[c][cur] ) );
	}
	write( ans ), putchar( '\n' );
	return 0;
}