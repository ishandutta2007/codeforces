#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=6e5+10,LN=20,M=2e2+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,q,ans[N],p[N],Q[N],L,R,C[N][26],F[N],en[N],ts,a[N],k,P[N];
multiset<ll> ms[N];
string s[N];
pll qu[N];
void AddTrie(ll j){
    int v=0;
    for (char ch : s[j]){
        if (!C[v][ch-'a']) C[v][ch-'a']=++ts,P[ts]=v;
        v=C[v][ch-'a'];
    }
    en[j]=v;
    ms[v].insert(a[j]);
    ans[v]=max(ans[v],a[j]);
}
void BuildAho(){
    for (int i=0; i<26; i++) if (C[0][i]) Q[R++]=C[0][i];
    while (L<R){
        int v=Q[L++];
        if(ms[F[v]].empty()) p[v]=p[F[v]];
        else p[v]=F[v];
        for (int i=0; i<26; i++){
            if (!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }
        }
    }
}
int main(){
    fast_io;
    cin >> n >> q;
    memset(ans,-1,sizeof ans);
    for(ll i=1; i<=n; i++){
        cin >> s[i];
        AddTrie(i);
    }
    for(ll i=1; i<=q; i++){
        ll t;
        cin >> t;
        if(t==1){
            ll j,x;
            cin >> j >> x;
            qu[i]={j,x};
        }else{
            cin >> s[n+(++k)];
            a[n+k]=-1;
            AddTrie(n+k);
            qu[i]={-1,n+k};
        }
    }
    BuildAho();
    for(ll i=1; i<=q; i++){
        if(qu[i].F!=-1){
            ll t=qu[i].F;
            ms[en[t]].erase(ms[en[t]].find(a[t]));
            a[t]=qu[i].S;
            ms[en[t]].insert(a[t]);
            ans[en[t]]=*ms[en[t]].rbegin();
        }else{
            ll an=-1;
            ll v=en[qu[i].S];
            while(v){
                ll u=v;
                while(u){
                    an=max(an,ans[u]);
                    u=p[u];
                }
                v=P[v];
            }
            cout << an << '\n';
        }
    }
    return 0;
}