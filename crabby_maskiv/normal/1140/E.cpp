#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n1,n2,n,m;
ll dp1[N],dp2[N];//same diff
ll a1[N],a2[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		int x;cin>>x;
		if(i&1) a1[++n1]=x;
		else a2[++n2]=x;
	}
	dp1[1]=0;dp2[1]=1;
	for(i=2;i<=n;i++){
		dp1[i]=dp1[i/2]*dp1[(i+1)/2]+(m-1)*(dp2[i/2]*dp2[(i+1)/2]%mod);
		dp2[i]=dp1[i/2]*dp2[(i+1)/2]+dp2[i/2]*dp1[(i+1)/2]+(m-2)*(dp2[i/2]*dp2[(i+1)/2]%mod);
		dp1[i]%=mod;dp2[i]%=mod;
	}
	ll ans1=1,ans2=1;
	int pos=0;
	for(i=1;i<=n1+1;i++){
		if(a1[i]>-1){
			if(a1[i]==0&&a1[pos]==0){
				ans1*=m;ans1%=mod;
				for(j=1;j<n1;j++) ans1=(ans1*(m-1))%mod;
				break;
			}
			else if(a1[i]==0||a1[pos]==0){
				for(j=1;j<i-pos;j++) ans1=(ans1*(m-1))%mod;
				pos=i;
				continue;
			}
			ans1*=(a1[i]==a1[pos])?dp1[i-pos]:dp2[i-pos];
			ans1%=mod;
			pos=i;
		}
	}
	pos=0;
	for(i=1;i<=n2+1;i++){
		if(a2[i]>-1){
			if(a2[i]==0&&a2[pos]==0){
				ans2*=m;ans2%=mod;
				for(j=1;j<n2;j++) ans2=(ans2*(m-1))%mod;
				break;
			}
			else if(a2[i]==0||a2[pos]==0){
				for(j=1;j<i-pos;j++) ans2=(ans2*(m-1))%mod;
				pos=i;
				continue;
			}
			ans2*=(a2[i]==a2[pos])?dp1[i-pos]:dp2[i-pos];
			ans2%=mod;
			pos=i;
		}
	}
	cout<<ans1*ans2%mod;
	return 0;
}