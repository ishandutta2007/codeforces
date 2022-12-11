#include<bits/stdc++.h>
using namespace std;
#define db long double
db v;
db dfs(db a,db b,db c){
	if(b<0)swap(a,b);
	if(a<0&&b<0)return 1;
	if(a<0)return 1+b*(b<v+1e-8?1:dfs(-1,b-v,c+v));
	return 1+b*(b<v+1e-8?dfs(a+b/2,-1,c+b/2):dfs(a+v/2,b-v,c+v/2))+a*(a<v+1e-8?dfs(-1,b+a/2,c+a/2):dfs(a-v,b+v/2,c+v/2));
}
int main(){
	int t;cin>>t;while(t--){
		db a,b,c; cin>>a>>b>>c>>v;
		cout<<setprecision(12)<<dfs(a,b,c)<<endl;
	}
}