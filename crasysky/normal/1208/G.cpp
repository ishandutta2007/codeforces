#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<double,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=2e6+6; int phi[N];
int main(){
	int n,k; cin>>n>>k;
	if (k==1){ cout<<3<<endl; return 0; }
	rep(i,1,n){
		phi[i]+=i; rep(j,2,n/i) phi[i*j]-=phi[i];
	}
	sort(phi+3,phi+1+n);
	ll ans=0; rep(i,1,k+2) ans+=phi[i];
	cout<<ans<<endl;
	return 0;
}