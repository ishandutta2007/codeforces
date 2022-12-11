#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct zfc
{
	char a[101];
	int la;
}a[101];
bool cmp(zfc a,zfc b)
{
	return a.la<b.la;
}
bool cha(zfc a,zfc b)
{
	int flag;
	for(int i=0;i<=b.la-a.la;i++)
	{
		flag=0;
		for(int j=0;j<a.la;j++)
			if(a.a[j]!=b.a[j+i])
			{
				flag=1;
				break;
			}
		if(flag==0)return 1;	
	}
	return 0;
}
int n,flag1;
int main()
{
	scanf("%d",&n);
	gets(a[0].a);
	for(int i=1;i<=n;i++)
	{
		gets(a[i].a);
		a[i].la=strlen(a[i].a);	
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		flag1=0;
		for(int j=1;j<i;++j)
			if(cha(a[j],a[i])==0)
			{
				flag1=1;
				break;	
			}
		if(flag1==1)
		{
			printf("NO");
			return 0;	
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	puts(a[i].a);		
	return 0;
}