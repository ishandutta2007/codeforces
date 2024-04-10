#include<bits/stdc++.h>
using namespace std;
queue<int>q[2];
int a[1001][1001],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int xx,yy;
char c[1001][1001];
int main()
{
	int x,y;
	cin>>x>>y;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='E')
				q[0].push(i),
				q[1].push(j);
			if(c[i][j]=='S')
				xx=i,
				yy=j;
			a[i][j]=-1;
		}
	while(!q[0].empty())
	{
		for(int i=0;i<4;i++)
			if(a[dx[i]+q[0].front()][dy[i]+q[1].front()]==-1)
				if(dx[i]+q[0].front()>=0&&dx[i]+q[0].front()<x&&dy[i]+q[1].front()>=0&&dy[i]+q[1].front()<y)
					if(c[dx[i]+q[0].front()][dy[i]+q[1].front()]!='T')
						q[0].push(dx[i]+q[0].front()),
						q[1].push(dy[i]+q[1].front()),
						a[dx[i]+q[0].front()][dy[i]+q[1].front()]=a[q[0].front()][q[1].front()]+1;
		q[0].pop();
		q[1].pop();
	}
	int ans=0;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(isdigit(c[i][j]))
				if(a[i][j]<=a[xx][yy]&&a[i][j]!=-1)
					ans=ans+c[i][j]-'0';
	cout<<ans;
}