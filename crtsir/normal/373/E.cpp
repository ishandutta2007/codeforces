#include<bits/stdc++.h>
using namespace std;
long long dp[150003],dp2[150003],n,m,d,deq[150003],a[303],b[303],t[303],cnt,ans=-123456789101112;
int main(){
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i]>>t[i],
		cnt+=b[i];
	for(int i=m-1;i>0;i--)
		t[i]=t[i]-t[i-1];
	for(int i=1;i<=n;i++)
		dp2[i]=fabs(a[0]-i);
	for(int i=1;i<m;i++)
		if(t[i]*d<n-1)
		{
			long long pl=0,pr=0;
			for(int j=1;j<=t[i]*d;j++){
				while(pl!=pr)
					if(dp2[j]<=dp2[deq[pr-1]])
						pr--;
					else
						break;
				deq[pr++]=j;
			}
			for(int j=1+t[i]*d;j<=n;j++){ 
				while(pl!=pr)
					if(dp2[j]<=dp2[deq[pr-1]])
						pr--;
					else
						break;
				deq[pr++]=j;
				dp[j-t[i]*d]=dp2[deq[pl]]+fabs(a[i]-(j-t[i]*d));
				if(deq[pl]<j-t[i]*d*2+1)pl++;
			}
			for(int j=n-t[i]*d+1;j<=n;j++){
				dp[j]=dp2[deq[pl]]+fabs(a[i]-j);
				if(deq[pl]<j-t[i]*d+1)pl++;
			}
			for(int j=1;j<=n;j++)dp2[j]=dp[j];
		}else{
			long long minn=123456789101112;
			for(int j=1;j<=n;j++)minn=min(dp2[j],minn);
			for(int j=1;j<=n;j++)dp[j]=minn+fabs(a[i]-j),dp2[j]=dp[j];
		}
	for(int i=1;i<=n;i++)ans=max(-dp[i]+cnt,ans);
	cout<<ans;
}