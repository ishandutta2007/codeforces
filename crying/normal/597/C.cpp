#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lowbit(x) (x&-x)
#define next Cry_For_theMoon
typedef long long ll;
typedef double db;
const ll MAXN=1e5+10;
int n,k;
ll p[MAXN],v[MAXN],ans;
struct FenwickTree{
	ll tree[MAXN];
	void add(ll x,ll k){
		for(;x<=n;x+=lowbit(x))tree[x]+=k;
	}
	ll query(ll x){
		ll sum=0;
		for(;x;x-=lowbit(x))sum+=tree[x];
		return sum;
	}
	void clear(){memset(tree,0,sizeof tree);}
}tree;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%lld",&p[i]);
		v[i]=1;
	}
	rep(i,1,k){
		tree.clear();
		rep(j,1,n){
			ll tmp=tree.query(p[j]-1);
			tree.add(p[j],v[j]);
			v[j]=tmp;
		}	
	} 
	rep(i,1,n)ans+=v[i];
	printf("%lld",ans);
	return 0;
}