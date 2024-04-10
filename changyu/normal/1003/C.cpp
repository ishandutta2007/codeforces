#include<cstdio>
#define max(a,b)a>b?a:b
int n,m,a[5001];double ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]+=a[i-1];
    for(int j=m;j<=n;j++)
      for(int i=j;i<=n;i++)
        ans=max((a[i]-a[i-j])*1.0/j,ans);
	printf("%.12lf",ans);
	return 0;
}