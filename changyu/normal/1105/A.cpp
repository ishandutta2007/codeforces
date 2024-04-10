#include<cstdio>
const int N=1001;
int n,a[N],ans=12345678,s,t;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int j=1;j<=100;j++)
	{
	  s=0;
	  for(int i=1;i<=n;i++){
		if(a[i]>j+1)s+=a[i]-j-1;
		if(a[i]<j-1)s+=j-1-a[i];
	  }
	  if(s<ans)ans=s,t=j;
	}printf("%d %d",t,ans);
	return 0;
}