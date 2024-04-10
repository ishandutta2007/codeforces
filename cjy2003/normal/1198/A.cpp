#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,I,a[400040],ans=0x3f3f3f3f,num;
int m,cnt[400040],sum[400040];
int main()
{
	scanf("%d %d",&n,&I);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	a[0]=-1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=a[i-1])++m;
		++cnt[m];
	}
	for(int i=1;i<=m;++i)sum[i]=sum[i-1]+cnt[i];
	I=I*8/n;
	I=min(I,20);
	num=1;
	for(int i=1;i<=I;++i)num<<=1;
	num=min(num,m);
	for(int i=1;i<=m-num+1;++i)
		ans=min(ans,sum[i-1]+sum[m]-sum[i+num-1]);
	printf("%d",ans);
	return 0;
}