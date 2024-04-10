#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define rep( i, a, b ) for( int (i) = (a) ; (i) <= (b) ; (i) ++ )
#define per( i, a, b ) for( int (i) = (a) ; (i) >= (b) ; (i) -- )

typedef long long LL;

const double eps = 1e-8;
const int MAXN = 1e5 + 5;

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

map<int, int> up, down;

int Q;

struct Vector
{
	int x, y;
	Vector( int X = 0, int Y = 0 ) { x = X, y = Y; }
	Vector( map<int, int> :: const_iterator it ) { x = it->first, y = it->second; }
	Vector operator + ( const Vector &b ) const { return Vector( x + b.x, y + b.y ); }
	Vector operator - ( const Vector &b ) const { return Vector( x - b.x, y - b.y ); }
	bool operator == ( const Vector &b ) const { return x == b.x && y == b.y; }
	bool operator < ( const Vector &b ) const { return x == b.x ? y < b.y : x < b.x; }
};

void read( Vector &v ) { read( v.x ), read( v.y ); }
void write( Vector v ) { printf( "(%d, %d)\n", v.x, v.y ); }
LL Dot( const Vector &a, const Vector &b ) { return 1ll * a.x * b.x + 1ll * a.y * b.y; }
LL Cross( const Vector &a, const Vector &b ) { return 1ll * a.x * b.y - 1ll * a.y * b.x; }

bool Chk( const map<int, int>& mp, const Vector &p ) //  mp  
{
	auto it = mp.find( p.x );
	if( it != mp.end() ) return p.y >= it->second;
	it = mp.lower_bound( p.x );
	if( it == mp.begin() || it == mp.end() ) return false;
	auto nxt = it; nxt --; /*write( Vector( nxt ) ), write( Vector( it ) ), write( p );*/
	return Cross( Vector( it ) - Vector( nxt ), p - Vector( nxt ) ) >= 0;
}

void Insert( map<int, int>& mp, const Vector &p ) // 
{
	if( Chk( mp, p ) ) return ;
	if( mp.size() < 2 ) return void( mp[p.x] = p.y );
	auto it = mp.end();
	if( p.x <= mp.begin()->first )
	{
		while( mp.size() > 1 )
		{
			auto it = mp.begin(), tmp = mp.begin(); tmp ++;
			if( Cross( Vector( tmp ) - Vector( it ), Vector( it ) - p ) < 0 ) break;
			mp.erase( mp.begin() );
		}
		return void( mp[p.x] = p.y );
	}
	if( p.x >= ( -- it )->first )
	{
		while( mp.size() > 1 )
		{
			auto tmp = ( it = mp.end() ); it --, -- ( -- tmp );
			if( Cross( p - Vector( it ), Vector( it ) - Vector( tmp ) ) < 0 ) break;
			mp.erase( it );
		}
		return void( mp[p.x] = p.y );
	}
	it = mp.upper_bound( p.x ); auto pre = it; -- pre;
	while( pre != mp.begin() )
	{
		auto tmp = pre; -- tmp;
		if( Cross( p - Vector( pre ), Vector( pre ) - Vector( tmp ) ) < 0 ) break;
		pre = mp.erase( pre ); pre --;
	}
	while( ( ++ it ) != mp.end() )
	{
		auto tmp = it --;
		if( Cross( Vector( tmp ) - Vector( it ), Vector( it ) - p ) < 0 ) break;
		it = mp.erase( it );
	}
	mp[p.x] = p.y;
}

void Init()
{
	Vector pnt[3]; int opt;
	rep( i, 0, 2 ) read( opt ), read( pnt[i] );
	sort( pnt, pnt + 3 ), Q -= 3;
	Insert( up, Vector( pnt[0].x, - pnt[0].y ) ), Insert( down, pnt[0] );
	Insert( up, Vector( pnt[2].x, - pnt[2].y ) ), Insert( down, pnt[2] );
	if( Cross( pnt[1] - pnt[0], pnt[2] - pnt[0] ) < 0 ) Insert( up, Vector( pnt[1].x,  - pnt[1].y ) );
	else Insert( down, pnt[1] );
}

int main()
{
	up.clear(), down.clear();
	read( Q ); Init();
	while( Q -- )
	{
		int opt; Vector p;
		read( opt ), read( p );
		if( opt == 1 ) 
			Insert( up, Vector( p.x, - p.y ) ), 
			Insert( down, p );
		else
			puts( Chk( up, Vector( p.x, - p.y ) ) && Chk( down, p ) ? "YES" : "NO" );
	}
	return 0;
}
/*
5
1 -702 -823
1 -330 -896
1 -564 90
1 559 818
2 404 716
*/