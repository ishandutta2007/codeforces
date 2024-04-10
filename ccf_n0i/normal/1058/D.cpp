#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,a[500005],g1,g2;
string st;
int main()
{
	cin>>n>>m>>k;
	if (n%k==0)
	{
		puts("YES");
		printf("0 0\n0 %I64d\n%I64d %I64d\n",m,n/k*2,m);
		return 0;
	}
	if (m%k==0)
	{
		puts("YES");
		printf("0 0\n%I64d 0\n%I64d %I64d\n",n,n,m/k*2);
		return 0;
	}
	if ((n*m*2)%k==0)
	{
		k=(n*m*2)/k;
		long long x=__gcd(n,k);
		long long y=k/x;
		if (x<=n&&y<=m)
		{
			puts("YES");
			printf("0 0\n0 %I64d\n%I64d %I64d\n",y,x,y);
			return 0;
		}
	}
	puts("NO");
	return 0;
}