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
const int N=1e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
int n,a[N],L[N],R[N],q,t,l[N],r[N],W[N];
vector<int> cp,vec[N],bs[N];
struct node{
    int a,b,c,d;
} f[N*4];
node operator+(node a, node b){
    node ans;
    ans.d=(a.d&b.d);
    ans.b=a.b;
    ans.c=b.c;
    ans.a=max({a.a,b.a,a.c+b.b});
    if(a.d){
        ans.b+=b.b;
    }
    if(b.d){
        ans.c+=a.c;
    }
    return ans;
}
void build(int v, int l, int r){
    if(r-l==1){
        f[v].a=f[v].b=f[v].c=f[v].d=1;
        return;
    }
    int m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void upd(int v, int l, int r, int p){
    if(r-l==1){
        f[v].a=f[v].b=f[v].c=f[v].d=0;
        return;
    }
    int m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p);
    else upd(rc,m,r,p);
    f[v]=f[lc]+f[rc];
}
node get(int v, int l, int r, int tl, int tr){
    if(tl>=r || l>=tr) return f[0];
    if(l>=tl && r<=tr) return f[v];
    int m=(l+r)>>1;
    return get(lc,l,m,tl,tr)+get(rc,m,r,tl,tr);
}
int main(){
    fast_io;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cp.pb(a[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    for(int i=1; i<=n; i++){
        a[i]=lower_bound(cp.begin(),cp.end(),a[i])-cp.begin()+1;
        vec[a[i]].pb(i);
    }
    t=cp.size();
    cin >> q;
    for(int i=1; i<=q; i++){
        cin >> L[i] >> R[i] >> W[i];
        l[i]=1;
        r[i]=t+1;
        bs[(l[i]+r[i])>>1].pb(i);
    }
    for(int g=0; g<LN; g++){
        build(1,1,n+1);
        for(int i=1; i<=t; i++){
            for(int j : vec[i-1]) upd(1,1,n+1,j);
            for(int j : bs[i]){
                if(get(1,1,n+1,L[j],R[j]+1).a>=W[j]) l[j]=i;
                else r[j]=i;
                if(r[j]-l[j]>1) bs[(l[j]+r[j])>>1].pb(j);
            }
            bs[i]={};
        }
    }
    for(int i=1; i<=q; i++) cout << cp[l[i]-1] << '\n';
    return 0;
}