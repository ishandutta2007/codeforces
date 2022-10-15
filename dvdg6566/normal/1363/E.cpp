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
const ll MAXN=200100;
const ll MAXK=17;
const ll INF=1e18;
const ll MOD=998244353;

ll A[MAXN];
ll B[MAXN];
ll C[MAXN];
vi V[MAXN];
ll N,a,b;
ll ans;

pi dfs(int x,int p){
    if(p!=-1)A[x]=min(A[x],A[p]);
    int o=0;
    int z=0;
    if(B[x]==0&&C[x]==1)++o;
    else if(B[x]==1&&C[x]==0)++z;
    for (auto v:V[x])if(v!=p){
        pi a=dfs(v,x);
        o+=a.f;
        z+=a.s;
    }
    ll e=min(o,z);
    ans+=e*A[x]*2;
    return mp(o-e,z-e);
}

int main(){
    cin>>N;
    for (int i=1;i<=N;++i){
        cin>>A[i]>>B[i]>>C[i];
    }
    for (int i=1;i<N;++i){
        cin>>a>>b;
        V[a].pb(b);
        V[b].pb(a);
    }
    pi x=dfs(1,-1);
    if(max(x.f,x.s)!=0){
        cout<<-1;
        return 0;
    }
    cout<<ans;
}