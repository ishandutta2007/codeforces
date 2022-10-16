#include<bits/stdc++.h>
using namespace std;
int cc[1000001],cl[1001][1001],m,cnt=-1,n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char c[1001][1001];
void dfs(int x,int y,int ct)
{
	++cc[ct];
	cl[x][y]=ct;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<0||xx>=n||yy<0||yy>=m)continue;
		if(c[xx][yy]=='*'||cl[xx][yy]!=-1)continue;
		dfs(xx,yy,ct);
	}
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j],
			cl[i][j]=-1;
	if(n==1&&m==1&&c[0][0]=='*')
	{
		cout<<1;return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(cl[i][j]==-1&&c[i][j]=='.')
				++cnt,
				dfs(i,j,cnt);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(c[i][j]=='.')
				cout<<'.';
			else
			{
				vector<int>cun;
				for(int k=0;k<4;k++)
				{
					int xx=i+dx[k],yy=j+dy[k];
					if(xx<0||xx>n-1||yy<0||yy>m-1)continue;
					cun.push_back(cl[xx][yy]);
				}
				sort(cun.begin(),cun.end());
				int aa=cc[cun[0]]+1;
				for(int k=1;k<cun.size();k++)
					if(cun[k]!=cun[k-1])
						aa+=cc[cun[k]];
				cout<<aa%10;
			}
		cout<<endl;
	}
}