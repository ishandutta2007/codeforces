#include <cstdio>

const int mod = 51123987, inv2 = 25561994;
const int MAXN = 2e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar();int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) { putchar( '-' ), x = -x; }
	if( 9 < x ) { write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int lef[MAXN], rig[MAXN];
int len[MAXN << 1], l[MAXN << 1], r[MAXN << 1];
char S[MAXN << 1];
int N, length;

void manacher()
{
	int mid = 0, mxr = 0;
	for( int i = 1 ; i <= length ; i ++ )
	{
		if( i <= mxr ) len[i] = MIN( len[( mid << 1 ) - i], mid + len[mid] - i );
		while( i - len[i] > 0 && i + len[i] <= length && S[i - len[i]] == S[i + len[i]] ) len[i] ++;
		if( i + len[i] > mxr ) mxr = i + len[i], mid = i;
	}
}

int fix( const int a )  { return ( a % mod + mod ) % mod; }

int main()
{
	read( N );
	S[++ length] = '$';
	for( int i = 1 ; i <= N ; i ++ )
		S[++ length] = getchar(), S[++ length] = '$';
	manacher();
	for( int i = 1 ; i <= length ; i ++ )
		l[i - len[i] + 1] ++, l[i + 1] --,
		r[i] ++, r[i + len[i]] --;
	int res = 0;
	for( int i = 1 ; i <= length ; i ++ )
	{
		( res += len[i] >> 1 ) %= mod, ( l[i] += l[i - 1] ) %= mod, ( r[i] += r[i - 1] ) %= mod;
		if( S[i] ^ '$' ) lef[i >> 1] = l[i], rig[i >> 1] = r[i];
	}
	for( int i = 1 ; i <= N ; i ++ ) ( lef[N - i + 1] += lef[N - i + 2] ) %= mod;
	res = 1ll * res * fix( res - 1 ) % mod * inv2 % mod;
	for( int i = 1 ; i <= N ; i ++ )
		res = fix( res - 1ll * rig[i] * lef[i + 1] % mod );
	write( res ), putchar( '\n' );
	return 0;
}