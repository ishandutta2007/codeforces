#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define fbo               find_by_order
#define ook               order_of_key

template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

vc<int> v[200005],ans,ans2;int vis[200005];
void dfs(int z,int i){
	vis[z]=1;
	if(i){
		ans.pb(z);
	}
	else{
		ans2.pb(z);
	}
	for(int x:v[z]){
		if(vis[x])continue;
		dfs(x,!i);
	}
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    dfs(1,1);
    if(ans.size()<=n/2){
    	cout<<ans.size()<<"\n";
    	for(int x:ans)cout<<x<<" ";
    }
	else{
    	cout<<ans2.size()<<"\n";
    	for(int x:ans2)cout<<x<<" ";
    }
	cout<<"\n";
	
	ans.clear();ans2.clear();
	for(int i=1;i<=n;i++){v[i].clear();vis[i]=0;}
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}