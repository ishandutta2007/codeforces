#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int a[N],n,m,x,y,s;

main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	sort(a+1,a+1+n);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		int ans=5e18;
		int p=lower_bound(a+1,a+1+n,x)-a;
		if(p<=n)
			ans=min(ans,max(y+a[p]-s,0ll));
		if(p>1)
			ans=min(ans,(x-a[p-1])+max(y+a[p-1]-s,0ll));
		cout<<ans<<endl;
	} 
}