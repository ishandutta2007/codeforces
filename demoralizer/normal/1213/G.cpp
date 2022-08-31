#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define chrng(n,a,b)      (((n)>=(a))&&((n)<=(b)))
#define clamp(n,a,b)      (((n)<(a))?(a):((((n)>(b))?(b):(n)))

int parent[200005];
int size[200005];
int fans;
int findParent(int i)
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i]);
    return parent[i];
}
void unionNodes(int a,int b)
//to merge the connected components of nodes a and b
{
    int parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    fans+=size[parent_a]*size[parent_b];
    if(size[parent_a]>=size[parent_b])//the larger connected component eats up the smaller one
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}
vector<pair<int, pii>> g;
int ans[200005];
int q[200005];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.pb({w,{u,v}});
	}
	sort(all(g));
	for(int i=0;i<m;i++){
		cin>>q[i];
	}
	for(int i=1;i<=200002;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    
    for(auto x:g){
    	unionNodes(x.sc.fr,x.sc.sc);
    	ans[x.fr]=fans;
    }
    rep(i,2,200001){
    	if(ans[i]==0)ans[i]=ans[i-1];
    }
    for(int i=0;i<m;i++){
    	cout<<ans[q[i]]<<" ";
    }
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}