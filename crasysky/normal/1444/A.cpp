#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6;
ll pr[N],a[N];
ll check(ll p,ll pr,ll c){
	while (p%pr==0) p/=pr;
	rep(i,1,c) p*=pr;
	return p;
}
int main(){
	int T; cin>>T;
	while (T--){
		ll p,q; cin>>p>>q;
		if (p%q){ cout<<p<<endl; continue; }
		int pc=0;
		for (ll i=2;i*i<=q;++i)
			if (q%i==0){
				pr[++pc]=i,a[pc]=0; while (q%i==0) q/=i,++a[pc];
			}
		if (q!=1) pr[++pc]=q,a[pc]=1;
		ll ans=0;
		rep(i,1,pc) ans=max(ans,check(p,pr[i],a[i]-1));
		cout<<ans<<endl;
	}
}