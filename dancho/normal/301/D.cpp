#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct el
{
	int l, r, id;
	bool operator<( const el& e ) const
	{
		return r < e.r;
	}
};

typedef pair<int,int> pii;

int n, m;
int p[1<<19];
int pos[1<<19];

long long le[1<<18];
long long mi[1<<18];
long long ans[1<<18];

vector<el> que;
vector<pii> upd;

void adds( int p, int v )
{
	if ( p == 0 ) return;
	for ( int i = p; i <= n; i += (i&(-i)) )
	{
//		printf( "II %d %d %d\n", i, p, n );
		mi[i] += v;
	}
}

void addmi( int p, int q )
{
	adds( p, 1 );
	adds( q+1, -1 );
}

long long getmi( int p )
{
	int r = 0;
	for ( int i = p; i > 0; i -= (i&(-i)) )
		r += mi[i];
	return r;
}

int main()
{
	int i, j;
	el e;
	
	memset( le, 0, sizeof( le ) );
	memset( mi, 0, sizeof( mi ) );
	scanf( "%d %d", &n, &m );
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &p[i] );
		pos[ p[i] ] = i;
	}

	for ( i = 1; i <= m; i++ )
	{
		int l, r;
		scanf( "%d %d", &l, &r );
		e.id = i;
		e.r = r;
		e.l = l;
		que.push_back( e );
	}
	for ( i = 1; i <= n; i++ )
	{
		for ( j = i; j <= n; j += i )
		{
//			printf( "%d / %d\n", pos[i], pos[j] );
			upd.push_back( make_pair( max( pos[j], pos[i] ), min( pos[j], pos[i] ) ) );
		}
	}
	
	sort( que.begin(), que.end() );
	sort( upd.begin(), upd.end() );
	
	i = j = 0;
	int la = 0;
	long long all = 0;
	while ( ( i < (int) que.size() ) && ( j < (int) upd.size() ) )
	{
//		printf( "OP %d %d __ %d %d :::: %d %d\n", i, j, que.size(), upd.size(), upd[j].first, que[i].r );
		while ( min( upd[j].first, que[i].r ) > la )
		{
			le[la] = all;
			la++;
		}
		if ( upd[j].first <= que[i].r )
		{
			all++;
//			printf( "ADD %d %d\n", upd[j].second, upd[j].first-1 );
			addmi( upd[j].second, upd[j].first-1 );
			j++;
		}
		else
		{
			ans[ que[i].id ] = all-le[ que[i].l-1 ]-getmi( que[i].l-1 );
			i++;
		}
	}
	
	while ( i < (int) que.size() )
	{
//		printf( "OP %d %d\n", i, j );
		while ( que[i].r > la )
		{
			le[la] = all;
			la++;
		}
		ans[ que[i].id ] = all-le[ que[i].l-1 ]-getmi( que[i].l-1 );
		i++;
	}
	
	for ( i = 1; i <= m; i++ )
	{
		printf( "%I64d\n", ans[i] );
	}
	
	return 0;
}