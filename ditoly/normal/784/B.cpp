#include<cstdio>
const int o[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main()
{
	int n,ans;
	scanf("%d",&n);ans=!n;
	while(n)ans+=o[n%16],n/=16;
	printf("%d",ans);
}