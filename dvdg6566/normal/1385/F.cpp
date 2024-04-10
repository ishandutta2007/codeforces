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
const ll MAXN=500100;
const ll MAXK=20;
const ll INF = 1e13;
const ll MOD = 1e9+7;

vi V[MAXN];
int A[MAXN],N,T,K,a,b;
int deg[MAXN];
int rmv[MAXN];
priority_queue<pi,vpi,greater<pi>>pq;

int fd(int x){
	for(auto i:V[x])if(rmv[i]==0)return i;
	return 0;
}

void ers(int x){
	rmv[x]=1;
	int t=fd(x);
	A[t]++;
	if(A[t]>=K)pq.push(mp(A[t],t));
	// cerr<<"++ "<<t<<" from "<<x<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>K;
		for(int i=1;i<=N;++i){
			V[i].clear();deg[i]=0;
			A[i]=0;rmv[i]=0;
		}
		for(int i=1;i<N;++i){
			cin>>a>>b;
			V[a].pb(b);V[b].pb(a);
			deg[a]++;deg[b]++;
		}
		for(int i=1;i<=N;++i)if(deg[i]==1){
			ers(i);
		}
		for(int i=1;i<=N;++i)if(A[i]){
			if(A[i]>=K)pq.push(mp(A[i],i));
		}
		int ans=0;
		while(SZ(pq)){
			pi t=pq.top();pq.pop();
			if(rmv[t.s])continue;
			if(t.f<K)continue;
			if(A[t.s]!=t.f)continue;
			ans++;
			deg[t.s]-=K;
			A[t.s]-=K;
			if(A[t.s]>=K)pq.push(mp(A[t.s],t.s));
			if(A[t.s]==0&&deg[t.s]==1){
				ers(t.s);
			}
		}
		cout<<ans<<'\n';
	}
}