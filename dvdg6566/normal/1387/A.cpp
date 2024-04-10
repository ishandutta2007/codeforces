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

vpi V[MAXN];
ll pos[MAXN];
ll neg[MAXN];
vi S;
ll N,E,Q,a,b,w;
ll ans;
ll vis[MAXN];

void fail(){
    cout<<"NO\n";
    exit(0);
}

void dfs(ll x){
    S.pb(x);
    vis[x]=1;
    for(auto v:V[x]){
        if(pos[x]!=INF){
            int t=v.s-pos[x];
            if(neg[v.f]==t){
                continue;
            }else if(neg[v.f]==INF){
                neg[v.f]=t;
                dfs(v.f);
                continue;
            }else {
                fail();
            }
        }
        if(neg[x]!=INF){
            int t=v.s-neg[x];
            if(pos[v.f]==t){
                continue;
            }else if (pos[v.f]==INF){
                pos[v.f]=t;
                dfs(v.f);
                continue;
            }else{
                fail();
            }
        }
    }
}

ld out[MAXN];

int main(){
    cin>>N>>E;
    for(ll i=1;i<=N;++i)pos[i]=neg[i]=INF;
    for(ll i=0;i<E;++i){
        cin>>a>>b>>w;
        V[a].pb(b,w);
        V[b].pb(a,w);
    }
    for(ll i=1;i<=N;++i){
        S.clear();
        if(vis[i])continue;
        pos[i]=0;
        dfs(i);
        ld aval=INF;
        sort(ALL(S));
        S.resize(unique(ALL(S))-S.begin());
        for(auto i:S){
            if(neg[i]!=INF&&pos[i]!=INF){
                ld cval=(ld)(neg[i]-pos[i])/2;
                if(aval==INF)aval=cval;
                else if(aval!=cval){
                    fail();
                }
            }
        }
        if(aval==INF){
            vector<ld> vx;
            for(auto i:S){
                if(neg[i]!=INF){
                    vx.pb(neg[i]);
                }else{
                    vx.pb(-pos[i]);
                }
            }
            sort(ALL(vx));
            aval=vx[SZ(vx)/2];
        }
        for(auto i:S){
            if(neg[i]!=INF){
                out[i]=-aval+neg[i];
            }else{
                out[i]=aval+pos[i];
            }
        }

    }
    cout<<"YES\n";
    for(int i=1;i<=N;++i){
        printf("%.1lf ",(double)out[i]);
    }
}