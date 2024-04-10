#include <iostream>
#include <stdio.h>
#define MAXN 200010
#define mod 1000000007
 
using namespace std;
 
int n , k , pre[ MAXN ] , root[ MAXN ] , ans , res = 1;
 
inline int abs( int x )
{
	return x < 0 ? -x : x;
}
 
int find( int x )
{
	if( x == pre[x] ) return x;
	return pre[x] = find( pre[x] );
}
 
inline void merge( int x , int y )
{
	if( find( x ) != find( y ) )
		pre[ find( x ) ] = find( y );
}
 
inline int read()
{
	register int x = 0 , ch = getchar();
	while( !isdigit( ch ) ) ch = getchar();
	while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
	return x;
}
 
int main()
{
	n = read() , k = read();
	for( register int i = 0 ; i < ( n + 2 ) << 1 ; i++ ) pre[i] = i;
	while( k-- )
	{
		int x = read() , y = read() , ch;
		int l = abs( x - y ) , r = min( x + y , 2 * n + 2 - x - y );
		while( isspace( ch = getchar() ) );
		if( ch == 'o' )
		{
			merge( l << 1 , r << 1 | 1 );
			merge( l << 1 | 1 , r << 1 );
		}
		else
		{
			merge( l << 1 , r << 1 );
			merge( l << 1 | 1 , r << 1 | 1 );
		}
	}
	for( register int i = 0 ; i < ( n + 2 ) << 1 ; i++ )
		if( !root[ find( i ) ] )
			ans += root[ find( i ) ] = 1;
	ans >>= 1 , ----ans;
	for( register int i = 0 ; i < n + 1 ; i++ )
		if( find( i << 1 ) == find( i << 1 | 1 ) )
		{
			cout << 0 << endl;
			return 0;
		}
	while( ans-- ) res <<= 1 , res %= mod;
	cout << res << endl;
	return 0;
}