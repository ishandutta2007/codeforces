#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;
unordered_map<int , int> mp;
int lca(int v, int u, int w = 0){
	if(u == v)
		return 0;
	if(u<v)
		swap(u,v);
	mp[u]+=w;
	return lca(v,u/2,w) + mp[u];
}
int32_t main(){
	int q;
	cin>>q;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int v,u,w;
			cin>>v>>u>>w;
			lca(v,u,w);
		}
		else{
			int v, u;
			cin>>v>>u;
			cout<<lca(u,v)<<endl;
		}
	}
}