#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,q,d[N][11];
struct node{
    pll p[11];
} f[N*4];
node operator+(node b, node a){
    node c;
    for(int i=1; i<=m; i++){
        if(a.p[i].S<=0 || a.p[i].S>m) c.p[i]=a.p[i];
        else c.p[i]=b.p[a.p[i].S];
    }
    return c;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        for(int i=1; i<=m; i++){
            int j=i,pr=-1;
            while(true){
                if(j==0 || j==m+1){
                    f[v].p[i]={l,j};
                    break;
                }
                if(!d[l][j]){
                    f[v].p[i]={l-1,j};
                    break;
                }
                if(j+d[l][j]==pr){
                    f[v].p[i]={-1,-1};
                    break;
                }
                pr=j;
                j+=d[l][j];
            }       
        }
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void upd(ll v, ll l, ll r, ll p){
    if(r-l==1){
        for(int i=1; i<=m; i++){
            int j=i,pr=-1;
            while(true){
                if(j==0 || j==m+1){
                    f[v].p[i]={l,j};
                    break;
                }
                if(!d[l][j]){
                    f[v].p[i]={l-1,j};
                    break;
                }
                if(j+d[l][j]==pr){
                    f[v].p[i]={-1,-1};
                    break;
                }
                pr=j;
                j+=d[l][j];
            }       
        }
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p);
    else upd(rc,m,r,p);
    f[v]=f[lc]+f[rc];
}
node get(ll v, ll l, ll r, ll tl, ll tr){
    if(l>=tr || tl>=r) return f[0];
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,tr)+get(rc,m,r,tl,tr);
}
int main(){
    fast_io;
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++) f[0].p[i]={0,i};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;
            if(c=='>') d[i][j]=1;
            else if(c=='<') d[i][j]=-1;
        }
    }
    build(1,1,n+1);
    while(q--){
        char c;
        cin >> c;
        if(c=='C'){
            ll i,j;
            cin >> i >> j >> c;
            if(c=='^') d[i][j]=0;
            else if(c=='>') d[i][j]=1;
            else d[i][j]=-1;
            upd(1,1,n+1,i);
        }else{
            ll x,y;
            cin >> x >> y;
            pll p=get(1,1,n+1,1,x+1).p[y];
            cout << p.F << ' ' << p.S << '\n';
        }
    }
    return 0;
}