#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,t,a[105],rem;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&rem,&m);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n-1)
		{
			rem+=a[i];
			int t=max(0,a[i+1]-m);
			rem-=t;
			if(rem<0)break;
		}
		if(i<n)puts("NO");else puts("YES");
	}
	return 0;
}