#include<bits/stdc++.h>
using namespace std;
char c[12][12][12];
bool vis[12][12][12];
int k,n,m,beginn,beginm,dx[6]={0,0,0,0,1,-1},dy[6]={0,0,1,-1,0,0},dz[6]={1,-1,0,0,0,0};
int dfs(int k1,int n1,int m1)
{
	int ans=1;
	vis[k1][n1][m1]=true;
	for(int i=0;i<6;i++)
	{
		int kk=k1+dx[i],nn=n1+dy[i],mm=m1+dz[i];
		if(!vis[kk][nn][mm]&&c[kk][nn][mm]=='.')
			ans+=dfs(kk,nn,mm);
	}
	return ans;
}
int main()
{
	memset(c,'#',sizeof(c));
	cin>>k>>m>>n;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=m;j++)
			for(int ij=1;ij<=n;ij++)
				cin>>c[i][j][ij];
	cin>>beginn>>beginm;
	if(c[1][beginn][beginm]=='.')
		cout<<dfs(1,beginn,beginm);
	else
		cout<<0;
}