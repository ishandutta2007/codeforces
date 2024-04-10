#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 998244353;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100
#define MAXL 2010

ll dp[MAXL], query[MAXL];
vi V;
vpi Q;
ll N,M,K,a,b;

ll rsq(pi r){
    return V[r.s] - V[r.f-1];
}

ll ask(ll x){
    // dp state dp[x] stores the maximum amount saved after buying the x most ex shovels
    if (x == K)return 0;
    if (x > K)return -INF;
    if (dp[x] != -1)return dp[x];
    ll ans = 0;

    // cout<<"Asking "<<x<<'\n';
    for (int i=1;i<=K-x;++i){
        a = i;
        b = query[i];
        if (!b)continue;
        // cout<<"Consider set with size " <<a<<'\n';
        pi payrange = mp(x+1,x+a-b);
        pi freerange = mp(x+a-b+1,x+a);
        // cout<<"Payrange is "<<payrange.f<<' '<<payrange.s<<'\n';
        // cout<<"Freerange is "<<freerange.f<<' '<<freerange.s<<' '<<rsq(freerange)<<'\n';
        ans = max(ans, rsq(freerange) + ask(a+x));
    }

    return dp[x] = ans;
}

int main(){
    // freopen("in.txt","r",stdin);
    cin >>N >>M>>K;
    for (int i=0;i<N;++i){
        cin>>a;
        V.pb(a);
    }
    sort(ALL(V));
    while(SZ(V) > K)V.pop_back();
    V.pb(INF);
    reverse(ALL(V));
    // for (auto i :V)cout<<i<<' '<<'\n';

    for (int i=1;i<=K;++i)V[i] = V[i] + V[i-1];

    for (int i=0;i<M;++i){
        cin >> a >> b;
        if (a > K)continue;
        query[a] = max(query[a], b);
    }
    for (int i=1;i<=K;++i){
        if (!query[i])continue;
        a = i;
        b = query[i];
        Q.pb(mp(a,b));
    }
    memset(dp,-1,sizeof(dp));
    ask(0);
    // for (int i=0;i<=K;++i)cout<<dp[i]<<' ';cout<<'\n';

    cout<<V[K] -INF- ask(0);
}