/*








*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r;
signed main(){
	cin>>n>>l>>r;
	int ans=0;
	for(int i=1;i<=l;i++)ans+=1ll<<i-1;for(int i=1;i<=n-l;i++)ans++;
	cout<<ans<<" ";
	ans=0;
	for(int i=1;i<=r;i++)ans+=1ll<<i-1;for(int i=1;i<=n-r;i++)ans+=1ll<<r-1;
	cout<<ans;
	return 0;
}