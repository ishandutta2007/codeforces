#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int n, m, x, y;
int a[100020], b[100020];

vector<pii> sol;

int main()
{
	int i, j, k;
	
	scanf( "%d %d %d %d", &n, &m, &x, &y );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	for ( i = 1; i <= m; i++ )
		scanf( "%d", &b[i] );
		
	i = 1; j = 1;
	sol.clear();
	while ( ( i <= n ) && ( j <= m ) )
	{
		if ( ( b[j] >= a[i]-x ) && ( b[j] <= a[i]+y ) )
		{
			sol.push_back( make_pair( i, j ) );
			i++;
			j++;
		}
		else if ( b[j] < a[i]-x )
		{
			j++;
		}
		else if ( b[j] > a[i]+y )
			i++;
	}
	
	printf( "%d\n", sol.size() );
	for ( k = 0; k < (int) sol.size(); k++ )
	{
		printf( "%d %d\n", sol[k].first, sol[k].second );
	}
	return 0;
}