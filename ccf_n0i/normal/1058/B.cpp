#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[100005],i,j,z=0,ss,x,y;
int main()
{
	cin>>n>>m>>k;
	while (k--)
	{
		cin>>x>>y;
		if (x+y>=m&&x+y<=n+n-m)
		{
			if (x-y>=-m&&x-y<=m)
			{
				puts("YES");
				continue;
			}
		}
		puts("NO");
	}
	return 0;
}