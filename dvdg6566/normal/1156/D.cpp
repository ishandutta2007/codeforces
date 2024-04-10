#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
ll INF = 1e15;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define f first 
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

ll pre1[MAXN], pre0[MAXN];
ll post0[MAXN], post1[MAXN];
vpi V[MAXN];
ll p[MAXN];
ll N,a,b,c;

pi dfs(ll x){
    for (auto i : V[x]){
        if (p[i.f] != 0)continue;
        p[i.f] = x;
        pi t = dfs(i.f);
        if (i.s == 1)pre1[x] += t.s+1;
        else pre0[x] += t.f+1;
    }
    return mp(pre0[x], pre1[x]);
}

void prop(ll x, ll zeros, ll ones){
    zeros += pre0[x];
    ones += pre1[x];
    for (auto v : V[x]){
        if (p[v.f] != x)continue;
        if (v.s == 1){
            post1[v.f] = ones - pre1[v.f];
        }else{
            // v.s = 0
            post0[v.f] = zeros - pre0[v.f];
        }
        prop(v.f,post0[v.f], post1[v.f]);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    cin >> N;
    for (ll i=1;i<N;++i){
        cin >>a >>b>>c;
        V[a].pb(mp(b,c));
        V[b].pb(mp(a,c));
    }
    p[1] = 1;
    dfs(1);
    prop(1,0,0);
    ll ans = 0;
    for (ll i=1;i<=N;++i){
        ll t = (pre0[i] + 1) * (post1[i] + 1) + (pre1[i] + 1) * (post0[i] + 1) + (pre1[i] * pre0[i]) - 2;
        //cout<<t<<' '<<pre0[i]<<' '<<pre1[i]<<' '<<post0[i]<<' '<<post1[i]<<'\n';
        ans += t;
    }
    cout<<ans;
    //for (ll i=1;i<=N;++i)cout<<pre0[i]<<' '<<pre1[i]<<' '<<post0[i]<<' '<<post1[i]<<'\n';
}