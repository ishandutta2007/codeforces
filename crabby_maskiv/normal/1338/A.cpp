#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
ll a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		ll t=0,mx=-1e18;
		for(i=1;i<=n;i++){
			mx=max(mx,a[i]);
			t=max(t,mx-a[i]);
		}
		while(t){
			t>>=1;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}