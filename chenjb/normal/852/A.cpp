#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int n,sum,a[200010],b[200010],c[200010];
int save[200010];
int tot,cnt1,cnt2,cnt3;
char s[200010];
void calc()
{
	sum=0;
	for(int i=1;i<=cnt2;i++)sum+=b[i];
	
	cnt3=0;
	for(;sum;sum/=10)c[++cnt3]=sum%10;
	for(int i=1;i<=cnt3/2;i++)swap(c[i],c[cnt3-i+1]);

	sum=0;
	for(int i=1;i<=cnt3;i++)sum+=c[i];
	if (sum>9)return;
	
	printf("%d",a[1]);
	for(int i=2;i<=cnt1;i++)printf("+%d",a[i]);
	puts("");
	printf("%d",b[1]);
	for(int i=2;i<=cnt2;i++)printf("+%d",b[i]);
	puts("");
	printf("%d",c[1]);
	for(int i=2;i<=cnt3;i++)printf("+%d",c[i]);
	puts("");

	exit(0);
}
void dfs(int dep)
{
	if (dep>tot)
	{
		calc();
		return;
	}		
	if (b[cnt2]!=0)
	{
		int tmp=b[cnt2];
		b[cnt2]=b[cnt2]*10+save[dep];
		dfs(dep+1);
		b[cnt2]=tmp;
	}
	++cnt2;
	b[cnt2]=save[dep];
	dfs(dep+1);
	cnt2--;
}
void randomsplit()
{
	cnt1=1;
	a[1]=s[0]-'0';
	for(int i=1;i<n;i++)
	{
		int key=rand()&1;
		if (0<a[cnt1]&&a[cnt1]<=9&&key)
		{
			a[cnt1]=a[cnt1]*10+s[i]-'0';
		}
		else
		{
			a[++cnt1]=s[i]-'0';
		}
	}
}
int main()
{
	srand(time(NULL));
	scanf("%d\n",&n);
	scanf("%s",s);
	while (1)
	{
		randomsplit();
		sum=0;
		for(int i=1;i<=cnt1;i++)sum+=a[i];
		tot=0;
		for(;sum;sum/=10)save[++tot]=sum%10;
		for(int i=1;i<=tot/2;i++)swap(save[i],save[tot-i+1]);
		cnt2=1;
		b[1]=save[1];
		dfs(2);
	}
	return 0;
}