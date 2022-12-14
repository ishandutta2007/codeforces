#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n, m;
int t[100020], x[100020];
int w[100020];

map<int,vector<int> > mp;

int main()
{
	int i, j, k, b;
	int ct;
	
	map<int,vector<int> >::iterator it;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &t[i], &x[i] );
	}
	
	ct = 0;
	k = 1;
	b = 0;
	while ( k <= n )
	{
		mp.clear();
		b = 0;
		j = k;
		while ( ( k <= n ) && ( b < m ) )
		{
			mp[ x[k] ].push_back( k );
			k++;
			b++;
		}
		
		if ( ct < t[k-1] ) ct = t[k-1];
		i = 0;
		for ( it = mp.begin(); it != mp.end(); it++ )
		{
			ct = ct + (it->first) - i;
			for ( j = 0; j < (int)(it->second).size(); j++ )
			{
				w[ (it->second)[j] ] = ct;
			}
			ct = ct + 1 + (int)(it->second).size()/2;
			i = (it->first);
		}
		ct = ct + i;
	}
	
	for ( i = 1; i < n; i++ )
		printf( "%d ", w[i] );
	printf( "%d\n", w[n] );
	return 0;
}