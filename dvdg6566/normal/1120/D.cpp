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
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

ll N,a,b;
ll W[MAXN];
vi V[MAXN];
ll optglo[MAXN], optinc[MAXN];
ll p[MAXN];
vi out;
bool glo[MAXN], inc[MAXN];

void dfs(int x){
    int num_child = SZ(V[x]);
    if (x != 1)--num_child;

    if (num_child == 0){
        // Leaf Node
        optglo[x] = W[x];
        optinc[x] = 0;
        return;
    }
    ll me = INF;
    for (auto v : V[x]){
        if (p[x] == v)continue;
        p[v] = x;
        dfs(v);
        optinc[x] += optglo[v];
        me = min(me, optinc[v] - optglo[v]);
    }
    optglo[x] = optinc[x];
    optinc[x] += me;
    optglo[x] = min(optglo[x], optinc[x] + W[x]);
}

void check(int x){
    
    int num_child = SZ(V[x]);
    if (x != 1)--num_child;

    if (num_child == 0){
        if (glo[x])out.pb(x);
        return;
    }

    ll t = 0;
    ll me = INF;

    for (auto v : V[x]){
        if (p[x] == v)continue;
        t += optglo[v];
        me = min(me, optinc[v] - optglo[v]);
    }

    if (glo[x] && t + me + W[x] == optglo[x])out.pb(x);

    if (glo[x] && optglo[x] == t){
        // Case 1 for global is if you take all the globals from the kids
        for (auto v : V[x])if (p[x] != v)glo[v] = 1;
    }
    if (inc[x] || (glo[x] && optinc[x] + W[x] == optglo[x]) ){
        vi possible;
        for (auto v : V[x]){
            if (v == p[x])continue;
            if (t + optinc[v] - optglo[v] == optinc[x])possible.pb(v);
        }
        if (SZ(possible) == 1){
            inc[possible[0]] = 1;
            for (auto v : V[x]){
                if (v == p[x] || v == possible[0])continue;
                glo[v] = 1;
            }
        }
        if (SZ(possible) > 1){
            for (auto v : V[x]){
                if (v != p[x])glo[v] = 1;
            }
            for (auto v : possible)inc[v] = 1;
        }
    }
    for (auto v : V[x])if (v != p[x])check(v);
}

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N;
    for (int i=1;i<=N;++i)cin>>W[i];
    for (int i=1;i<N;++i){
        cin>>a>>b;
        V[a].pb(b);
        V[b].pb(a);
    }
    dfs(1);
    glo[1] = 1;
    check(1);
    // for (int i=1;i<=N;++i)cout<<optglo[i]<<' '<<optinc[i]<<'\n';
    // cout<<'\n';
    // for (int i=1;i<=N;++i)cout<<glo[i]<<' '<<inc[i]<<'\n';
    // cout<<'\n';
    cout<<optglo[1]<<' '<<SZ(out)<<'\n';
    sort(ALL(out));
    for (auto i : out)cout<<i<<' ';
}