#include<bits/stdc++.h>
using namespace std;
const int Maxn=10000002,M=1e9+7;
typedef long long Int;
int miu[Maxn],cnt[Maxn];
int n;
int xp[500020];
int main()
{
	xp[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)xp[i]=(xp[i-1]+xp[i-1])%M;
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		cnt[x]++;
	}
	int ans=0;
	miu[1]=1;
	for(int i=1;i<Maxn;i++)
	{
		for(int j=i+i;j<Maxn;j+=i)
		{
			miu[j]-=miu[i];
			cnt[i]+=cnt[j];
		}
		if(!cnt[i]||!miu[i])continue;
		ans+=miu[i]*(xp[cnt[i]]-1)*(Int)(cnt[i]-n)%M;
		if(ans>=M)ans-=M;
		if(ans<0)ans+=M;
	}	
	printf("%d\n",ans);
}