#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
int t[5005];
ll pref[5005];
ll dp[5005][4];
int opt[5005][4];
ll daj(int l,int r)
{
	if(l>r)
		return 0;
	return pref[r]-pref[l-1];
}
int main()
{	
	cin>>n;
	for(int i=1;n>=i;i++)
	{
		cin>>t[i];
		pref[i]=pref[i-1]+t[i];
	}
	for(int i=1;n+1>=i;i++)
		{
			dp[i][0]=pref[i-1];
			opt[i][0]=0;
		}
	for(int i=1;n+1>=i;i++)
	{
		for(int g=1;4>g;g++)
			{
				dp[i][g]=-1e15;
				for(int j=1;i+1>j;j++)
					{
						ll c=daj(j,i-1);
						if(g%2==1)
							c*=-1;
						if(dp[j][g-1]+c>dp[i][g])
						{
							opt[i][g]=j;
							dp[i][g]=dp[j][g-1]+c;
						}
					}
			}
	}
	int xx=n+1,yy=3;
	vector < int > ans;
	for(int i=1;4>=i;i++)
	{
		ans.push_back(opt[xx][yy]);
		xx=opt[xx][yy];
		yy--;
	}
	for(int i=2;i>=0;i--)
		cout<<ans[i]-1<<" ";
    return 0;	
}