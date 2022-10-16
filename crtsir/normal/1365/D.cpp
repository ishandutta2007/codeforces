#include<bits/stdc++.h>
using namespace std;
bool vis[53][53];
int T,n,m,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
string s[53];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>s[i];
		bool ok=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j]=='B')
					for(int k=0;k<4;k++)
						if(i+dx[k]>=0&&i+dx[k]<n)
							if(j+dy[k]>=0&&j+dy[k]<m)
								if(s[i+dx[k]][j+dy[k]]=='.')
									s[i+dx[k]][j+dy[k]]='#';
								else
									if(s[i+dx[k]][j+dy[k]]=='G')
										ok=0;
		queue<pair<int,int> >Q;
		memset(vis,0,sizeof(vis));
		if(s[n-1][m-1]!='#')
		{
			Q.push(make_pair(n-1,m-1));
			vis[n-1][m-1]=1;
		}
		while(!Q.empty())
		{
			int nx=Q.front().first,ny=Q.front().second;
			Q.pop();
			for(int i=0;i<4;i++)
				if(nx+dx[i]>=0&&nx+dx[i]<n)
					if(ny+dy[i]>=0&&ny+dy[i]<m)
						if(s[nx+dx[i]][ny+dy[i]]!='#'&&!vis[nx+dx[i]][ny+dy[i]])
						{
							Q.push(make_pair(nx+dx[i],ny+dy[i]));
							vis[nx+dx[i]][ny+dy[i]]=1;
						}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j]=='G')
					ok&=vis[i][j];
		if(ok)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}