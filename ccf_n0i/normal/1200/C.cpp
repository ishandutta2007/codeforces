#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
long long n,m,q,i,j,g,sx,sy,ex,ey;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	g=__gcd(n,m);
	while(q--)
	{
		scanf("%I64d%I64d%I64d%I64d",&sx,&sy,&ex,&ey);
		long long t1,t2;
		if(sx==1) t1=(sy-1)/(n/g);else t1=(sy-1)/(m/g);
		if(ex==1) t2=(ey-1)/(n/g);else t2=(ey-1)/(m/g);
		if(t1==t2)puts("YES");else puts("NO");
	}
	return 0;
}