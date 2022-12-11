#include <cstdio>

typedef long long LL;

const int MAXN = 35, MAXLOG = 65;

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

LL a[MAXN];
int cnt[65];
int N, K;

int main()
{
	int T;
	bool flag;
	read( T );
	while ( T -- )
	{
		read( N ), read( K );
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
		for( int i = 0 ; i <= 60 ; i ++ ) cnt[i] = 0;
		for( int i = 1 ; i <= N ; i ++ )
		{
			LL t = a[i];
			for( int j = 0 ; t ; j ++, t /= K ) cnt[j] += t % K;
		}
		flag = true;
		for( int i = 0 ; i <= 60 ; i ++ ) flag &= cnt[i] <= 1;
		puts( flag ? "YES" : "NO" );
	}
	return 0;
}