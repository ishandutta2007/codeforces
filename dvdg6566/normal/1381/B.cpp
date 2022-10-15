#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=4010;
const ll MAXK=20;
const ll INF = 1e13;
const ll MOD = 1e9+7;

ll N,a,b,c,d,e,M,K,T;
ll A[MAXN];
bitset<MAXN> bs;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		bs.reset();
		bs[0]=1;
		cin>>N;N*=2;
		for(int i=1;i<=N;++i)cin>>A[i];
		vi szes;
		int cur=1;
		while(cur<=N){
			int r=cur;
			while(r+1<=N){
				if(A[r+1]<A[cur])++r;
				else break;
			}
			szes.pb(r-cur+1);
			// cerr<<cur<<' '<<r<<'\n';
			cur=r+1;
		}
		for(auto i:szes)bs=bs|(bs<<i);
		if(bs[N/2])cout<<"YES\n";
		else cout<<"NO\n";
		// cout<<bs[N/2]<<'\n';
	}
}