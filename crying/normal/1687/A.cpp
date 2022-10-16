#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
ll T,n,k,a[MAXN],ans;
ll sum[MAXN];
ll S(ll x){
	return x*(x-1)/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i,1,n){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		if(k>=n){
			cout<<sum[n]+n*(2*k-1-n)/2<<'\n';
			continue;
		}
		ll ans=0;
		rep(i,k,n)ans=max(ans,sum[i]-sum[i-k]);
		cout<<ans+S(k)<<'\n';
	}

	return 0;
}