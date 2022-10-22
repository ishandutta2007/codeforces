/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int inv(int x){return qpow(x,mod-2);}
int n,m;
int main(){
	cin>>n>>m;
	if(n==2)return puts("0"),0;
	int ans=1;
	for(int i=1;i<=n-3;i++)(ans*=2)%=mod;
	ans=1ll*ans*(n-2)%mod;
	for(int i=1;i<=m;i++)ans=1ll*ans*i%mod;
	for(int i=1;i<=n-1;i++)ans=1ll*ans*inv(i)%mod;
	for(int i=1;i<=m-(n-1);i++)ans=1ll*ans*inv(i)%mod;
	cout<<ans;
	return 0;
}