#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

int n;
pii a[1<<17];

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &a[i].first, &a[i].second );
	}
	
	sort( a + 1, a + n + 1 );
	
	k = a[1].second;
	j = a[1].first;
	for ( i = 2; i <= n; i++ )
	{
		while ( k > 1 && j < a[i].first )
		{
			k = (k+3)/4;
			j++;
		}
		if ( k < a[i].second )
			k = a[i].second;
		j = a[i].first;
	}
	while ( k > 1 )
	{
		k = (k+3)/4;
		j++;
	}
	
	if ( j <= a[n].first )
		j = a[n].first + 1;
	printf( "%d\n", j );
	return 0;
}