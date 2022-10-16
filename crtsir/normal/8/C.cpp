#include<bits/stdc++.h>
using namespace std;
int a,b,n,x[24],y[24],dp[16793216],c1[24],c2[24][24],path[16793216][2];
int main(){
	cin>>a>>b>>n;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	for(int i=0;i<(1<<n);i++)dp[i]=1000000003;
	for(int i=0;i<n;i++)c1[i]=2*fabs(x[i]-a)*fabs(x[i]-a)+2*fabs(y[i]-b)*fabs(y[i]-b);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c2[i][j]=fabs(x[i]-a)*fabs(x[i]-a)+fabs(x[i]-x[j])*fabs(x[i]-x[j])+fabs(a-x[j])*fabs(a-x[j])
					+fabs(y[i]-b)*fabs(y[i]-b)+fabs(y[i]-y[j])*fabs(y[i]-y[j])+fabs(b-y[j])*fabs(b-y[j]);
	dp[0]=0;
	for(int i=0;i<(1<<n)-1;i++)
		if(dp[i]!=-1){
			int f=0;
			while(i&(1<<f))f++;
			if(dp[i+(1<<f)]>dp[i]+c1[f])
				dp[i+(1<<f)]=dp[i]+c1[f],
				path[i+(1<<f)][0]=f,
				path[i+(1<<f)][1]=f;
			for(int k=f+1;k<n;k++)
				if((i&(1<<k))==0)
					if(dp[i+(1<<f)+(1<<k)]>=dp[i]+c2[f][k])
						dp[i+(1<<f)+(1<<k)]=dp[i]+c2[f][k],
						path[i+(1<<f)+(1<<k)][0]=k,
						path[i+(1<<f)+(1<<k)][1]=f;
		}
	cout<<dp[(1<<n)-1]<<endl<<0;
	vector<int>ans;
	for(int pos=(1<<n)-1;pos;){
		ans.push_back(-1);
		if(path[pos][0]==path[pos][1])ans.push_back(path[pos][0]),pos=pos-(1<<path[pos][1]);
		else ans.push_back(path[pos][0]),ans.push_back(path[pos][1]),pos=pos-(1<<path[pos][0])-(1<<path[pos][1]);
	}
	for(int i=ans.size()-1;i>=0;i--)cout<<' '<<ans[i]+1;
}