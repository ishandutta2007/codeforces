#include <cstdio>

const int MAXN = 105;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int f[MAXN][MAXN];
char S[MAXN];
int N;

int DFS( const int l, const int r )
{
	if( l > r ) return true;
	if( f[l][r] ) return f[l][r];
	if( l == r ) return f[l][r] = ( S[l - 1] == S[l] - 1 ) || ( S[l + 1] == S[l] - 1 ) ? 1 : -1;
	bool flag;
	for( int i = l ; i <= r ; i ++ )
	{
		if( S[i] == 'a' ) return f[l][r] = -1;
		flag = false;
		for( int j = i - 1 ; j && j >= l - 1 ; j -- ) 
		{
			if( S[j] == S[i] - 1 && DFS( j + 1, i - 1 ) > 0 ) { flag = true; break; }
			if( S[j] == 'a' ) break;
		}
		if( flag ) continue;
		for( int j = i + 1 ; j <= r + 1 && j <= N ; j ++ )
		{
			if( S[j] == S[i] - 1 && DFS( i + 1, j - 1 ) > 0 ) { flag = true; break; }
			if( S[j] == 'a' ) break;
		}
		if( ! flag ) return f[l][r] = -1;
	}
	return f[l][r] = 1;
}

int main()
{
	read( N );
	scanf( "%s", S + 1 );
	int tot = 0, flag;
	for( int i = 1 ; i <= N ; i ++ )
	{
		flag = false;
		for( int j = i - 1 ; j ; j -- ) 
			if( S[j] == S[i] - 1 && DFS( j + 1, i - 1 ) > 0 ) 
			{ flag = true; break; }
		if( flag ) { tot ++; continue; }
		for( int j = i + 1 ; j <= N ; j ++ )
			if( S[j] == S[i] - 1 && DFS( i + 1, j - 1 ) > 0 )
			{ flag = true; break; }
		if( flag ) tot ++;
	}
	write( tot ), putchar( '\n' );
	return 0;
}