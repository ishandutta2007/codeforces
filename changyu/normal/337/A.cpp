#include<cstdio>
#include<algorithm>
int n,m,a[50];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	std::sort(a,a+n);
	int ans=a[m-1]-a[0];
	for(int i=m;i<n;i++)ans=std::min(ans,a[i]-a[i-m+1]);
	printf("%d",ans);
	return 0;
}