#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const double eps = 1e-7;

struct el
{
	int m, v;
	int no;
	bool operator<( const el& x ) const
	{
		if ( m == x.m ) return v < x.v;
		return m < x.m;
	}
};

int n, k;
int h;
el e[100020];
vector<int> sol, cur;

int main()
{
	int i, j;
	int c;
	double le, ri, mi;
	
	scanf( "%d %d %d", &n, &k, &h );
	for ( i = 1; i <= n; i++ )
	{
		e[i].no = i;
		scanf( "%d", &e[i].m );
	}
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &e[i].v );
	}
	
	sort( e + 1, e + n + 1 );
	
	le = 0; ri = 1e10;
	for ( j = 0; j < 100; j++ )
	{
		mi = (le+ri)/2.0;
		
		c = 1;
		cur.clear();
		for ( i = 1; i <= n; i++ )
		{
//			printf( "%d %lf __ %lf %lf\n",i, (double)e[i].v, (double)c*(double)h/(double)e[i].v, mi );
			if ( (long long)c*h <= (long long)( mi*(double)e[i].v ) + eps )
			{
				c++;
				cur.push_back( e[i].no );
			}
		}
		if ( (int)cur.size() >= k )
		{
			ri = mi;
			sol = cur;
		}
		else le = mi;
	}
	
	printf( "%d", sol[0] );
	for ( i = 1; i < (int) sol.size(); i++ )
		printf( " %d", sol[i] );
	printf( "\n" );
	
	return 0;
}