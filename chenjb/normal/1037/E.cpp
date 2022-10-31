#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
using namespace std;
int ans[510000];
set<int>a[510000];
int q[510000];
int x[510000],y[510000];
bool v[510000];
int n,m,k;
void init()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=m;i++)
	{
		a[x[i]].insert(y[i]);
		a[y[i]].insert(x[i]);
	}
}
int main()
{
	//freopen("1.in","r",stdin);

	init();


	memset(v,0,sizeof(v));
	int head=0,tail=0;
	int now=n;
	for(int i=1;i<=n;i++)
		if(a[i].size()<k)
		{
			q[++tail]=i;
			v[i]=1;
		}



	for(int i=m;i>0;i--)
	{
		while(head!=tail)
		{
			head++;
			now--;

			for(auto p:a[q[head]])
			{
				if(a[p].find(q[head])==a[p].end())continue;
				a[p].erase(q[head]);
				if(a[p].size()<k && v[p]==0)q[++tail]=p,v[p]=1;
			}

		}


		ans[i]=now;


		if(a[x[i]].find(y[i])!=a[x[i]].end())
		{
			a[x[i]].erase(y[i]);
			if(a[x[i]].size()<k && v[x[i]]==0)
			{
				q[++tail]=x[i];
				v[x[i]]=1;
			}
		}


		if(a[y[i]].find(x[i])!=a[y[i]].end())
		{
			a[y[i]].erase(x[i]);
			if(a[y[i]].size()<k && v[y[i]]==0)
			{
				q[++tail]=y[i];
				v[y[i]]=1;
			}
		}


	}



	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}