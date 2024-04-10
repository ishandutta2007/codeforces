#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=101000;
const ll MOD=998244353;
const int MAXL = 8000100;
const ll INF = 1e18;

ll M,K;

ll dp[64][64];

ll ask(ll ind,ll cnt){
	// cnt is number left
	// ind is index
	if(ind == -1){
		if(cnt==0)return 1;
		return 0;
	}
	if(dp[ind][cnt]!=-1)return dp[ind][cnt];
	if(cnt > 0){
		dp[ind][cnt] = ask(ind-1,cnt) + ask(ind-1,cnt-1); // take zero or take 1
		if(dp[ind][cnt] > INF)dp[ind][cnt]=INF;
		return dp[ind][cnt]; 
	}else{
		return dp[ind][cnt]=ask(ind-1,cnt); // take zero
	}
}

ll query(ll m,ll k){
	ll ans=0;
	for(int i=63;i>=0;--i){
		ll t=ask(i-1,k); // taking zero
		// cerr<<"Ask "<<i<<' '<<k<<' '<<t<<' '<<m<<'\n';
		if(m <= t){
			continue;
		}else{
			m -= t;
			--k;
			ans += (1LL<<i);
		}
	}
	return ans;
}

int main(){
	cin>>M>>K;
	if(K==1){
		cout<<1;
		assert(M==1);
		return 0;
	}	
	--K;
	memset(dp,-1,sizeof(dp));
	// Find the Mth number with K bits
	// dp [len][bits] = number of things 
	// cout<<query(5,1)<<'\n';
	ll res=query(M,K);
	cout<<res+1<<'\n';

	// ll A = res+1;
	// ll cx=0;

	// for(ll t=A+1;t<=2*A;++t){
	// 	if(__builtin_popcount(t)==K+1)++cx;
	// }
	// cout<<cx<<'\n';
}