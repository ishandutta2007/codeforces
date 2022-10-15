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
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 100010;

vi V[MAXN];
ll sub[MAXN];
ll d[MAXN];
ll N,a,b;
vi Q[MAXN];
priority_queue<pi>pq;
ll A[MAXN];
ll ans;
ll subgrp[MAXN];

ll dfs1(ll x,ll p){
    sub[x]=1;
    for(auto v:V[x])if(v!=p){
        sub[x]+=dfs1(v,x);
    }
    return sub[x];
}

ll dfs2(ll x,ll p){
    for(auto v:V[x])if(v!=p){
        if(sub[v]>N/2)return dfs2(v,x);
    }
    return x;
}

void dfs3(ll x,ll p,ll rt){
    subgrp[x]=rt;
    Q[rt].pb(x);
    for(auto v:V[x])if(v!=p){
        d[v]=d[x]+1;
        dfs3(v,x,rt);
    }
}

int main(){
    cin>>N;
    for(ll i=1;i<N;++i){
        cin>>a>>b;
        V[a].pb(b);
        V[b].pb(a);
    }
    dfs1(1,-1);
    ll x=dfs2(1,-1);
    subgrp[x]=x;
    for(auto t:V[x]){
        d[t]=1;
        dfs3(t,x,t);
        pq.push(mp(SZ(Q[t]), t));
    }
    ll cur=x;
    while(SZ(pq)){
        pi t=pq.top();pq.pop();
        if(t.s==subgrp[cur]){
            pi nt=pq.top();pq.pop();
            pq.push(t);
            t=nt;
        }
        // cerr<<"Current node "<<cur<<'\n';
        // cerr<<"Sub "<<t.s<<'\n';
        ll c=Q[t.s].back();Q[t.s].pop_back();
        // cerr<<"Next node "<<c<<'\n';
        --t.f;
        if(t.f)pq.push(t);
        ans+=d[cur]+d[c];
        A[cur]=c;
        cur=c;
    }
    A[cur]=x;
    ans+=d[cur];
    cout<<ans<<'\n';
    for(ll i=1;i<=N;++i)cout<<A[i]<<' ';
}