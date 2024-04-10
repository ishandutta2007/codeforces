#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;
int n,q;

struct BIT{
    int a[N];
    BIT(){memset(a,0x7f,sizeof(a));}
    void add(int k,int p){k=n-k+1;while(k<=n)a[k]=min(a[k],p),k+=k&-k;}
    int sum(int k){int ans=4.1e18;k=n-k+1;while(k)ans=min(ans,a[k]),k-=k&-k;return ans;}
}T;

int x[N],w[N];
int st[N],t;
vector<pair<int,int>> a[N];
int ans[N];

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>x[i]>>w[i];
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		a[y].push_back({x,i});
	}
	for(int i=1;i<=n;i++){
		while(t&&w[i]<=w[st[t]]){
			T.add(st[t],(x[i]-x[st[t]])*(w[i]+w[st[t]]));
			--t;
		}
		if(t)T.add(st[t],(x[i]-x[st[t]])*(w[i]+w[st[t]]));
		st[++t]=i;
		for(auto x:a[i])
			ans[x.second]=T.sum(x.first);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
}

main(){
	solve();
}