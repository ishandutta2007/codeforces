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
string S;
vi open, close;
int blk[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	ll ans=1;
	for (int i=1;i<=N;++i){
		cin>>A[i];
		if (B[A[i]%M]){
			cout<<0;
			return 0;
		}
		B[A[i]%M]++;
	}
	for (int i=1;i<=N;++i){
		for (int j=i+1;j<=N;++j){
			ans = ans*((abs(A[i] - A[j]) % M))%M;
		}
	}
	cout<<ans;
}