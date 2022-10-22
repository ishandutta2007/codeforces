#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Tc,n,K;
int a[100004];
void solve(){
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=-1e18;
	for(int i=n,j=0;i>0&&j<=K*2;i--,j++)
		for(int k=n,l=0;k>0&&l<=K*2;k--,l++)if(i!=k)ans=max(ans,(ll)i*k-(ll)K*(a[i]|a[k]));
	cout<<ans<<"\n";
}
int main(){
	for(cin>>Tc;Tc--;)solve();
}