#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 105, MAXM = 105;

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

string s[MAXN], t[MAXM];
int N, M, Q;

int gcd( const int a, const int b ) { return b ? gcd( b, a % b ) : a; }

int main()
{
	int Y, lcm;
	ios :: sync_with_stdio( false );
	cin >> N >> M;
	for( int i = 1 ; i <= N ; i ++ ) cin >> s[i];
	for( int i = 1 ; i <= M ; i ++ ) cin >> t[i];
	cin >> Q;
	lcm = N * M / gcd( N, M );
	while( Q -- )
	{
		cin >> Y;
		Y = ( Y - 1 ) % lcm;
		cout << s[Y % N + 1] << t[Y % M + 1] << endl;
	}
	return 0;
}
/*
1 1
a
b
1
1000000000
*/