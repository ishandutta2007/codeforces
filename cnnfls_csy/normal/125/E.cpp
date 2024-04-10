#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,k,x,y,z,i,j,fa[5005],deg;
double l,r,mid,st;
struct ii
{
	int x,y,id;
	double z;
}bi[100005];
bool cmp(ii x,ii y)
{
	return x.z<y.z;
}
void indsu()
{
	int i;
	for (i=1;i<=n;i++) fa[i]=i;
}
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool check()
{
	//sort(bi+1,bi+n+1,cmp);
	indsu();
	int i;
	for (i=1;i<=m;i++)
	{
		if (bi[i].x==1) continue;
		if (find(bi[i].x)!=find(bi[i].y))
		{
			fa[find(bi[i].x)]=find(bi[i].y);
		}
	}
	set<int> vis;
	for (i=2;i<=n;i++) vis.insert(find(i));
	if (vis.size()>k) return 0;
	return 1;
}
int get(double x)
{
	indsu();
	int i,deg=0;
	for (i=1;i<=m;i++)
	{
		if (bi[i].x==1) bi[i].z+=x;
	}
	sort(bi+1,bi+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		if (find(bi[i].x)!=find(bi[i].y))
		{
			if (bi[i].x==1) deg++;
			fa[find(bi[i].x)]=find(bi[i].y);
		}
	}
	for (i=1;i<=m;i++)
	{
		if (bi[i].x==1) bi[i].z-=x;
	}
	return deg;
}
int print(double x)
{
	indsu();
	int i,deg=0;
	for (i=1;i<=m;i++)
	{
		if (bi[i].x==1) bi[i].z+=x;
	}
	sort(bi+1,bi+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		if (find(bi[i].x)!=find(bi[i].y))
		{
			if (bi[i].x==1)
			{
				if (bi[i].x==1) deg++;
				if (deg>k) continue;
			}
			cout<<bi[i].id<<' ';
			fa[find(bi[i].x)]=find(bi[i].y);
		}
	}
}
int main()
{
	double st=clock();
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for (i=1;i<=m;i++)
	{
		cin>>bi[i].x>>bi[i].y>>bi[i].z;
		bi[i].id=i;
		if (bi[i].x>bi[i].y) swap(bi[i].x,bi[i].y);
		if (bi[i].x==1) deg++;
	}
	if (deg<k||!check())
	{
		cout<<-1;
		return 0;
	}
	cout<<n-1<<endl;
	l=-1e5;r=1e5+0.3;
	while ((clock()-st)/CLOCKS_PER_SEC<3.5)
	{
		mid=(l+r)/2;
		int ed=get(mid);
		if (ed<k) r=mid;
		if (ed>k) l=mid;
		if (ed==k) break;
		if (r-l<0.9&&ed>k) break;
	}
	print(mid);
	return 0;
}