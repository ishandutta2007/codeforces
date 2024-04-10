#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define TREE tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define rk order_of_key
#define vc vector
//#define int long long
//const int N=
using namespace std;

vc<vc<int>>p;
map<pair<int,int>,int>v;

int main(){
	ios::sync_with_stdio(false);
	int n,m,x,y;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x>>y,p.push_back({x,y,-1}),v[{x,y}]=1; 
	for(int i=1;i<=m;i++)cin>>x>>y,p.push_back({x,y,i});
	sort(p.begin(),p.end());
	TREE t;int s=0,h=-1;vc<int>ans(m+1);
	for(auto x:p){
		if(x[2]==-1){
			int y=t.rk(x[1]+1),d=s-y,dl=x[0]-x[1];
			if(dl<d)t.insert(x[1]);
			else if(dl>d&&h!=x[0])h=x[0],++s;
		}else{
			if(v[{x[0],x[1]}])ans[x[2]]=1;
			else if(x[0]!=h)
				if((t.lower_bound(x[1])==t.end()||*t.lower_bound(x[1])!=x[1])&&x[1]+s-t.rk(x[1]+1)==x[0])
					ans[x[2]]=1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"LOSE":"WIN")<<endl;
}