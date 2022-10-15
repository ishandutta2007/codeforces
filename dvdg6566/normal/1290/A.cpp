#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define lb lower_bound
#define up upper_bound

ll MOD = 1e9+7;
#define MAXN 5010

ll N,a,b,c,d,e,f,T,M,K;
ll A[MAXN];
vi V;
vi cur;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while (T--){
		cin>>N>>M>>K;
		--M;
		K = min(K,M);
		M = M - K;
		
		V.clear();
		for (int i=1;i<=N;++i){
			cin>>A[i];
		}
		ll ans = 0;
		for (int l=1;l<=K+1;++l){
			int r = N - (K - l) - 1;
			// cout<<"Choose "<<l<<' '<<r<<'\n';
			ll best = MOD;
			for (int k=0;k<=M;++k){
				int left_open = l+k;
				int right_open = r-(M-k);
				// cout<<left_open<<' '<<right_open<<'\n';
				best = min(best, max(A[left_open], A[right_open]));
			}
			ans = max(ans, best);
		}
		cout<<ans<<'\n';
	}
}