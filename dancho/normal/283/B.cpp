#include <cstdio>
#include <cstring>

int n;
int a[1<<20];
int ne[1<<20];
long long de[1<<20];

int us[1<<20];

void gogo( int i )
{
	int j, k;
	j = i+a[i];
	de[i] += a[i];
	if ( j <= 0 || j > n )
	{
		ne[i] = -2;
	}
	else if ( j == 1 )
	{
		ne[i] = -1;
	}
	else
	{
		k = j - a[j];
		de[i] += a[j];
		if ( k <= 0 || k > n )
		{
			ne[i] = -2;
		}
		else if ( k == 1 )
		{
			ne[i] = -1;
		}
		else
		{
			if ( us[k] == 0 )
			{
				us[k] = us[i];
				gogo( k );
				ne[i] = ne[k];
				de[i] += de[k];
			}
			else if ( us[k] != us[i] )
			{
				ne[i] = ne[k];
				de[i] += de[k];
			}
			else
			{
				ne[i] = -1;
			}
		}
	}
}
int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 2; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	memset( de, 0, sizeof( de ) );
	memset( us, 0, sizeof( us ) );
	for ( i = 2; i <= n; i++ )
	{
		if ( us[i] == 0 )
		{
			us[i] = i;
			gogo( i );
		}
	}
	
	for ( i = 1; i < n; i++ )
	{
		a[1] = i;
		us[1] = 1;
		de[1] = 0;
		ne[1] = 0;
		gogo( 1 );
		if ( ne[1] == -2 )
			printf( "%I64d\n", de[1] );
		else if ( ne[1] == -1 )
			printf( "-1\n" );
	}
	return 0;
}