#include <map>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;

const int base = 31;
const int MAXN = 105, MAXM = 55;

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

map<ull, int> mp;

ull pH[MAXN], sH[MAXN];
char S[MAXN][MAXM];
int seq[MAXN];
bool pal[MAXN], used[MAXN];
int N, M;

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ )
	{
		scanf( "%s", S[i] + 1 );
		for( int j = 1 ; j <= M ; j ++ )
			pH[i] = pH[i] * base + ( S[i][j] - 'a' ), sH[i] = sH[i] * base + ( S[i][M - j + 1] - 'a' );
		pal[i] = pH[i] == sH[i];
		mp[pH[i]] ++;
	}
	int tot = 0, ind = 0;
	for( int i = 1 ; i <= N ; i ++ ) 
		if( ( ! pal[i] ) && mp[sH[i]] ) 
			tot += 2, mp[pH[i]] --, mp[sH[i]] --, used[i] = true;
	for( int i = 1 ; i <= N ; i ++ ) 
		if( pal[i] && mp[pH[i]] ) { ind = i, tot ++; break; }
	write( tot * M ), putchar( '\n' );
	if( ! tot ) return 0;
	tot = 0;
	for( int i = 1 ; i <= N ; i ++ )
		if( used[i] )
		{
			printf( "%s", S[i] + 1 );
			for( int j = 1 ; j <= N ; j ++ )
				if( i ^ j && sH[j] == pH[i] )
					seq[++ tot] = j;
		}
	for( int i = 1 ; i <= N ; i ++ ) 
		if( ind == i ) { printf( "%s", S[i] + 1 ); break; }
	for( int i = tot ; i ; i -- ) printf( "%s", S[seq[i]] + 1 );
	puts( "" );
	return 0;
}