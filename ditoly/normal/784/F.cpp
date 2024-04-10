#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
int ran(){static int x=23333;return x^=x<<13,x^=x>>17,x^=x<<5;}
int main()
{
	int n,i,j,mn,a[11],t=clock();
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		for(mn=101,j=1;j<=n;++j)mn=min(mn,a[j]);
		printf("%d ",mn);
		for(j=1;j<=n;++j)if(a[j]==mn){a[j]=101;break;}
	}
	while(double(clock()-t)/CLOCKS_PER_SEC<1.9);
}