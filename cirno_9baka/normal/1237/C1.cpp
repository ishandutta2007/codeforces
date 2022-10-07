#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,ans,j,k,m,u;
struct str{
	int x,y,z,t;
}a[100005],p[100005];
bool cmp(str a,str b)
{
	if(a.x==b.x)
	{
		if(a.y==b.y)
			return a.z<b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
		a[i].t=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;)
	{
		for(j=i;j<=n&&a[i].x==a[j].x&&a[i].y==a[j].y;j++);
		for(k=i;k+2<=j;k+=2)
			printf("%d %d\n",a[k].t,a[k+1].t);
		if(k==j-1)
			p[++m]=a[k];
		i=j;
	}
	for(i=1;i<=m;)
	{
		for(j=i;j<=m&&p[i].x==p[j].x;j++);
		for(k=i;k+2<=j;k+=2)
			printf("%d %d\n",p[k].t,p[k+1].t);
		if(k==j-1)
			a[++u]=p[k];
		i=j;
	}
	for(i=1;i<=u;i+=2)
		printf("%d %d\n",a[i].t,a[i+1].t);
}