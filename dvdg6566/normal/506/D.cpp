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
const ll BSIZ=300;

int N,E,a,b,c,Q;
vpi col[MAXN];
vi V[MAXN];
map<pi,int> M;
int p[MAXN];
int par(int x){return (p[x]==x)?x:p[x]=par(p[x]);}
int res[MAXN];
vpi queries;
int ans[MAXN];
int vis[MAXN];
vi cur;

void dfs(int x){
    vis[x]=1;cur.pb(x);
    for(auto t:V[x])if(!vis[t]){
        dfs(t);
    }
}

int main(){
    cin>>N>>E;
    for(int i=1;i<=E;++i){
        cin>>a>>b>>c;
        col[c].pb(a,b);
    }
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>a>>b;
        queries.pb(a,b);
    }
    for(int i=1;i<=E;++i){
        if(SZ(col[i]) <= BSIZ)continue;
        
        for(int j=1;j<=N;++j)p[j]=j;
        

        for(auto e:col[i]){
            int a=par(e.f);
            int b=par(e.s);
            if(a!=b)p[a]=b;
        }
        for(int i=0;i<Q;++i){
            if(par(queries[i].f)==par(queries[i].s))++ans[i];
        }
    }
    for(int i=1;i<=E;++i){
        if(SZ(col[i]) > BSIZ)continue;
        set<int> nodes;
        for(auto e:col[i]){
            V[e.f].pb(e.s);
            V[e.s].pb(e.f);
            nodes.insert(e.f);
            nodes.insert(e.s);
        }
        for(auto i:nodes)vis[i]=0;
        for(auto i:nodes)if(!vis[i]){
            dfs(i);
            for(auto i:cur)for(auto j:cur){
                if(i<j)M[mp(i,j)]++;
            }
            cur.clear();
        }

        for(auto i:nodes)V[i].clear();
    }

    for(int i=0;i<Q;++i){
        int a=queries[i].f;
        int b=queries[i].s;
        ans[i]+=M[mp(min(a,b), max(a,b))];
        cout<<ans[i]<<'\n';
    }
}