#include<cstdio>
#include<algorithm>
int n,a[200001],d=2e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+n+1);
	//for(int i=1;i<=n+n;i++)printf("%d ",a[i]);
	for(int i=n+1;i<n+n;i++)
	  d=std::min(a[i]-a[i-n+1],d);
	printf("%I64d",std::min(1ll*(a[n+n]-a[n+1])*(a[n]-a[1]),1ll*d*(a[n+n]-a[1])));
	return 0;
}