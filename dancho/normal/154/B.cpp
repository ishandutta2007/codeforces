#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> pii;

int n, m;
vector<int> pr;
vector<int> fa[100020];
set<int> us[100020];
set<int> S;

int a[100020];

int main()
{
	int i, j, k, l;
	char op[8];
	
	memset( a, 0, sizeof( a ) );
	
	scanf( "%d %d", &n, &m );
	for ( i = 2; i <= n; i++ )
	{
		if ( a[i] == 0 )
		{
			pr.push_back( i );
			fa[i].push_back( i );
			for ( j = i+i; j <= n; j=j+i )
			{
				a[j] = 1;
				fa[j].push_back( i );
			}
		}
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%s %d", op, &k );
		if ( op[0] == '-' )
		{
			if ( S.find( k ) == S.end() )
			{
				printf( "Already off\n" );
			}
			else
			{
				S.erase( k );
				for ( j = 0; j < (int) fa[k].size(); j++ )
				{
					l = fa[k][j];
					us[l].erase( k );
				}
				printf( "Success\n" );
			}
		}
		else if ( op[0] == '+' )
		{
			if ( S.find( k ) != S.end() )
			{
				printf( "Already on\n" );
			}
			else
			{
				for ( j = 0; j < (int) fa[k].size(); j++ )
				{
					l = fa[k][j];
					if ( us[l].size() > 0 )
					{
						break;
					}
				}
				if ( j < (int) fa[k].size() )
				{
					printf( "Conflict with %d\n", (*us[l].begin()) );
				}
				else
				{
					S.insert( k );
					for ( j = 0; j < (int) fa[k].size(); j++ )
					{
						l = fa[k][j];
						us[l].insert( k );
					}
					printf( "Success\n" );
				}
			}
		}
	}
	return 0;
}