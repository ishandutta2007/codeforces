#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[200020],b[200020],ans;
int len;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	if(b[n])
	{
		for(int i=n;;--i)
		{
			if(b[i]==1)
			{
				len=n-i+1;
				break;
			}
			else if(i!=n&&b[i]+1!=b[i+1])break;
		}
	}
	ans=-0x3f3f3f3f;
//	printf("%d",len);
	for(int i=1;i<=n;++i)
		if(b[i]&&i<n-len+1)ans=max(ans,i-b[i]+1);
	if(len&&ans<=-len)printf("%d",n-len);
	else
	{
		for(int i=n-len+1;i<=n;++i)
			if(b[i])ans=max(ans,i-b[i]+1);
		printf("%d",max(ans,0)+n);
	}
	return 0;
}