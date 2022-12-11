#include <cstdio>

typedef long long LL;

const int MAXN = 1e5 + 5, MAXS = MAXN * 10;

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

int arr[MAXS << 1], *buc = arr + MAXS;

int a[MAXN], s[MAXN];
int N;

int main()
{
	LL ans;
	int T;
	read( T );
	while( T -- )
	{
		read( N );
		for( int i = 1 ; i <= N ; i ++ )
			scanf( "%1d", &a[i] ), s[i] = s[i - 1] + a[i] - 1;
		ans = 0;
		for( int i = 0 ; i <= N ; i ++ )
			ans += buc[s[i]], buc[s[i]] ++;
		for( int i = 0 ; i <= N ; i ++ ) buc[s[i]] = 0;
		write( ans ), putchar( '\n' );
	}
	return 0;
}