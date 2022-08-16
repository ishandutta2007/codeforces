#include <bits/stdc++.h>
using namespace std;
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

pii v[1005];int u[1005];int vis[1005];
vc<pair<int,pii> > ans;
pii dfs(int z){
	vis[z]=1;
	if(v[z].fr==0){
		return {z,M};
	}
	pii t=dfs(v[z].fr);
	return {t.fr,min(t.sc,v[z].sc)};
}
int goup(int z){
	if(vis[z])return -1;
	vis[z]=1;
	if(u[z])
	return goup(u[z]);
	return z;
}
void solve(){
    int n,p;
    cin>>n>>p;
    for (int i = 0; i < p; ++i)
    {
    	int a,b,d;
    	cin>>a>>b>>d;
    	v[a]={b,d};
    	u[b]=a;
    }
    for(int i=1;i<=n;i++){
    	if(vis[i])continue;
    	int k=goup(i);
    	if(k==-1)continue;
    	pii q=dfs(k);
    	if(q.sc!=M)
    	ans.pb({k,q});
    }
    cout<<ans.size()<<"\n";sort(all(ans));
    for(auto x:ans){
    	cout<<x.fr<<" "<<x.sc.fr<<" "<<x.sc.sc<<"\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}