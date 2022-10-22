/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=200000;
int n,m;
int a[N+1];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=n;i>=n-m+1;i--)ans+=i;
	cout<<ans<<" ";
	vector<int> pos;
	for(int i=1;i<=n;i++)if(n-m+1<=a[i])pos.push_back(i);
	ans=1;
	for(int i=0;i+1<pos.size();i++)ans=1ll*ans*(pos[i+1]-pos[i])%mod;
	cout<<ans;
	return 0;
}