#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

map<int,int> a;
int n,x[N],s,ans;

void solve(){
	ans=0;
	s=0;
	a.clear();
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i],x[i]*=n,s+=x[i]/n,a[x[i]]++;

	for(int i=1;i<=n;i++){
		if(x[i]==s)ans+=a[x[i]]-1;
		else ans+=a[s*2-x[i]];
	}
	cout<<ans/2<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}