#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node{
	int x,y,X,Y;
}a[1010],q1[1010],q2[1010];
bool cmpx(node a,node b) {return a.x<b.x;}
bool cmpy(node a,node b) {return a.y<b.y;}
void solve(int l,int r)
{
	int k=-1;
	if(l==r) return;
	sort(a+l,a+r+1,cmpx);
	int Max=a[l].X;
	for(int i=l+1;i<=r;i++)
	{
		if(Max<=a[i].x) {k=i;break;}
		Max=max(Max,a[i].X);
	}
	if(k!=-1)
	{
		solve(l,k-1);solve(k,r);
		return;
	}
	sort(a+l,a+r+1,cmpy);
	Max=a[l].Y;
	for(int i=l+1;i<=r;i++)
	{
		if(Max<=a[i].y) {k=i;break;}
		Max=max(Max,a[i].Y);
	}
	if(k!=-1)
	{
		solve(l,k-1);solve(k,r);
		return;
	}
	printf("NO");exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d %d",&a[i].x,&a[i].y,&a[i].X,&a[i].Y);
	solve(1,n);
	printf("YES");
}




/*
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node{
	int x,y,X,Y;
}a[1010],q1[1010],q2[1010];
bool cmpx(node a,node b) {return a.x<b.x;}
bool cmpy(node a,node b) {return a.y<b.y;}
void solve(int l,int r)
{
	int k=-1;
	if(l==r) return;
	sort(a+l,a+r+1,cmpx);
	int Max=a[l].X;
	for(int i=l+1;i<=r;i++)
	{
		if(Max<=a[i].x) {k=i;break;}
		Max=max(Max,a[i].X);
	}
	if(k!=-1)
	{
		solve(l,k-1);solve(k,r);
		return;
	}
	sort(a+l,a+r+1,cmpy);
	Max=a[l].Y;
	for(int i=l+1;i<=r;i++)
	{
		if(Max<=a[i].y) {k=i;break;}
		Max=max(Max,a[i].Y);
	}
	if(k!=-1)
	{
		solve(l,k-1);solve(k,r);
		return;
	}
	printf("NO");exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d %d",&a[i].x,&a[i].y,&a[i].X,&a[i].Y);
	solve(1,n);
	printf("YES");
}
*/