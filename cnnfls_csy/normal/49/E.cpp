#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,dp2[55][55][26],dp3[55][55][26],dp[55][55];
string st,st2,st3;
char x,y,z;
vector<pair<char,char>/**/> bi[26];
int dfs3(int x,int y,char c)
{
	if (x==y&&st2[x]==c) return 1;
	if (dp3[x][y][c-'a']!=-1) return dp3[x][y][c-'a'];
	dp3[x][y][c-'a']=0;
	int i,j;
	for (j=0;j<bi[c-'a'].size();j++)
	{
		for (i=x;i<y;i++)
		{
			if (dfs3(x,i,bi[c-'a'][j].first)&&dfs3(i+1,y,bi[c-'a'][j].second))
			{
				return dp3[x][y][c-'a']=1;
			}
		}
	}
	return dp3[x][y][c-'a']=0;
}
int dfs2(int x,int y,char c)
{
	if (x==y&&st[x]==c) return 1;
	if (dp2[x][y][c-'a']!=-1) return dp2[x][y][c-'a'];
	dp2[x][y][c-'a']=0;
	int i,j;
	for (j=0;j<bi[c-'a'].size();j++)
	{
		for (i=x;i<y;i++)
		{
			if (dfs2(x,i,bi[c-'a'][j].first)&&dfs2(i+1,y,bi[c-'a'][j].second))
			{
				return dp2[x][y][c-'a']=1;
			}
		}
	}
	return dp2[x][y][c-'a']=0;
}
int dfs(int x,int y)
{
	if (x<0&&y<0) return 0;
	if (x<0||y<0) return 1<<25;
	if (dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=1<<25;
	int i,j;
	char k;
	for (i=0;i<=x;i++)
	{
		for (j=0;j<=y;j++)
		{
			for (k='a';k<='z';k++)
			{
				if (dfs2(i,x,k)&&dfs3(j,y,k))
				{
					dp[x][y]=min(dp[x][y],dfs(i-1,j-1)+1);
				}
			}
		}
	}
	return dp[x][y];
}
int main()
{
	cin>>st>>st2>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st3;
		bi[st3[0]-'a'].push_back(make_pair(st3[3],st3[4]));
		//bi[x].push_back(make_pair(y,z));
		//cerr<<x<<' '<<y<<' '<<z<<endl;;
		//cerr<<(st3[0]-'a')<<' '<<st3[3]<<' '<<st3[4]<<endl;
	}
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	memset(dp3,-1,sizeof(dp3));
	int ans=dfs(st.size()-1,st2.size()-1);
	if (ans>st.size()+st2.size()) cout<<-1; else cout<<ans;
	return 0;
}