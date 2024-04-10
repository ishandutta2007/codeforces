#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=110,mod=998244353;
int i,j,k,h,n,m,l[maxn],r[maxn],S[maxn],cnt=1;
ll dp[maxn][maxn];
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
ll C(int a,int b){
	if(b>a || b<0)return 0;
	ll ans=1,in=1;
	for(int i=1;i<=b;i++)ans=ans*(a-i+1)%mod,in=in*i%mod;
	return ans*ksm(in,mod-2)%mod;
}
ll all=1;
ll get(int a,int b){
	return C(a+b-1,b);
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]),S[2*i-1]=l[i],S[2*i]=r[i]+1,all=all*(r[i]-l[i]+1)%mod;
	for(i=1;i<=n/2;i++)swap(l[i],l[n-i+1]),swap(r[i],r[n-i+1]);
	sort(S+1,S+1+2*n);for(i=2;i<=2*n;i++)if(S[i]!=S[cnt])S[++cnt]=S[i];
	for(i=1;i<=n;i++)l[i]=lower_bound(S+1,S+1+cnt,l[i])-S;
	for(i=1;i<=n;i++)r[i]=lower_bound(S+1,S+1+cnt,r[i]+1)-S;
	dp[0][0]=1;
	ll ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<cnt;j++){
			for(k=i-1;k>=0;k--){
				if(l[k+1]<=j&&j+1<=r[k+1]);else break;
				for(h=0;h<j;h++){
					dp[i][j]+=dp[k][h]*get(S[j+1]-S[j],i-k)%mod;
					dp[i][j]%=mod;
				}
			}
			if(i==n)ans+=dp[i][j];
		}
	}cout<<ans%mod*ksm(all,mod-2)%mod<<endl;
	return 0;
}