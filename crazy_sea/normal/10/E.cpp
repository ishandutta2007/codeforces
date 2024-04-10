#include<cstdio>
using namespace std;
const int inf=0x3f3f3f3f;
int n,a[500],ans=inf,x,now,s1,s2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			now=a[i]-1;s1=1,s2=0;
			for(int k=i;k<=j;k++) s1+=now/a[k],now%=a[k];
			x=now=a[i]+a[j]-now-1;
			for(int k=1;k<=n;k++) s2+=now/a[k],now%=a[k];
			if(s1<s2&&x<ans) ans=x;
		}
	printf("%d",ans==inf?-1:ans);
}