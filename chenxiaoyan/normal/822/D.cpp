#include<bits/stdc++.h>
using namespace std;
#define R 5000000
#define mod 1000000007
#define pb push_back
int t,l,r;
bitset<R+1> npr;
vector<int> pr;
int lpd[R+1];
void sieve(){
	for(int i=2;i<=r;i++){
		if(!npr[i])pr.pb(i),lpd[i]=i;
		for(int j=0;j<pr.size()&&pr[j]*i<=r;j++){
			npr.set(pr[j]*i);lpd[pr[j]*i]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
}
int dp[R+1];
int main(){
	scanf("%d%d%d",&t,&l,&r);
	sieve();
//	for(int i=0;i<pr.size();i++)cout<<pr[i]<<" ";puts("");
	for(int i=2;i<=r;i++)dp[i]=(1ll*i*(lpd[i]-1)/2%mod+dp[i/lpd[i]])%mod;
	int ans=0,po=1;
	for(int i=l;i<=r;i++)(ans+=1ll*dp[i]*po%mod)%=mod,po=1ll*po*t%mod;
	printf("%d",ans);
	return 0;
}