#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int,int> > pii;

priority_queue< pii, vector<pii>, greater<pii> > pq;

int n;
long long a[100020];

int d[100020];
int nx[32];

long long sol[100020];

int main()
{
	int i, j, k;
	pii p;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		a[i] = k;
	}
	
	memset( nx, -1, sizeof( nx ) );
	
	d[n] = 0;
	nx[0] = n;
	for ( i = n-1; i > 0; i-- )
	{
		d[i] = (1<<29);
		for ( k = 1; i+k <= n; k=k*2 )
		{
			if ( d[i+k] + 1 < d[i] )
				d[i] = d[i+k] + 1;
		}
		for ( j = 0; j < d[i]; j++ )
		{
			if ( nx[j] == -1 ) continue;
			pq.push( make_pair( nx[j]-i, make_pair( i, j ) ) );
		}
		nx[ d[i] ] = i;
	}
	
	long long sm = 0;
	for ( i = 1; i < n; i++ )
	{
		sm = sm + a[i]*d[i];
	}
	
	sol[n-1] = sm;
	for ( i = n-2, j = 1; i > 0; i--, j++ )
	{
		while ( ( pq.size() > 0 ) && ( pq.top().first <= j ) )
		{
			p = pq.top(); pq.pop();
			if ( p.second.second < d[ p.second.first ] )
			{
				sm = sm - a[ p.second.first ]*d[ p.second.first ];
				d[ p.second.first ] = p.second.second;
				sm = sm + a[ p.second.first ]*d[ p.second.first ];
			}
		}
		sol[i] = sm;
	}
	
	for ( i = 1; i < n; i++ )
	{
		printf( "%I64d\n", sol[i] );
	}
	return 0;
}