#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,q,x[N],y[N],i,l,r;
struct str{
	int x,y,c;
}a[N];
bool cmp(str a,str b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	if(a.y!=b.y)
		return a.y<b.y;
	return a.c>b.c;
}
bool check(int m)
{
	int i,mn=1<<30;
	for(i=1;i<=m;++i)
		a[i]=(str){(x[i]+1)/2,(y[i]+1)/2,x[i]&1};
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;++i)
		if(a[i].c==1)
			mn=min(mn,a[i].y);
		else
			if(a[i].y>=mn)
				return false;
	return true;
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=q;++i)
		scanf("%d %d",&x[i],&y[i]);
	l=1,r=q+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	for(i=1;i<l;++i)
		puts("YES");
	for(i=l;i<=q;++i)
		puts("NO");
}