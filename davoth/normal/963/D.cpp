/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e5+10,LN=18,M=1e6+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,sz,Rank[N][LN],pw,P[N],k[N],ans[N],p[N],cl[N],st[N];
string S,s,t[N];
vector<ll> qu[N],ed[N],cp[N];
queue<ll> wtf[N];
ll gp(ll x){
    return p[x]?p[x]=gp(p[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(cp[v].size()<cp[u].size()) swap(v,u);
    p[u]=v;
    for(ll i : cp[u]) cp[v].pb(i);
}
bool cmp(int x, int y){
    if(Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
    if(max(x, y)+(1<<(pw-1))>sz) return x>y;
    return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}
void BuildSuffixArray(){
    for(int i=1; i<=sz; i++) Rank[i][0]=S[i-1], P[i]=i;
    for(pw=1; pw<LN; pw++){
        sort(P+1, P+sz+1, cmp);
        Rank[P[1]][pw]=1;
        for (int i=2; i<=sz; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
    }
}
ll LCP(int x, int y){
    int res=0;
    for(int i=LN-1; i>=0; i--) if(Rank[x][i]==Rank[y][i] && max(x,y)-1<=sz){
        x+=(1<<i);
        y+=(1<<i);
        res|=(1<<i);
    }
    return res;
}
int main(){
    fast_io;
    cin >> s >> n;
    memset(ans,-1,sizeof ans);
    for(ll i=1; i<=(ll)s.size(); i++) cp[i].pb(i);
    S=s;
    for(ll i=1; i<=n; i++){
        cin >> k[i] >> t[i];
        st[i]=S.size()+1;
        for(char c : t[i]) S.pb(c);
        qu[t[i].size()].pb(i);
    }
    sz=S.size();
    BuildSuffixArray();
    for(ll i=1; i<sz; i++){
        ed[LCP(P[i],P[i+1])].pb(i);
    }
    for(ll i=N-1; i; i--){
        for(ll j : ed[i]) uni(P[j],P[j+1]);
        if(qu[i].empty()) continue;
        for(ll j : qu[i]){
            for(ll x : cp[gp(st[j])]) if(x+t[j].size()<=s.size()+1) cl[x]=j;
        }
        for(ll j=1; j<=(ll)s.size(); j++){
            ll x=cl[j];
            if(!x) continue;
            if((ll)wtf[x].size()==k[x]) wtf[x].pop();
            wtf[x].push(j);
            if((ll)wtf[x].size()==k[x] && (ans[x]==-1 || j-wtf[x].front()<ans[x])) ans[x]=j-wtf[x].front();
            cl[j]=0;
        }
    }
    for(ll i=1; i<=n; i++){
        if(ans[i]==-1) cout << ans[i] << '\n';
        else cout << ans[i]+t[i].size() << '\n';
    }
    return 0;
}