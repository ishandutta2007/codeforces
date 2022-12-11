#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100010],pre[100010],suf[100010];
int mx,p;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pre[i]=a[i]|pre[i-1];
	for(int i=n;i;--i)suf[i]=suf[i+1]|a[i];
	p=1;
	for(int i=1;i<=n;++i)
	{
		int w=a[i]-(a[i]&(pre[i-1]|suf[i+1]));
		if(w>mx)mx=w,p=i;
	}
	printf("%d ",a[p]);
	for(int i=1;i<p;++i)printf("%d ",a[i]);
	for(int i=p+1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}