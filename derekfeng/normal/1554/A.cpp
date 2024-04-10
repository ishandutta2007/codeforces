#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
int a[100004];
void solve(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans=0;
	for(int i=1;i<n;i++)ans=max(ans,(ll)a[i-1]*a[i]);
	cout<<ans<<"\n";
}
int main(){
	for(cin>>T;T--;)solve();
}