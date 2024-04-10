/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=250000;
int n,mod;
int fact[N+1];
int main(){
	cin>>n>>mod;
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=1ll*fact[i-1]*i%mod;
	int ans=0;
	for(int i=1;i<=n;i++)(ans+=1ll*(n-i+1)*(n-i+1)%mod*fact[n-i]%mod*fact[i]%mod)%=mod;
	cout<<ans;
	return 0;
}