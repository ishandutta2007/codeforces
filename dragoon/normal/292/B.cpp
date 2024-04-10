#include<stdio.h>
#include<vector>
using namespace std;

vector<int> V[100005];
int n, m;

int bus()
{
	int d1, d2, i;

	if(n != m+1)
		return 0;

	if( n == 1 ) 
		return 1;

	d1 = d2 = 0;
	for(i = 1; i <= n; i++)
	{
		if( V[i].size() == 1 ) d1++;
		else if( V[i].size() == 2 ) d2++;
		else return 0;
	}

	if(d1 == 2 && d2 == n - 2)
		return 1;
	return 0;
}

int ring()
{
	if( n!= m)
		return 0;

	int i;

	for(i = 1; i <= n; i++)
		if( V[i].size() != 2 )
			return 0;
	return 1;
}

int star()
{
	if( n!= m+1 )
		return 0;

	int i, x = 0;
	for(i = 1; i <= n; i++)
		if( V[i].size() > 1 )
			x++;

	if( x==1 )
		return 1;
	return 0;
}

int main()
{
	int i, u, v;

	scanf("%d %d", &n, &m);

	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		V[ u ].push_back( v );
		V[ v ].push_back( u );
	}

	if( bus() ) printf("bus topology\n");
	else if( ring() ) printf("ring topology\n");
	else if( star() ) printf("star topology\n");
	else printf("unknown topology\n");

	return 0;
}