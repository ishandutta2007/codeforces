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
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
const ll MAXN=5100;

ll A[MAXN];
int rmin[MAXN];
ll N;
unordered_map<int,int> U;
ll memo[MAXN][MAXN];
// ll memo[MAXN];
int cnt;

void dnc0(ll s,ll e){
	if(e<s)return;
	U[s*N+e]=cnt;
	int m=s;
	for(int i=s+1;i<=e;++i)if(A[i]<A[m])m=i;
	rmin[cnt]=m;
	++cnt;
	dnc0(s,m-1);
	dnc0(m+1,e);
}

ll dnc(ll s,ll e,ll h){
	if(e<s)return 0;
	ll i=U[s*N+e];
	if(memo[i][h]!=-1)return memo[i][h];
	ll m=rmin[i];
	// cerr<<s<<' '<<e<<' '<<m<<'\n';
	ll xh=A[m]-A[h];

	return memo[i][h]=min(dnc(s,m-1,h)+dnc(m+1,e,h)+1, xh+dnc(s,m-1,m) + dnc(m+1,e,m));
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(ll i=1;i<=N;++i)cin>>A[i];

	dnc0(1,N);
	memset(memo,-1,sizeof(memo));
	cout<<dnc(1,N,0);
}