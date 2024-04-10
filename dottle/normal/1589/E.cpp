#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define TREE tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 
#define grk order_of_key
#define int long long
const int N=1005000;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	TREE q;
	for(auto&x:a)cin>>x;
	int ns=0,ans=0;
	for(int i=0;i<n;i++){
		if(!a[i])ans++;
		if(!(i&1)){
			while(!q.empty()&&ns+floor(1.**q.rbegin()/N)>a[i])q.erase(*q.rbegin());
			ans+=q.grk((a[i]-ns+1)*N)-q.grk((a[i]-ns)*N);
			ns=a[i]-ns;
			q.insert((ns-a[i])*N+i+1);
		}else{
			while(!q.empty()&&ns-floor(1.**q.begin()/N)>a[i])q.erase(*q.begin());
			ans+=q.grk((ns-a[i]+1)*N)-q.grk((ns-a[i])*N);
			ns=a[i]-ns;
			q.insert((a[i]-ns)*N+i+1);
		}
	}
	cout<<ans<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;while(t--)solve();
}