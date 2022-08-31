#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
long long n,m,i,j,k,ans,fx[1005],fy[1005],tx[1005],ty[1005],x,nx,ny;
int mp[5005][5005];
char op;
vector<long long> allx,ally;
void bfs(int x,int y)
{
	queue<int> qx,qy;
	qx.push(x);
	qy.push(y);
	int i;
	while (!qx.empty())
	{
		int x=qx.front(),y=qy.front();
		qx.pop();
		qy.pop();
		if (!mp[x][y]) mp[x][y]=2;
		for (i=0;i<4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if (xx>-1&&yy>-1&&xx<=allx.size()+5&&yy<=ally.size()+5)
			{
				if (!mp[xx][yy])
				{
					qx.push(xx);
					qy.push(yy);
					mp[xx][yy]=2;
				}
			}
		}
	}
}
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf(" %c%d",&op,&x);
		fx[i]=nx;
		fy[i]=ny;
		if (op=='L')
		{
			ny-=x;
		}
		if (op=='R')
		{
			ny+=x;
		}
		if (op=='U')
		{
			nx-=x;
		}
		if (op=='D')
		{
			nx+=x;
		}
		tx[i]=nx;
		ty[i]=ny;
		if (fx[i]>tx[i]) swap(fx[i],tx[i]);
		if (fy[i]>ty[i]) swap(fy[i],ty[i]);
		tx[i]++;
		ty[i]++;
	}
	for (i=1;i<=n;i++)
	{
		allx.push_back(fx[i]);
		ally.push_back(fy[i]);
		allx.push_back(tx[i]);
		ally.push_back(ty[i]);
	}
	sort(allx.begin(),allx.end());
	allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());
	ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	allx.insert(allx.begin(),allx[0]-1);
	ally.insert(ally.begin(),ally[0]-1);
	allx.push_back(allx.back()+1);
	ally.push_back(ally.back()+1);
	for (i=1;i<=n;i++)
	{
		fx[i]=upper_bound(allx.begin(),allx.end(),fx[i])-allx.begin();
		fy[i]=upper_bound(ally.begin(),ally.end(),fy[i])-ally.begin();
		tx[i]=upper_bound(allx.begin(),allx.end(),tx[i])-allx.begin();
		ty[i]=upper_bound(ally.begin(),ally.end(),ty[i])-ally.begin();
		for (j=fx[i];j<tx[i];j++)
		{
			for (k=fy[i];k<ty[i];k++)
			{
				mp[j][k]=1;
			}
		}
	}
	bfs(0,0);
	//for (i=0;i<allx.size();i++) cerr<<allx[i]<<' ';cerr<<endl;
	//for (i=0;i<ally.size();i++) cerr<<ally[i]<<' ';cerr<<endl;
	for (i=1;i<allx.size();i++)
	{
		for (j=1;j<ally.size();j++)
		{
			if (mp[i][j]!=2)
			{
				ans+=(allx[i]-allx[i-1])*(ally[j]-ally[j-1]);
			}
		}
	}
	cout<<ans;
	return 0;
}