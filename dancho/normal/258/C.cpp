#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int mod = 1000000007;

long long qpow( long long v, long long st )
{
	v %= mod;
	long long r = 1;
	while ( st )
	{
		if ( st&1 )
		{
			r *= v;
			if ( r >= mod )
				r %= mod;
		}
		v = v * v;
		if ( v >= mod )
			v %= mod;
		st = st / 2;
	}
	return r;
}

int n;
int a[100020];
set<int> dels[100020];
vector<int> pdel;

int pr[100020];

int main()
{
	int i, j, k, s, v;
	int mx = 0;
	set<int>::iterator it;

	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		if ( a[i] > mx )
			mx = a[i];
	}
	
	sort( a + 1, a + n + 1 );
	
	memset( pr, 0, sizeof( pr ) );
	for ( i = 1; i <= mx; i++ )
		dels[i].insert( 1 );
	for ( i = 2; i <= mx; i++ )
	{
		if ( !pr[i] )
		{
			for ( j = i; j <= mx; j += i )
			{
				pr[j] = 1;
				pdel.clear();
				for ( it = dels[j].begin(); it != dels[j].end(); it++ )
				{
					pdel.push_back( *it );
				}
				s = j;
				v = 1;
				while ( s % i == 0 )
				{
					s = s / i;
					v *= i;
					for ( k = 0; k < (int) pdel.size(); k++ )
					{
						dels[j].insert( v*pdel[k] );
					}
				}
			}
		}
	}
	
	long long sol = 0, p;
	int le, ri, mi;
	
	for ( i = 1; i <= mx; i++ )
	{
		k = 1;
		p = 1;
		for ( it = dels[i].begin(), it++, j = 1; it != dels[i].end(); it++, j++ )
		{
			le = 0; ri = n;
			while ( le + 1 < ri )
			{
				mi = (le+ri) / 2;
				if ( a[mi] < (*it) )
					le = mi;
				else
					ri = mi;
			}
			p = p * qpow( j, ri-k );
			if ( p >= mod ) p %= mod;
			k = ri;
		}
		j = dels[i].size();
		p = p * ( qpow( j, n-k+1) - qpow( (j-1), n-k+1 ) + mod );
		if ( p >= mod ) p %= mod;
		sol += p;
		if ( sol >= mod )
			sol %= mod;
	}
	printf( "%d\n", (int) sol );

	return 0;
}