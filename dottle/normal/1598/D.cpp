#include<bits/stdc++.h>
#define int long long
const int N=500005;
using namespace std;

map<int,int> a,b,c[N];
int x[N],y[N],n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i],a[x[i]]++,b[y[i]]++;
	int ans=n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++){
		int X=a[x[i]],Y=b[y[i]];
		ans-=(X-1)*(Y-1);
	}
	for(int i=1;i<=n;i++)
		a[x[i]]=b[y[i]]=0;
	cout<<ans<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}