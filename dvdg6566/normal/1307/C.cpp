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
ll L[30];
ll dp[30][30];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string S;cin>>S;
	int N = SZ(S);
	ll ans=0;
	for (int i=0;i<N;++i)A[i+1] = S[i] - 'a';
	for (int i=1;i<=N;++i){
		int t = A[i];
		for (int j=0;j<26;++j){
			dp[t][j]+=L[j];
		}
		L[t]++;
		ans = max(ans, L[t]);
	}
	
	for (int i=0;i<26;++i)for (int j=0;j<26;++j)ans=max(ans,dp[i][j]);
	cout<<ans;
}