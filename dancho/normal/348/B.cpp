#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

long long gcd( long long a, long long b )
{
	if ( b == 0 ) return a;
	return gcd( b, a%b );
}

long long lcm( long long a, long long b )
{
	return a*b/gcd(a, b);
}

long long rem = 0;
int n;
vector<int> g[1<<20];
long long a[1<<20];
long long m[1<<20];
long long deg[1<<20];
bool us[1<<20];

void dfs( int v )
{
	if ( (int) g[v].size() == 1 && v != 1 )
	{
		return;
	}
	if ( v != 1 )
		deg[v] = (int) g[v].size() - 1;
	else
		deg[v] = (int) g[v].size();
	
	int i, u;
	long long sm = 0, cnt = 0, mn = (1LL<<62);
	m[v] = 1;
	for ( i = 0; i < (int) g[v].size(); ++i )
	{
		u = g[v][i];
		if ( !us[u] )
		{
			us[u] = 1;
			dfs( u );
			m[v] = lcm( m[v], m[u] );
			cnt++;
			if ( a[u] < mn )
				mn = a[u];
			sm += a[u];
		}
	}
	m[v] = m[v] * deg[v];
	if ( mn == 0 )
	{
		rem += sm;
		a[v] = 0;
		return;
	}
	long long re = (cnt*mn / m[v])*m[v];
	
	rem += (sm - re);
	a[v] = re;
}

int main()
{
	int i, j, k;
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++)
	{
		scanf( "%d", &k );
		a[i] = k;
		m[i] = 1;
	}
	
	for ( i = 1; i < n; i++)
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
	
	memset( us, 0, sizeof( us ) );
	us[1] = 1;
	dfs( 1 );
	
	cout << rem << "\n";
	return 0;
}