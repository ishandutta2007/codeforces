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

int N,M,a,b,D;
vi V[MAXN];
vpi E,O;

int p[MAXN];
int par(int x){return (x == p[x]) ? x : p[x] = par(p[x]);}
int ok[MAXN];

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N>>M>>D;
    for (int i=0;i<M;++i){
        cin>>a>>b;
        V[a].pb(b);
        V[b].pb(a);
        E.pb(mp(a,b));
    }
    if (SZ(V[1]) < D){
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=N;++i)p[i] = i;
    int grp = N;
    for (auto i : E){
        if (i.f == 1 || i.s == 1)continue;
        if (par(i.f) == par(i.s))continue;
        --grp;
        p[par(i.f)] = par(i.s);
    }
    if (grp > D+1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for (auto i : V[1]){
        if (par(i) != 1 && ok[par(i)] == 0){
            O.pb(mp(i,1));
            ok[par(i)] = 1;
        }
    }
    for (int i=1;i<=N;++i)p[i] = i;
    for (auto i : O){
        if (par(i.f) == par(i.s))assert(0);
        p[par(i.f)] = par(i.s);
        cout<<i.f<<' '<<i.s<<'\n';
        --D;
    }
    int ct = -1;
    while(D != 0){
        ++ct;
        int v = V[1][ct];
        if (par(v) == par(1))continue;
        cout<<1<<' '<<v<<'\n';
        p[par(v)] = 1;
        --D;
    }
    for (auto i:E){
        if (i.f == 1 || i.s == 1)continue;
        if (par(i.f) == par(i.s))continue;
        cout<<i.f<<' '<<i.s<<'\n';
        p[par(i.f)] = par(i.s);
    }
}