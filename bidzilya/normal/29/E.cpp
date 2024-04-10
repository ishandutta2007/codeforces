#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;

int n,m;
vector<vector<int> > g;
int b[500][500][2],p1[500][500][2],p2[500][500][2];
int q1[500*500*2],q2[500*500*2],q3[500*500*2];
int l,c;
bool found;

vector<int> a1,a2;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	g.resize(n);
	for (int i=0; i<m; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<2; k++)
				b[i][j][k]=0;
	b[0][n-1][0]=1;
	p1[0][n-1][0]=-1;
	p2[0][n-1][0]=-1;
	l=0;c=0;
	q1[0]=0;
	q2[0]=n-1;
	q3[0]=0;
	int v1,v2,u1,u2,stp;
	found=0;
	while (c<=l)
	{
		v1=q1[c];
		v2=q2[c];
		stp=q3[c];
		c++;
		if (stp==0)
		{
			for (int i=0; i<g[v1].size() && !found; i++)
			{
				int u1=g[v1][i];
				if (!b[u1][v2][1])
				{
					b[u1][v2][1]=1;
					p1[u1][v2][1]=v1;
					p2[u1][v2][1]=v2;
					l++;
					q1[l]=u1;
					q2[l]=v2;
					q3[l]=1;
				}
			}
		}else
		{
			for (int i=0; i<g[v2].size() && !found; i++)
			{
				int u2=g[v2][i];
				if (!b[v1][u2][0] && v1!=u2)
				{
					b[v1][u2][0]=1;
					p1[v1][u2][0]=v1;
					p2[v1][u2][0]=v2;
					l++;
					q1[l]=v1;
					q2[l]=u2;
					q3[l]=0;
					if (v1==n-1 && u2==0)
						found=1;
				}
			}
		}
		if (found)break;
	}
	if (found)
	{
		for (u1=n-1,u2=0;;)
		{
			a1.push_back(u1);
			a2.push_back(u2);
		    v1=p1[u1][u2][0];
			v2=p2[u1][u2][0];
			if (v1==-1 || v2==-1)break;
			u1=v1;
			u2=v2;
			v1=p1[u1][u2][1];
			v2=p2[u1][u2][1];
			if (v1==-1 || v2==-1)break;
			u1=v1;
			u2=v2;
		}
		printf("%d\n",a1.size()-1);
		for (int i=a1.size()-1; i>=0; i--)
			printf("%d ",a1[i]+1);
		printf("\n");
		for (int i=a2.size()-1; i>=0; i--)
			printf("%d ",a2[i]+1);
		printf("\n");
	}else
		printf("-1\n");
	return 0;
}