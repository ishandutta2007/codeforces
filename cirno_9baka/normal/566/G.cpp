#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=262144;
const int M=998244353;
int n,i,m,x,y,k,sta[N],top;
struct str{
	int x,y,f;
}a[N];
bool cmp(str a,str b)
{
	if(a.x==b.x&&a.y==b.y)
		return a.f<b.f;
	if(a.x==b.x)
		return a.y>b.y;
	return a.x<b.x;
}
long long mt(int a,int b,int x,int y)
{
	return 1ll*a*y-1ll*b*x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	scanf("%d %d",&x,&y);
	for(i=1;i<=n;++i)
	{
		++k;
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	for(i=1;i<=m;++i)
	{
		++k;
		scanf("%d %d",&a[k].x,&a[k].y);
		a[k].f=1;
	}
	sort(a+1,a+1+k,cmp);
	for(i=1;i<=k;++i)
		if(a[i].x!=a[i-1].x||a[i].y!=a[i-1].y)
		{
			while(top>0&&a[i].x>a[sta[top]].x&&a[i].y>a[sta[top]].y)
				--top;
			while(top>1&&mt(a[sta[top]].x-a[sta[top-1]].x,a[sta[top]].y-a[sta[top-1]].y,a[i].x-a[sta[top]].x,a[i].y-a[sta[top]].y)>0)
				--top;
			while(top>0&&a[i].x>a[sta[top]].x&&a[i].y>a[sta[top]].y)
				--top;
			sta[++top]=i;
		}
	for(i=1;i<=top;++i)
		if(!a[sta[i]].f)
		{
			puts("Max");
			return 0;
		}
	puts("Min");
}