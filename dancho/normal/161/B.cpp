#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

struct el
{
	int c, t, no;
	
	bool operator<( const el& x ) const
	{
		return c < x.c;
	}
};

int n, k;
el p[1024];
bool us[1024];

vector<el> ca[1024];

int main()
{
	int i, j, jj;
	long long sm = 0, ot = 0;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &p[i].c, &p[i].t );
		sm = sm + 2LL*p[i].c;
		p[i].no = i;
	}
	
	sort( p + 1, p + n + 1 );
	memset( us, 0, sizeof( us ) );
	
	j = 0;
	jj = 0;
	for ( i = n; i > 0; i-- )
	{
		if ( ( p[i].t == 1 ) && ( j < k ) )
		{
			j++;
			ca[j].push_back( p[i] );
			ot = ot + p[i].c;
			
			jj = j;
			us[i] = 1;
		}
	}
		for ( i = 1; i <= n; i++ )
		{
			if ( us[i] == 0 )
			{
				if ( j < k ) j++;
				ca[j].push_back( p[i] );
			}
		}
	
	ot = 0;
	for ( i = 1; i <= jj; i++ )
	{
		sort( ca[i].begin(), ca[i].end() );
		ot = ot + ca[i][0].c;
	}
	
	sm = sm - ot;
	cout << (sm/2);
	if ( sm%2 == 0 )
		printf( ".0\n" );
	else printf( ".5\n" );
	for ( i = 1; i <= k; i++ )
	{
		printf( "%d", ca[i].size() );
		for ( j = 0; j < (int)ca[i].size(); j++ )
			printf( " %d", ca[i][j].no );
		printf( "\n" );
	}
	return 0;
}