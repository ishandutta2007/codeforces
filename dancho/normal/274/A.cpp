#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int n, k;
map<int,int> cnt;
int a[1<<20];
int c[1<<20], lc;
int dp[1<<20];

int main()
{
	int i, j;
	int ans = 0;
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		cnt[a[i]]++;
	}
	
	if ( k == 1 )
	{
		printf( "%d\n", n );
		return 0;
	}
	
	map<int,int>::iterator it;
	sort( a + 1, a + n + 1 );
	for ( i = 1; i <= n; i++ )
	{
		long long b = a[i];
		if ( cnt.find( b ) == cnt.end() )
			continue;
		lc = 0;
		while ( b < 2000000000 )
		{
			lc++;
			if ( cnt.find( b ) != cnt.end() )
			{
				c[lc] = cnt[b];
				cnt.erase( b );
			}
			else
				c[lc] = 0;
			b = b * k;
		}
		
		while ( c[lc] == 0 )
			lc--;
		dp[0] = 0;
		dp[1] = c[1];
		for ( j = 2; j <= lc; j++ )
		{
			dp[j] = max( c[j] + dp[j-2], dp[j-1] );
		}
		ans += dp[lc];
	}
	printf( "%d\n", ans );
}