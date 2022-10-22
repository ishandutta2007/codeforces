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
const int N=4e5+10,LN=20,M=2e2+10,SQ=250,inf=1e9;
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
ll n,Q[N],L,R,C[N][26],F[N],ted[N],a[N],r[N],m,ts,ans;
string s[N],t;
void AddTrie(string s, ll w){
    int v=0,x=0;
    for (char ch : s){
        if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
        v=C[v][ch-'a'];
        r[x++]=v;
    }
    ted[v]+=w;
}
void BuildAho(){
    for (int i=0; i<26; i++) if (C[0][i]) Q[R++]=C[0][i];
    while (L<R){
        int v=Q[L++];
        ted[v]+=ted[F[v]];
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
    cin >> t >> n;
    m=t.size();
    for(ll i=1; i<=n; i++){
        cin >> s[i];
        AddTrie(s[i],1);
    }
    AddTrie(t,0);
    BuildAho();
    for(ll i=0; i<m; i++){
        a[i]=ted[r[i]];
    }
    ts=L=R=0;
    memset(Q,0,sizeof Q);
    memset(C,0,sizeof C);
    memset(F,0,sizeof F);
    memset(ted,0,sizeof ted);
    for(ll i=1; i<=n; i++){
        reverse(s[i].begin(),s[i].end());
        AddTrie(s[i],1);
    }
    reverse(t.begin(),t.end());
    AddTrie(t,0);
    BuildAho();
    for(ll i=0; i<m-1; i++){
        ans+=a[m-i-2]*ted[r[i]];
    }
    cout << ans << '\n';
    return 0;
}