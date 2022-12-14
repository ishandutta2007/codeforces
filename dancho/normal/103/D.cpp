#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int n, p;
int w[300020];

map<int,vector<pii> > q;

long long ps[300020], sol[300020];

int main()
{
	int i, j, k, l;
	map<int, vector<pii> >::iterator it;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &w[i] );
	}
	
	scanf( "%d", &p );
	for ( i = 1; i <= p; i++ )
	{
		scanf( "%d %d", &j, &k );
		q[k].push_back( make_pair( j, i ) );
	}
	
	for ( it = q.begin(); it != q.end(); it++ )
	{
		if ( (it->first) <= 550 )
		{
			k = (it->first);
			for ( i = n; i > n-k && i > 0; i-- )
			{
				ps[i] = w[i];
			}
			for ( i = n-k; i > 0; i-- )
			{
				ps[i] = ps[i+k] + w[i];
			}
			
			for ( j = 0; j < (it->second).size(); j++ )
			{
				sol[ (it->second)[j].second ] = ps[ (it->second)[j].first ];
			}
		}
		else
		{
			l = (it->first);
			for ( j = 0; j < (it->second).size(); j++ )
			{
				sol[ (it->second)[j].second ] = 0;
				for ( k = (it->second)[j].first; k <= n; k = k + l )
				{
					sol[ (it->second)[j].second ] += w[k];
				}
			}
		}
	}
	for ( i = 1; i <= p; i++ )
	{
		printf( "%I64d\n", sol[i] );
	}
	return 0;
}