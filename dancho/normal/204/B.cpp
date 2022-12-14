#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n;

map<int,int> cnt;
map<int,int> os;

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &j, &k );
		cnt[j]++;
		if ( j != k )
		{
			os[k]++;
		}
		if ( cnt[j] >= (n+1)/2 )
		{
			printf( "0\n" );
			return 0;
		}
	}
	
	
	map<int,int>::iterator it;
	k = (n+1)/2;
	j = (1<<29);
	for ( it = os.begin(); it != os.end(); it++ )
	{
		if ( (it -> second) + cnt[ (it->first) ] >= k )
		{
			j = min( j, k - cnt[ (it->first) ] );
		}
	}
	if ( j < (1<<29) ) printf( "%d\n", j );
	else printf( "%d\n", -1 );
	return 0;
}