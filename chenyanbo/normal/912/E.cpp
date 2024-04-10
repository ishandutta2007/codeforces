#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
int p[20];
#define MAXN 1000007
vector<int> a,b;
vector<ll> A,B;
const ll U=1e18;
void dfs(vector<int> &v,vector<ll> &V,ll val,int i){
	if(i==v.size()){
	    V.push_back(val);
		return;
	}
	dfs(v,V,val,i+1);
	if(val<=U/v[i]) dfs(v,V,val*v[i],i);
}
ll cal(ll val){
	ll sum=0,s;  //=sum
	int uuu=A.size();
    for(int i=0; i<uuu; ++i){
    	s=A[i];
		if(s>val) break;
		sum+=upper_bound(all(B),val/s)-B.begin();
	}
	return sum;
}
int main(){
    int n;scanf("%d",&n);     //neiwaifenhe
	int i;for(i=1;i<=n;i++) scanf("%d",p+i);
	ll k;scanf("%I64d",&k);
    for(i=1;i<=n;i++){
		if(i&1) a.push_back(p[i]);
		else b.push_back(p[i]);
	}
	dfs(a,A,1,0);
	dfs(b,B,1,0);
	sort(all(A));
	sort(all(B));
	ll l=0,r=1e18,mid;
	while(l<r){
		mid=l+r>>1;
        if(cal(mid)>=k) r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
}