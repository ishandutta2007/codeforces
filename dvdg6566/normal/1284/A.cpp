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
#define All(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 501010

ll N,E,Q,a,b,c,d,cnt,ans,res;
string S[MAXN],T[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>E;
	for (int i=0;i<N;++i)cin>>S[i];
	for (int i=0;i<E;++i)cin>>T[i];
	cin>>Q;
	while(Q--){
		cin>>a;--a;
		cout<<S[a%N]<<T[a%E]<<'\n';
	}
}