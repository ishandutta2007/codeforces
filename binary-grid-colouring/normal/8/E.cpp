#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[55][55][2][2];
bool vis[55][55][2][2];
int a[55];
ll n,k;
ll ans;
ll dfs(int l,int r,int rev,int inv)
{
	if(l>r)return 1;
	if(vis[l][r][rev][inv]==true)return dp[l][r][rev][inv];
	vis[l][r][rev][inv]=true;
	ll &ans=dp[l][r][rev][inv];
	ans = 0;
	for(int i=0;i<2;i++){
		if(a[l]==-1||a[l]==i)
		{
			for(int j=0;j<2;j++)
			{
				if(a[r]==-1||a[r]==j)
				{
					if(l<r||i==j)
					{
						if(rev||i<=j)
						{
							if(inv||i<=1-j)
							{
								ans+=dfs(l+1,r-1,rev||i<j,inv||i<1-j);
							}
						}
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	memset(a,-1,sizeof(a));
    a[0]=0;
    k++;
	if(dfs(0,n-1,0,0)<k){
		return 0*puts("-1");
	}

    for(int i=1;i<n;i++)
    {
    	a[i]=0;
    	memset(vis,0,sizeof(vis));
    	ll cur=dfs(0,n-1,0,0);
    	if(cur<k)
    	{
    		k-=cur;
    		a[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}