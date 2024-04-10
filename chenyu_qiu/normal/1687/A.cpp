#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
int T,n,k,a[200005],s[200005];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	if(k>=n) cout<<s[n]+(k*2-n-1)*n/2<<endl;
	else{
		int ans=0;
		for(int i=1;i<=n-k+1;i++){
			int j=i+k-1;
			ans=max(ans,s[j]-s[i-1]);
		}
		cout<<ans+(k-1)*k/2<<endl;
	}
}
signed main(){	
	IOS;TIE;
	cin>>T;
	while(T--) solve();
	return 0;
}