#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int cnt[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,temp;i<n;i++)
	{
		scanf("%d",&temp);
		cnt[temp]++;
	}
	vector<vector<int> > dp(3,vector<int>(3,0));
	dp[0][0]=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		vector<vector<int> > nxt(3,vector<int>(3,0));
		for(int j=0;j<=2;j++)
		{
			for(int k=0;k<=2;k++)
			{
				for(int l=0;l<=2;l++)
				{
					int c=cnt[i]-j-k-l;
					if(c>=0)
						nxt[j][k]=max(nxt[j][k],dp[l][j]+k+c/3);
				}
			}
		}
		swap(dp,nxt);
	}
	printf("%d\n",dp[0][0]);


}