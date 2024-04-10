#include<cstdio>
#define max(a,b)a>b?a:b
int n,a[101],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]+=a[i-1];
	ans=a[n]-1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
		if(i-j+1-a[i]+a[j-1]>a[i]-a[j-1])ans=max(ans,i-j+1-2*a[i]+2*a[j-1]+a[n]);
	printf("%d",ans);
	return 0;
}