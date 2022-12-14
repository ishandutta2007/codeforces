#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n;
map<int,int> mp;
priority_queue<pii> pq;

vector<int> sol[1000020];

int main()
{
	int i, k;
	pii a, b, c;
	int ls = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		mp[k]++;
	}
	
	map<int,int>::iterator it;
	for ( it = mp.begin(); it != mp.end(); it++ )
	{
		pq.push( make_pair( it->second, it->first ) );
	}
	
	while ( pq.size() >= 3 )
	{
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		c = pq.top(); pq.pop();
		
		a.first--;
		b.first--;
		c.first--;
		ls++;
		sol[ls].push_back( a.second );
		sol[ls].push_back( b.second );
		sol[ls].push_back( c.second );
		sort( sol[ls].begin(), sol[ls].end() );
		
		if ( a.first > 0 ) pq.push( a );
		if ( b.first > 0 ) pq.push( b );
		if ( c.first > 0 ) pq.push( c );
	}
	
	printf( "%d\n", ls );
	for ( i = 1; i <= ls; i++ )
	{
		printf( "%d %d %d\n", sol[i][2], sol[i][1], sol[i][0] );
	}
	return 0;
}