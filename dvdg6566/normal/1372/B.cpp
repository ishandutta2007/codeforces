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
const ll MAXN=5100;
const ll MAXK=100000;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,K,Q,L,R,Y,C,a,b,c;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N;
		int done=0;
		for(int i=2;i*i<=N;++i)if(N%i==0){
			done=1;
			int a=N/i;
			cout<<a<<' '<<(i-1)*a<<'\n';
			break;
		}
		if(done)continue;
		cout<<1<<' '<<N-1<<'\n';
	}
}