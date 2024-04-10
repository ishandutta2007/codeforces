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
#define ub upper_bound
const ll MAXN=201000;
const int INF=1e9;
// segment tree over prefix ranges
vi fact[MAXN];
vi tmp;
int ans;

void check(){
	ans=min(ans,SZ(tmp));
	// for(auto i:tmp)cerr<<i<<' ';cerr<<'\n';
	for(auto i:fact[SZ(tmp)]){
		// cerr<<"C "<<i<<'\n';
		for(int j=0;j<i;++j){
			bool ok=1;
			int col=tmp[j];
			for(int k=j+i;k<SZ(tmp);k+=i)if(tmp[k]!=col)ok=0;
			if(ok)ans=min(ans,(int)i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=1;i<MAXN;++i){
		for(int j=i*2;j<MAXN;j+=i)fact[j].pb(i);
	}
	
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		vi A,B,C;
		A.resize(N+1,0);
		B.resize(N+1,0);
		C.resize(N+1,0);
		ans=N;
		for(int i=1;i<=N;++i)cin>>A[i];
		for(int i=1;i<=N;++i)cin>>C[i];
		for(int i=1;i<=N;++i)if(!B[i]){
			tmp.clear();
			tmp.pb(C[i]);
			int c=A[i];
			B[i]=1;
			while(c!=i){
				B[c]=1;
				tmp.pb(C[c]);
				c=A[c];
			}
			check();
			// for(auto i:tmp)cerr<<i<<' ';cerr<<'\n';
		}
		cout<<ans<<'\n';
	}
}