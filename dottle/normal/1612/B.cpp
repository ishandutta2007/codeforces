#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
	int n,a,b;cin>>n>>a>>b;
	int x=1,y=n-2;
	vector<int> ans(n),v(n+1);
	ans[0]=a,ans[n-1]=b,v[a]=v[b]=1;
	for(int i=1;i<a;i++)
		if(!v[i])
			ans[y--]=i,v[i]=1;
	for(int i=n;i>b;i--)
		if(!v[i])
			ans[x++]=i,v[i]=1;
	for(int i=1;i<=n;i++)
		if(!v[i])
			ans[x++]=i;
	int mn=n+1,mx=0;
	for(int i=0;i<n/2;i++)
		mn=min(mn,ans[i]);
	for(int i=n/2;i<n;i++)
		mx=max(mx,ans[i]);
	if(mn==a&&mx==b&&x==y+1){
		for(auto x:ans)cout<<x<<' ';
		cout<<endl;
	}else cout<<-1<<endl;
} 

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}