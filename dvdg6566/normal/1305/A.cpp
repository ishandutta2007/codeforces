#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 300100;

ll T,Q,N,M,a,b,c,d,e,f;
ll A[MAXN];
ll B[MAXN];
vi V;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while (T--){
		cin>>N;
		for (int i=1;i<=N;++i)cin>>A[i];
		for (int i=1;i<=N;++i)cin>>B[i];
		sort(A+1,A+N+1);
		sort(B+1,B+N+1);
		for (int i=1;i<=N;++i)cout<<A[i]<<' ';cout<<'\n';
		for (int i=1;i<=N;++i)cout<<B[i]<<' ';cout<<'\n';	
	}
}