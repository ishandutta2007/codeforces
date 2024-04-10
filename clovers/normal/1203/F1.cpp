#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int n,r;
struct node{
	int x,y;
}a[N];

bool cmp(node p,node q)
{
	if(p.y*q.y<0) return p.y>0;
	if(p.y*q.y==0) //p.y=0,q.y<0()(y00) 
	{
		if(q.y<0) return p.y>q.y;
		if(p.y<0) return p.y>q.y; 
	}
	//00 
	if(p.y>=0) 
	{
		if(p.x==q.x) return p.y>q.y;
		return p.x<q.x;
	}
	else
	{
		if(p.x+p.y==q.x+q.y) return p.x>q.x;
		return p.x+p.y>q.x+q.y;
	}
}

int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(r<a[i].x) 
		{
			puts("NO"); 
			return 0;
		}
		r+=a[i].y;
	}
	if(r<0) puts("NO");
	else puts("YES");
	return 0;
}