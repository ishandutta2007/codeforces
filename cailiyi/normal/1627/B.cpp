#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,m,a[N+5],cnt;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m),cnt=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[cnt++]=max(i-1,n-i)+max(j-1,m-j);
		sort(a,a+cnt);
		for(int i=0;i<cnt;++i)
			printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}