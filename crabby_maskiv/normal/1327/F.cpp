#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll mod=998244353;
int n,m,k;
int l[N],r[N],x[N];
int c[N],dp[N];
int lmx[N];
ll solve(int f){
	memset(c,0,sizeof(c));
	memset(dp,0,sizeof(dp));
	memset(lmx,0,sizeof(lmx));
	dp[0]=1;
	int i,j;
	for(i=1;i<=m;i++){
		if(x[i]&(1<<f)){
			c[l[i]]++;
			c[r[i]+1]--;
		}
		else lmx[r[i]]=max(lmx[r[i]],l[i]);
	}
	for(i=1;i<=n;i++) c[i]+=c[i-1];
	j=0;
	int sum=0;
	for(i=1;i<=n;i++){
		if(!c[i-1]) sum=(sum+dp[i-1])%mod;
		while(j<lmx[i-1]){
			if(!c[j]) sum=(sum-dp[j]+mod)%mod;
			j++;
		}
		dp[i]=sum;
	}
	return dp[n];
}
int main(){
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	n++;
	for(i=1;i<=m;i++)
		scanf("%d%d%lld",&l[i],&r[i],&x[i]);
	int ans=1;
	for(i=0;i<k;i++) 
		ans=ans*solve(i)%mod;
	cout<<ans;
	return 0;
}