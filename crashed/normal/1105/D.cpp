#include <queue>
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> pos;
#define xx first
#define yy second

const int MAXN = 1005, MAXM = 1005, MAXP = 10;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ){ f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ){ x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ), x = -x; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

queue<pos> q[10], las[10];

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int ans[MAXP];
char str[MAXM];
int s[MAXP];
int N, M, P;
int col[MAXN][MAXM], dist[MAXN][MAXM];

bool chk( const int x, const int y )
{
	return 1 <= x && x <= N && 1 <= y && y <= M && ! col[x][y];
}

bool expand( const int indx )
{
	bool flag = false; 
	pos head; int tx, ty;
	while( ! las[indx].empty() )
	{
		head = las[indx].front(); las[indx].pop();
		for( int i = 0 ; i < 4 ; i ++ )
		{
			tx = head.xx + dir[i][0], ty = head.yy + dir[i][1];
			if( chk( tx, ty ) ) q[indx].push( pos( tx, ty ) ), col[tx][ty] = indx, dist[tx][ty] = 1, flag = true;
		}
	}
	while( ! q[indx].empty() )
	{
		head = q[indx].front(); q[indx].pop();
		if( dist[head.xx][head.yy] == s[indx] ) { las[indx].push( head ); continue; }
		for( int i = 0 ; i < 4 ; i ++ )
		{
			tx = head.xx + dir[i][0], ty = head.yy + dir[i][1];
			if( chk( tx, ty ) ) 
				q[indx].push( pos( tx, ty ) ), col[tx][ty] = indx, dist[tx][ty] = dist[head.xx][head.yy] + 1, flag = true;
		}
	}
	return flag;
}

int main()
{
	read( N ), read( M ), read( P );
	for( int i = 1 ; i <= P ; i ++ ) read( s[i] );
	for( int i = 1 ; i <= N ; i ++ )
	{
		scanf( "%s", str + 1 );
		for( int j = 1 ; j <= M ; j ++ )
		{
			if( str[j] == '#' ) col[i][j] = -1;
			else if( str[j] ^ '.' ) 
				col[i][j] = str[j] - '0', las[col[i][j]].push( pos( i, j ) ), dist[i][j] = 1;
		}
	}
	for( bool flag = false ; ; flag = false )
	{
		for( int i = 1 ; i <= P ; i ++ ) flag |= expand( i );
		if( ! flag ) break;
	}
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= M ; j ++ ) 
			ans[col[i][j]] ++;
	for( int i = 1 ; i <= P ; i ++ ) 
		write( ans[i] ), putchar( i == P ? '\n' : ' ' );
	return 0;
}