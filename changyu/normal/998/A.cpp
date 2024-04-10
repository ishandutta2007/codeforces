#include<cstdio>
int n,a[11],s,ss,c,f=1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),s+=a[i];
	for(int i=1;i+1<(1<<n);i++)
	{
		ss=0;c=0;
	  for(int k=0;k<n;k++)
	 	if(i&(1<<k))ss+=a[k],c++;
	 	if(s-ss!=ss){
		printf("%d\n",c);
		for(int k=0;k<n;k++)if(i&(1<<k))if(f)printf("%d",k+1),f=0;else printf(" %d",k+1);
return 0;
		}
	}
	return 0*puts("-1");
}