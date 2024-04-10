#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point
{
	int x, y, tp, on;
	bool operator<( const point& p ) const
	{
//		if ( x == p.x )
		return y < p.y;
//		return x < p.x;
	}
};

bool cmp( point a, point b )
{
	if ( a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}

point mp( int x, int y, int tp, int on )
{
	point r;
	r.x = x; r.y = y; r.tp = tp; r.on = on;
	return r;
}

int getDi( point a, point b )
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int n;
int np;
int bs, bso1, bso2, bst1, bst2, bsp1;
point p[1000020];
multiset<point> ms;

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	
	int i, j, k;
	point pb;
	np = 0;
	
	fscanf( fin, "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		fscanf( fin, "%d %d", &j, &k );
		np++;
		p[np] = mp( j, k, 4, i );
		np++;
		p[np] = mp( -j, k, 3, i );
		np++;
		p[np] = mp( j, -k, 2, i );
		np++;
		p[np] = mp( -j, -k, 1, i );
	}
	sort( p + 1, p + np + 1, cmp );
	
	ms.clear();
	multiset<point>::iterator it, jt, kt;
	j = 1;
	bs = (1<<30);
	bsp1 = bs + 1;
	for ( i = 1; i <= np; i++ )
	{
//		printf( "%d %d\n", i, np );
		while ( p[j].x < p[i].x - bsp1 )
		{
//			printf( "A\n" );
			it = ms.find( p[j] );
			ms.erase( it );
			j++;
		}
		//printf( "%d %d\n", ms.size(), i );
		jt = ms.lower_bound( mp( p[i].x, p[i].y-bsp1, p[i].tp, p[i].on ) );
		kt = ms.upper_bound( mp( p[i].x, p[i].y+bsp1, p[i].tp, p[i].on ) );
		for ( it = jt; it != kt; it++ )
		{
//			printf( "B\n" );
			pb = (*it);
			if ( pb.on != p[i].on )
			{
				if ( getDi( pb, p[i] ) < bs )
				{
					//printf( "SOL %d %d %d %d %d\n", getDi( pb, p[i] ), pb.on, pb.tp, p[i].on, p[i].tp );
					bs = getDi( pb, p[i] );
					bsp1 = ceil( sqrt( (double)bs ) );
					bso1 = pb.on;
					bst1 = pb.tp;
					bso2 = p[i].on;
					bst2 = p[i].tp;
					if ( bst1 == 4 )
						bst1 = 1;
					else if ( bst1 == 1 )
						bst1 = 4;
					else if ( bst1 == 2 )
						bst1 = 3;
					else if ( bst1 == 3 )
						bst1 = 2;
				}
			}
		}
		ms.insert( p[i] );
	}
	
	fprintf( fout, "%d %d %d %d\n", bso1, bst1, bso2, bst2 );
	
	fclose( fin );
	fclose( fout );
	return 0;
}