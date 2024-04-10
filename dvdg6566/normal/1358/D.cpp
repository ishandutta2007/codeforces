#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 400100;
const ll MAXB = 128;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll a,b,c,d,e,f,g,sum,N,M,E,K;
ll A[MAXN];
ll B[MAXN];
ll c2(ll x){return x*(x+1)/2;}
ll ans=0;
ll C[MAXN];

int main(){
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		cin>>A[i];
		A[i+N]=A[i];
		if(A[i]>=K){
			ll offset=A[i]-K;
			ll rep=K;
			ans=max(ans,c2(rep)+offset*K);
		}
	}
	for(int i=1;i<=2*N;++i){
		B[i]=B[i-1]+A[i];
		C[i]=c2(A[i])+C[i-1];
	}
	ll totdays=B[N];
	ll l=1;

	for(int i=N+1;i<=2*N;++i){
		totdays+=A[i];
		while(totdays>K){
			totdays-=A[l];
			++l;
		}
		if(l>i)continue;
		ll leftovers=K-(B[i]-B[l-1]);
		assert(leftovers>=0);
		assert(leftovers<A[l-1]);
		ll st=C[i]-C[l-1];
		ll offset=A[l-1]-leftovers;
		st+=c2(leftovers)+offset*leftovers;
		ans=max(ans,st);
	}
	cout<<ans;

}