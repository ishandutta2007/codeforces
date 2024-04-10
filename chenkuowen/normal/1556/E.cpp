#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e5;
template<class Func> struct ST{
	Func func;
	ll st[23][N];
	int lg[N];
	ll& operator[](int x){ return st[0][x]; }
	ll merge(ll x,ll y){ return func(x,y)?x:y; }
	void build(int n){
		lg[1]=0; for(int i=2;i<=n+1;++i) lg[i]=lg[i>>1]+1;
		for(int l=1;l<=lg[n];++l)
			for(int i=1;i+(1<<l)-1<=n;++i)
				st[l][i]=merge(st[l-1][i],st[l-1][i+(1<<l-1)]);
	}
	ll query(int x,int y){
		int l=lg[y-x+1];
		return merge(st[l][x],st[l][y-(1<<l)+1]);
	}
};
ST<greater<ll> > mxst;
ST<less<ll> > mist;
ll a[N];
int main(){
	int n,q; scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i){
		ll x; scanf("%lld",&x);
		a[i]=x-a[i];
	}
	for(int i=1;i<=n;++i) a[i]+=a[i-1];
	for(int i=1;i<=n;++i) mxst[i]=mist[i]=a[i];
	mxst.build(n);
	mist.build(n);
	while(q--){
		int l,r; scanf("%d%d",&l,&r);
		if(a[r]-a[l-1]!=0) puts("-1");
		else{
			if(mist.query(l,r)-a[l-1]<0) puts("-1");
			else printf("%lld\n",mxst.query(l,r)-a[l-1]);
		}
	}
	return 0;
}