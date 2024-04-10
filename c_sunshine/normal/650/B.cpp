#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a,b,T,ans;
char s[1000005];
int c[1000005];

int can(int i,int j)
{
	int tm=c[i]+c[n]-c[j-1]+a*min(n-j+1+(i-1)*2,(n-j+1)*2+i-1);
	return tm<=T;
}

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&T);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='h')c[i]=1;
		else c[i]=b+1;
	for(int i=1;i<=n+1;i++)
		c[i]+=c[i-1];
	int i,j;
	for(j=n+1;j>2&&can(1,j-1);j--);
	for(i=1;i<=n;i++)
	{
		while(j<=i)j++;
		while(j<=n&&!can(i,j))j++;
		if(can(i,j))ans=max(ans,n-j+1+i);
		else break; 
	}
	cout<<ans<<endl;
	return 0;
}