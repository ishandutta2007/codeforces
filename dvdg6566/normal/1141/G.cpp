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

vpi V[MAXN];
int res[MAXN];
int N,K,a,b,T;
vi deg;
int p[MAXN],cnt;

void prop(int x, int val){
    int d = SZ(V[x]);
    if (d > T){
        // Bad Vertice
        for (auto v:V[x]){
            if (v.f == p[x])continue;
            p[v.f] = x;
            res[v.s] = 1;
            prop(v.f,1);
        }
    }else{
        int id = 1;
        if (id == val)++id;
        for (auto v:V[x]){
            if (v.f == p[x])continue;
            p[v.f] = x;
            res[v.s] = id;
            ++id;
            if(id == val)++id;
            prop(v.f, res[v.s]);
        }
    }
}

int main(){
    // freopen("in.txt","r",stdin);
    cin >>N>>K;
    for (int i=1;i<N;++i){
        cin>>a>>b;
        V[a].pb(mp(b,i));
        V[b].pb(mp(a,i));
    }
    for (int i=1;i<=N;++i){
        deg.pb(SZ(V[i]));
    }
    
    sort(ALL(deg));
    reverse(ALL(deg));
    T = deg[K];
    cout<<T<<'\n';
    prop(1,0);
    for (int i=1;i<N;++i)cout<<res[i]<<' ';
}