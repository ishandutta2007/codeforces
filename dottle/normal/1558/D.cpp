#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define TREE tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define int long long
const int N=500500,mod=998244353;
using namespace std;

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

TREE t;

int kth(int k){
	int l=0,r=t.size()-1,ans=r+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(*t.find_by_order(mid)-mid>=k)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return k+ans-1;
}

void solve(){
	int n,m;cin>>n>>m;vector<pair<int,int>>a(m);map<int,int> tg;int ans=0;
	t.clear();
	for(auto&x:a)cin>>x.first>>x.second;
	reverse(a.begin(),a.end());
	t.insert(0);
	for(auto x:a){
		int p=kth(x.second+1),q=kth(x.second);
		ans+=!tg[p],tg[p]=1,t.insert(q);
	}
	cout<<C(2*n-1-ans,n)<<endl;
}

main(){
	ios::sync_with_stdio(false);
	init();
	int _T=1;cin>>_T;
	while(_T--)solve();
}