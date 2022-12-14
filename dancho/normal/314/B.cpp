#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int,int> pii;

pii f[128];

int la, lc;
char a[128], c[128];
int b, d;

int main()
{
	int i, j, k;
	
	scanf( "%d %d", &b, &d );
	scanf( "%s", a );
	scanf( "%s", c );
	
	la = strlen( a );
	lc = strlen( c );
	for ( i = 0; i < lc; i++ )
	{
		f[i].first = 0;
		k = i;
		for ( j = 0; j < la; j++ )
		{
			if ( a[j] == c[k] )
			{
				k++;
				if ( k >= lc )
				{
					f[i].first++;
					k = 0;
				}
			}
		}
		f[i].second = k;
	}
	
	int ans = 0;
	k = 0;
	for ( i = 1; i <= b; i++ )
	{
		ans += f[k].first;
		k = f[k].second;
	}
	
	printf( "%d\n", ans/d );
	return 0;
}