#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int bsz = 200;

int n, m;
int a[100020];
int v[100020];

int lg;
int gd[100000];
int ps[512][100020];

int main()
{
	int i, j, k, s, an;
	int l, r;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		a[i] = k;
		if ( k <= n )
			v[k]++;
	}
	
	lg = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( v[i] >= i )
		{
			gd[++lg] = i;
			ps[lg][0] = 0;
			for ( j = 1; j <= n; j++ )
			{
				if ( a[j] == i )
					ps[lg][j] = ps[lg][j-1] + 1;
				else ps[lg][j] = ps[lg][j-1];
//				printf( "%d %d %d\n", lg, i, ps[lg][i] );
			}
		}
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &l, &r );
		an = 0;
		for ( j = 1; j <= lg; ++j )
		{
			s = gd[j];
			if ( ps[j][r] - ps[j][l-1] == s )
				an++;
		}
		printf( "%d\n", an );
	}
	return 0;
}