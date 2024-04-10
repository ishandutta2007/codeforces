#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=200005;
int n;
int a[maxn];
LL s[maxn];

void init()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
}

double calc(int i,int len)
{
	return double(s[i]-s[i-len-1]+s[n]-s[n-len])/(len+len+1)-a[i];
}

void work()
{
	int len=0,ai,al;
	double ans=-1;
	for(int i=n;i;i--)
	{
		if(len)len--;
		len=min(len,i-1);
		while(i-len>1&&n-len>i&&calc(i,len+1)>calc(i,len))len++;
		if(calc(i,len)>ans)
		{
			ans=calc(i,len);
			ai=i;al=len;
		}
	}
	printf("%d\n",al+al+1);
	for(int i=ai-al;i<=ai;i++)
		printf("%d ",a[i]);
	for(int i=n-al+1;i<=n;i++)
		printf("%d ",a[i]);
}

int main()
{
	init();
	work();
	return 0;
}