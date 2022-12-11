#include <map>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN = 2e5 + 5;

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

map<int, int> mp;

int N, K;

int main()
{
	mp[0] = 1;
	read( N ), read( K );
	LL res = 0;
	int upper = ( 1 << K ) - 1, pXor = 0, fir, sec; 
	for( int i = 1, a ; i <= N ; i ++ )
	{
		read( a );
		fir = pXor ^ a, sec = pXor ^ a ^ upper;
		if( mp[fir] < mp[sec] ) res += mp[pXor = fir] ++;
		else res += mp[pXor = sec] ++;
	}
	write( 1ll * N * ( N + 1 ) / 2 - res ), putchar( '\n' );
	return 0;
}