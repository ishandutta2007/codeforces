#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

int n, k;
char s[2][100020];
int di[2][100020];
pii q[200020];
int qb, qe;

bool bfs()
{
	qb = 1; qe = 0;
	int i, j;
	q[++qe] = make_pair( 0, 1 );
	memset( di, -1, sizeof( di ) );
	di[0][1] = 1;
	pii a;
	while ( qb <= qe )
	{
		a = q[qb++];
		i = a.first; j = a.second;
		if ( di[i][j] > j ) continue;
		if ( s[i][j] == 'X' ) continue;
		if ( j + k > n ) return true;
		if ( di[i][j+1] == -1 )
		{
			q[++qe] = make_pair( i, j+1 );
			di[i][j+1] = di[i][j] + 1;
		}
		if ( di[i][j-1] == -1 && j-1 >= 1 )
		{
			q[++qe] = make_pair( i, j-1 );
			di[i][j-1] = di[i][j] + 1;
		}
		if ( di[1-i][j+k] == -1 )
		{
			di[1-i][j+k] = di[i][j] + 1;
			q[++qe] = make_pair( 1-i, j+k );
		}
	}
	return false;
}

int main()
{
	scanf( "%d %d", &n, &k );
	scanf( "%s", s[0]+1 );
	scanf( "%s", s[1]+1 );
	
	if ( bfs() )
	{
		printf( "YES\n" );
	}
	else printf( "NO\n" );
	return 0;
}