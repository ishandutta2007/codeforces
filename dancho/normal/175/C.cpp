#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<long long,long long> pii;

int n, t;
long long p[128];

pii e[128];

int main()
{
	int i, j, k;
	long long f, ans;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &j, &k );
		e[i] = make_pair( k, j );
	}
	
	scanf( "%d", &t );
	p[0] = 0;
	for ( i = 1; i <= t; i++ )
	{
		cin >> p[i];
	}
	
	sort( e + 1, e + n + 1 );
	sort( p + 1, p + t + 1 );
	
	ans = 0;
	long long d = 0;
	f = 1;
	for ( i = 1, j = 1; i <= n; i++ )
	{
		if ( ( e[i].second + d >= p[j] ) && ( j <= t ) )
		{
			ans = ans + (p[j]-d)*e[i].first*f;
			f = j+1;
			e[i].second = e[i].second - p[j] + d;
			d = p[j];
			i--;
			j++;
			continue;
		}
		else
		{
			ans = ans + e[i].first*e[i].second*f;
			d = d + e[i].second;
		}
	}
	
	cout << ans << endl;
	return 0;
}