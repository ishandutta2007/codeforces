#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
int n,m,i,j,a[200005],x,y,g[200005];
vector<int> b[200005];
pair<int,int> bfs1()
{
	queue<int> c,d;
	c.push(1);d.push(0);
	while (!c.empty())
	{
		int cx=c.front();
		for (i=0;i<b[cx].size();i++)
		{
			if (b[cx][i]!=cx&&b[cx][i]!=d.front())
			{
				if (a[cx]!=a[b[cx][i]]) return make_pair(c.front(),b[cx][i]);
				c.push(b[cx][i]);d.push(cx);
			}
		}
		c.pop();d.pop();
	}
	return make_pair(1,1);
} 
bool bfs2(int xx)
{
	for (int iii=1;iii<=n;iii++)
	g[iii]=0;
	for (int iii=1;iii<=n;iii++)
	if (iii!=xx&&g[iii]==0){g[i]=1;
	queue<int> c,d;
	c.push(iii);d.push(0);
	while (!c.empty())
	{
		int cx=c.front();
		for (i=0;i<b[cx].size();i++)
		{
			if (b[cx][i]!=cx&&b[cx][i]!=d.front()&&b[cx][i]!=xx&&g[b[cx][i]]==0)
			{
				if (a[cx]!=a[b[cx][i]]) return 0;
				c.push(b[cx][i]);d.push(cx);
				g[b[cx][i]]=1;
				int fff=c.front();
				/*cout<<c.front();c.push(fff);c.pop();
				while (c.front()!=fff)
				{
					 cout<<' '<<c.front();c.push(c.front());c.pop();
				}
				cout<<endl;*/
			}
		}
		c.pop();d.pop();
	}}
	return 1;
} 
void ch()
{
	pair<int,int> xx=bfs1();
	x=xx.first;
	y=xx.second;
	if (bfs2(x))
	{
			cout<<"YES"<<endl<<x;
			return;
	}
	if (bfs2(y))
	{
			cout<<"YES"<<endl<<y;
			return;
	}
	cout<<"NO";
}	
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		//x=i;y=i+1;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for (i=1;i<=n;i++) //a[i]=1;
	scanf("%d",&a[i]);
	ch();
	return 0;
}