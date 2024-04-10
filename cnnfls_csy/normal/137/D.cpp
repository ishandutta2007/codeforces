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
int n,m,i,j,k,dp[505][505],cst[505][505],pre[505][505],ans;
vector<int> pos;
string st,st1,st2;
void get(int x,int y)
{
	if (x) get(pre[x][y],y-1);
	pos.push_back(x+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>st>>n;
	st=" "+st;
	for (i=1;i<st.length();i++)
	{
		for (j=i;j<st.length();j++)
		{
			st1=st.substr(i,j-i+1);
			st2=st1;
			reverse(st2.begin(),st2.end());
			for (k=0;k<st1.length();k++)
			{
				if (st1[k]!=st2[k])
				{
					cst[i][j]++;
				}
			}
			cst[i][j]/=2;
		}
	}
	memset(dp,22,sizeof(dp));
	dp[0][0]=0;
	for (i=1;i<st.length();i++)
	{
		for (j=1;j<=n;j++)
		{
			for (k=0;k<i;k++)
			{
				if (dp[k][j-1]+cst[k+1][i]<dp[i][j])
				{
					dp[i][j]=dp[k][j-1]+cst[k+1][i];
					pre[i][j]=k;
				}
			}
		}
	}
	ans=1;
	for (i=2;i<=n;i++)
	{
		if (dp[st.length()-1][i]<dp[st.length()-1][ans]) ans=i;
	}
	cout<<dp[st.length()-1][ans]<<endl;
	get(st.length()-1,ans);
	for (i=1;i<pos.size();i++)
	{
		st1=st.substr(pos[i-1],pos[i]-pos[i-1]);
		for (j=0;j<st1.length()&&j<st1.length()-j-1;j++) st1[j]=st1[st1.length()-j-1];
		if (i>1) cout<<'+';
		cout<<st1;
	}
	return 0;
}