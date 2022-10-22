#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll dp0[N][N];//cur mx
ll dp1[N][N];
ll s[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m;
	dp0[1][1]=2;
	for(i=2;i<=n;i++){
		for(j=1;j<=i;j++){
			if(j==1){
				for(k=1;k<=i-1;k++)
					for(int p=1;p<=k;p++){
						dp1[1][k]+=dp0[p][k];
						dp1[1][k]%=mod;
					}
						
			}
			else{
				for(k=j;k<=i;k++){
					if(k==j) dp1[j][k]+=dp0[j-1][k-1]+dp0[j-1][k];
					else dp1[j][k]+=dp0[j-1][k];
					dp1[j][k]%=mod;
				}
			}
		}
		memcpy(dp0,dp1,sizeof(dp0));
		memset(dp1,0,sizeof(dp1));
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			s[i]+=dp0[j][i];
			s[i]%=mod;
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i*j<m)
				ans=(ans+s[i]*s[j])%mod;
		}
	}
	cout<<(ans*499122177)%mod;;
	return 0;
}