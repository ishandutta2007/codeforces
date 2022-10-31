#include <bits/stdc++.h>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int flag,a[501],b[501],c[501],n,tmp;
void work1()
{
	for(int j=0;j<=400;j++)c[j]=a[j];
	for(int j=400;j>=1;j--)a[j]=a[j-1];
	a[0]=0;
	flag=1;
	for(int j=0;j<=400;j++)
	{
		a[j]=a[j]+b[j]*tmp;
		if(a[j]<-1)flag=0;
		if(a[j]>1)flag=0;
	}
}
int main()
{
	cin>>n;
	a[0]=0; a[1]=1;
	b[0]=1; b[1]=0;
	tmp=1;
	for(int i=2;i<=n;i++)
	{
		work1();	
		if(!flag)
		{
			tmp=-tmp;
			for(int j=0;j<=400;j++)a[j]=a[j]+2*b[j]*tmp;
		}
		memcpy(b,c,sizeof(c));
	}
	int len=400;
	while(a[len]==0)len--;
	
	printf("%d\n",len);
	for(int i=0;i<=len;i++)printf("%d%c",a[i],i==len?'\n':' ');
	
	len=400;
	while(b[len]==0)len--;
		
	printf("%d\n",len);
	for(int i=0;i<=len;i++)printf("%d%c",b[i],i==len?'\n':' ');
	return 0;
}