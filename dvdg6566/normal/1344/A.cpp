#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
const ll MAXN = 200010;
const int INF = 1e9;
const ll MOD = 1e9+7;
const int H = 500;

ll N,L,ans,D,M,a,b;
ll A[MAXN];
ll B[MAXN];

int main(){
	// freopen("movie.in","r",stdin);
	// freopen("movie.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>L;
	while(L--){
		cin>>N;
		for(int i=0;i<=N;++i)B[i]=0;
		bool fail=0;
		for(int i=1;i<=N;++i){
			cin>>A[i];
			A[i]%=N;
			if(A[i]<0)A[i]+=N;
			int t=(i+A[i])%N;
			if(B[t]==1)fail=1;
			B[t]=1;
		}
		if(!fail)cout<<"YES\n";
		else cout<<"NO\n";
	}
}