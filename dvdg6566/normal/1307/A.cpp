#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 100100

ll A[MAXN],B[MAXN];
ll a,b,c,d,N,E,T,Q;
vi V;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>E;
		for (ll i=1;i<=N;++i)cin>>A[i];
		for (ll i=2;i<=N;++i){
			ll dst = i-1;
			ll cnt = A[i];
			if (dst*cnt <= E){
				E -= dst*cnt;
				A[1] += cnt;
				continue;
			}else{
				ll can_use = E/dst;
				A[1] += can_use;
				break;
			}
		}
		cout<<A[1]<<'\n';
	}
}