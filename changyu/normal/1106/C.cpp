#include<cstdio>
#include<algorithm>
int n;long long ans,a[300001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	std::sort(a+1,a+n+1);
	for(int i=1;i<n-i+1;i++)
	  ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	printf("%I64d",ans);
	return 0;
}