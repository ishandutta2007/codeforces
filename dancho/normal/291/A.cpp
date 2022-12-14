#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n, k;
map<int,int> mp;

int main()
{
	int ans = 0;
	scanf( "%d", &n );
	for (int i = 0; i < n; i++)
	{
		scanf( "%d", &k );
		if ( k > 0 ){
			mp[k]++;
			if ( mp[k] == 2 )
				ans++;
			else if ( mp[k] > 2 )
			{
				printf( "-1\n" );
				return 0;
			}
		}
	}
	
	printf( "%d\n", ans );
	
	return 0;
}