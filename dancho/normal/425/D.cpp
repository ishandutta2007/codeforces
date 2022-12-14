#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int bsize = 65;

typedef pair<int,int> pii;

struct point
{
	int x, y, id;
	bool operator<( const point &p ) const
	{
		if ( x == p.x ) return y < p.y;
		return x < p.x;
	}
};

bool cmpy( point a, point b )
{
	return a.y < b.y;
}

int n;
point p[100020];

bool us[100020];
int ny[100020];

inline bool findPoint( int x, int y )
{
	point po;
	po.x = x; po.y = y;

/*	int l, r, m;
	l = 0; r = n;
	while ( l + 1 < r )
	{
		m = (l+r)/2;
		if ( p[m] < po )
			l = m;
		else r = m;
	}
	int k = r;*/

	int k = (int) (lower_bound( p + 1, p + n + 1, po ) - p );
	if ( p[k].x == x && p[k].y == y )
		return 1;
	return 0;
}

int main()
{
	int i, j, k, l, s, t;
	//int cnt;
	int a;
	long long ans = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &p[i].x, &p[i].y );
		p[i].id = i;
	}
	
	sort( p + 1, p + n + 1, cmpy );
	
	k = 0;
	for ( i = 1; i <= n; )
	{
		j = i;
		while ( ( p[j].y == p[i].y ) && ( j <= n ) )
		{
			ny[ p[j].id ] = k;
			j++;
		}
		k++;
		i = j;
	}
	sort( p + 1, p + n + 1 );
	
	ans = 0;
	for ( i = 1; i <= n; )
	{
		j = i;
		while ( ( p[j].x == p[i].x ) && ( j <= n ) )
			j++;
		if ( j-i >= bsize )
		{
			//golqmo
			memset( us, 0, sizeof( us ) );
			//us.clear();
			for ( k = i; k < j; k++ )
				us[ ny[p[k].id] ] = 1;
				//us[ p[k].y + 1000000 ] = 1;
			for ( k = 1; k < i; )
			{
				l = k;
				while ( ( p[k].x == p[l].x ) && ( l <= n ) )
					l++;
				
				s = k;
				t = i;
				while ( k < l )
				{
					if ( us[ ny[p[k].id] ] )
					{
						a = p[i].x - p[k].x;
						while ( ( p[t].y < p[k].y-a ) && ( t < j ) )
							t++;
						
						while ( ( p[s].y < p[k].y-a ) && ( s < l ) )
							s++;
						
						if ( ( p[s].y == p[k].y-a ) && ( p[t].y == p[k].y-a ) )
						{
//							printf( "op\n" );
							ans++;
						}
					}
					k++;
				}
				k = l;
			}
		}
		else
		{
			for ( k = i; k < j; k++ )
			{
				for ( l = k+1; l < j; l++ )
				{
					a = p[l].y-p[k].y;
					if ( ( findPoint( p[k].x-a, p[k].y ) ) && ( findPoint( p[k].x-a, p[l].y ) ) )
						ans++;
				}
			}
		}
		
		i = j;
	}
	printf( "%lld\n", ans );
	return 0;
}