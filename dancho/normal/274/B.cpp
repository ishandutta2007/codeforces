#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> g[1<<20];
int v[1<<20];

bool us[1<<20];
long long p[1<<20], m[1<<20];

void solve( int w )
{
	int i, u;
	long long mxp = 0, mxm = 0;
	for ( i = 0; i < (int) g[w].size(); i++ )
	{
		u = g[w][i];
		if ( !us[u] )
		{
			us[u] = 1;
			solve( u );
			
			mxp = max( mxp, p[u] );
			mxm = max( mxm, m[u] );
		}
	}
	
	if ( (long long) v[w] + mxp >= mxm )
	{
		p[w] = mxp;
		m[w] = (long long) v[w] + p[w];
	}
	else
	{
		m[w] = mxm;
		p[w] = m[w] - v[w];
	}
}

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
	
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &v[i] );
	
	memset( us, 0, sizeof( us ) );
	us[1] = 1;
	solve( 1 );
	
	cout << m[1] + p[1] << "\n";
	return 0;
}