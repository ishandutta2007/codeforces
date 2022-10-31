#include <bits/stdc++.h>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int h,n;
int a[1100000];
int f[1100000];
bool check()
{
	for(int i=1;i<h;i++)if (a[i]!=1 && a[i+1]!=1)return 0;
	return 1;
}
void work1()
{
	int pre=0;
	int now=0;
	for(int i=0;i<=h;i++)
	{
		for(int j=1;j<=a[i];j++)f[++now]=pre;
		pre=now;
	}
}
void work2()
{
	int pre1=0,pre2=0;
	int now=0;
	for(int i=0;i<=h;i++)
	{
		int ff=pre1;
		for(int j=1;j<=a[i];j++){ f[++now]=ff; ff++; if (ff>pre2)ff=pre1;}
		pre1=pre2+1;
		pre2=now;
	}
}
int main()
{
	scanf("%d",&h); 
	n=0;
	for(int i=0;i<=h;i++){ scanf("%d",&a[i]); n+=a[i]; }
	if (check()){ puts("perfect"); return 0;}
	puts("ambiguous");
	work1();
	for(int i=1;i<=n;i++)printf("%d%c",f[i],i==n?'\n':' ');
	work2();
	for(int i=1;i<=n;i++)printf("%d%c",f[i],i==n?'\n':' ');
}