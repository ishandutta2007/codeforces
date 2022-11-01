/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int t,n,x,num[2000010],can[2000010],res[2000010];

int main()
{
	cin>>t;
	rep(tn,t)
	{
		rep(i,n+5) num[i]=can[i]=res[i]=0;
		cin>>n;
		rep(i,n)
		{
			scanf("%d",&x);
			num[x]++;
		}
		int tot=0;
		repn(i,n)
		{
			if(num[i]==0) continue;
			tot++;
			repn(j,num[i]+1) if(j-1-num[i]%j<=num[i]/j||num[i]%j==0) can[j]++,res[j]+=(num[i]+j-1)/j;
		}
		int ans=1e9;
		repn(i,n+3) if(can[i]==tot) ans=min(ans,res[i]);
		printf("%d\n",ans);
	}
	return 0;
}