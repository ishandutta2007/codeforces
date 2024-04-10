#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=400005;
const ll inf=(ll)6e18;
int q;
ll pre[N][21];
ll w[N],sum[N][21];
ll n=1,last=0,W;

signed main()
{
	cin>>q;
	w[0]=inf;
	while(q--)
	{
		ll opt,x,y,P,Q;
		scanf("%lld%lld%lld",&opt,&P,&Q);
		x=last^P,y=last^Q;
		if(opt==1) 
		{
			n++;
			w[n]=y;
			int tmp=x;
			if(w[x]>=w[n]) pre[n][0]=x;
			else 
			{
				for(int i=19;i>=0;i--)
				{
					if(pre[tmp][i]==0) continue;
					if(w[pre[tmp][i]]<w[n]) tmp=pre[tmp][i];
				}
				pre[n][0]=pre[tmp][0];
			}
			sum[n][0]=w[pre[n][0]]; 
			for(int i=1;i<=19;i++) pre[n][i]=pre[pre[n][i-1]][i-1];
			for(int i=1;i<=19;i++) 
			{
				if(pre[n][i]==0) continue;
				sum[n][i]=sum[pre[n][i-1]][i-1]+sum[n][i-1];
			}
		}
		else
		{
			ll now=x,limit_sum=w[x],ans=1;
			if(w[x]>y)
			{
				last=0;
				puts("0");
				continue;
			}
			for(int i=19;i>=0;i--)
			{
				if(pre[now][i]==0) continue;
				if(limit_sum+sum[now][i]>y) continue;
				ans+=(1<<i);
				limit_sum+=sum[now][i];
				now=pre[now][i];
			}
			last=ans;
			printf("%lld\n",ans);
		}
	}
	return 0;
}