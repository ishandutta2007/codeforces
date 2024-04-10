#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=998244353;
int n,m,i,a[1000005],l,r,s=1,p[1000005],k,ans,num,j;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	m=m*8/n;
	sort(a+1,a+1+n);
	if(m>30)
	{
		printf("0");
		return 0;
	}
	l=1;
	for(i=1;i<=m;i++)
		s*=2;
	for(i=1;i<=n;)
	{
		for(j=i;a[i]==a[j]&&j<=n;j++);
		p[++k]=j-i;
		i=j;
	}
	j=1;
	for(i=1;i<=k;i++)
	{
		while(j<=k&&j-i<s)
		{
			num+=p[j];
			j++;
		}
		ans=max(ans,num);
		num-=p[i];
	}
	cout<<n-ans<<endl;
}