#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=1e5+4,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll n,Rank[N][LN],pw,P[N],dp[N],ans=1,f[N*4],ip[N],rm[LN][N];
string S;
bool cmp(int x, int y){
    if(Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
    if(max(x, y)+(1<<(pw-1))>n) return x>y;
    return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}
void BuildSuffixArray(){
    for(int i=1; i<=n; i++) Rank[i][0]=S[i-1], P[i]=i;
    for(pw=1; pw<LN; pw++){
        sort(P+1, P+n+1, cmp);
        Rank[P[1]][pw]=1;
        for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
    }
}
ll LCP(int x, int y){
    int res=0;
    for(int i=LN-1; i>=0; i--) if(Rank[x][i]==Rank[y][i] && max(x,y)-1<=n){
        x+=(1<<i);
        y+=(1<<i);
        res|=(1<<i);
    }
    return res;
}
void upd(ll v, ll l, ll r, ll p, ll x){
    if(r-l==1){
        f[v]=x;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p,x);
    else upd(rc,m,r,p,x);
    f[v]=max(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)>>1;
    return max(get(lc,l,m,tl,min(m,tr)),get(rc,m,r,max(m,tl),tr));
}
int main(){
    fast_io;
    cin >> n >> S;
    BuildSuffixArray();
    for(ll i=1; i<=n; i++){
        ip[P[i]]=i;
        if(i<n) rm[0][i]=LCP(P[i],P[i+1]);
    }
    for(ll i=1; i<LN; i++){
        for(ll j=1; j<=n-(1<<i); j++){
            rm[i][j]=min(rm[i-1][j],rm[i-1][j+(1<<(i-1))]);
        }
    }
    ll k=dp[n]=1;
    for(ll i=n-1; i>0; i--){
        k++;
        while(k){
            ll L=ip[i],R=ip[i];
            for(ll j=LN; j--;){
                if(R+(1<<j)<=n && rm[j][R]>=k-1) R+=(1<<j);
                if(L-(1<<j)>0 && rm[j][L-(1<<j)]>=k-1) L-=(1<<j);
            }
            if(get(1,1,n+1,L,R+1)>=k-1) break;
            L=ip[i+1];
            R=ip[i+1];
            for(ll j=LN; j--;){
                if(R+(1<<j)<=n && rm[j][R]>=k-1) R+=(1<<j);
                if(L-(1<<j)>0 && rm[j][L-(1<<j)]>=k-1) L-=(1<<j);
            }
            if(get(1,1,n+1,L,R+1)>=k-1) break;
            k--;
            upd(1,1,n+1,ip[i+k],dp[i+k]);
        }
        dp[i]=k;
        ans=max(ans,dp[i]);
    }
    cout << ans << '\n';
    return 0;
}