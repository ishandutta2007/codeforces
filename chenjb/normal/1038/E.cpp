#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n;
multiset<int> a[5][5];
struct node
{
	int x,y,w;
};

vector< node > edge;

int f[110000][4];
void update(int &x,int y)
{
	if (x<y)x=y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int c1,x,c2;
		scanf("%d%d%d",&c1,&x,&c2);
		if (c1>c2)swap(c1,c2);
		a[c1][c2].insert(x);
	}

	edge.clear();
	for(int i=1;i<=4;i++)
		if (a[i][i].size()!=0)
		{
			int sum=0;
			for(auto p:a[i][i])sum+=p;
			node x;
			x.x=i,x.y=i,x.w=sum;
			edge.push_back(x);
		}

	for(int i=1;i<=4;i++)
		for(int j=i+1;j<=4;j++)
			if (a[i][j].size()!=0)
			{
				if (a[i][j].size()%2==0)
				{
					node x;
					x.x=i,x.y=j,x.w=*a[i][j].begin();
					edge.push_back(x);
					a[i][j].erase(a[i][j].begin());

					int sum=0;
					for(auto p:a[i][j])sum+=p;
					x.x=i,x.y=j,x.w=sum;
					edge.push_back(x);
				}
				else
				{
					node x;
					x.x=i,x.y=j,x.w=*a[i][j].begin();
					edge.push_back(x);
					a[i][j].erase(a[i][j].begin());

					if (a[i][j].size()==0)continue;
					int sum=0;
					for(auto p:a[i][j])sum+=p;
					x.x=i,x.y=i,x.w=sum;
					edge.push_back(x);
				}
			}


	int full=(1<<edge.size())-1;
	int cnt=edge.size();

	//for(auto p:edge)cout<<p.x<<" "<<p.y<<" "<<p.w<<endl;


	for(int i=0;i<cnt;i++)
	{
		update(f[1<<i][edge[i].y],edge[i].w);
		update(f[1<<i][edge[i].x],edge[i].w);
	}

	for(int i=1;i<full;i++)
		for(int j=0;j<cnt;j++)
			if ((i&(1<<j))==0)
			{
				update(f[i|(1<<j)][edge[j].y],f[i][edge[j].x]+edge[j].w);
				update(f[i|(1<<j)][edge[j].x],f[i][edge[j].y]+edge[j].w);
			}
	int ans=0;
	for(int i=1;i<=full;i++)
		for(int j=1;j<=4;j++)
			ans=max(ans,f[i][j]);
	cout<<ans<<endl;
}