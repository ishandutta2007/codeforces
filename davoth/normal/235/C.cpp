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
#define killshayan kill("done!\n")
#define killmashtali kill("Hello, World!")
const int N=1e6+10,LN=19,M=3e2+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const double pi=acos(-1);
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
struct SuffixAutomaton {
    static const int _N = 1e6 + 10;
    static const int _Sig = 26;

    int nx[2 * _N][_Sig], lnk[2 * _N], len[2 * _N];
    int cur, sz;
    inline int conv(char c){ return c - 'a'; }

    SuffixAutomaton (){
        cur = 0; sz = 1;
        memset(lnk, -1, sizeof lnk);
        memset(nx, -1, sizeof nx);
        len[cur] = 0;
    }
    void AddChar(int c){
        // ~nw : true if nw != -1

        int nw = sz ++;
        len[nw] = len[cur] + 1;
        for(; ~cur && nx[cur][c] == -1; cur = lnk[cur])
            nx[cur][c] = nw;

        if(cur == -1){
            lnk[nw] = 0;
            cur = nw;
            return ;
        }
        int q = nx[cur][c];
        if(len[q] == len[cur] + 1){
            lnk[nw] = q;
            cur = nw;
            return ;
        }

        int clone = sz ++;
        memcpy(nx[clone], nx[q], sizeof nx[q]);

        lnk[nw] = clone;
        lnk[clone] = lnk[q];
        lnk[q] = clone;

        len[clone] = len[cur] + 1;
        for(; ~cur && nx[cur][c] == q; cur = lnk[cur])
            nx[cur][c] = clone;

        cur = nw;
        return;
    }
    void Build(string s){ for(auto c : s) AddChar(conv(c)); }
} suf;
ll n,dp[N*2],f[N*2];
pll a[N*2];
string s,t;
int main(){
    fast_io;
    cin >> s >> n;
    suf.Build(s);
    for(ll i=suf.cur; ~i; i=suf.lnk[i]) dp[i]=1;
    for(ll i=0; i<suf.sz; i++) a[i]={-suf.len[i],i};
    sort(a,a+suf.sz);
    for(ll i=0; i<suf.sz; i++){
        for(ll j=0; j<26; j++){
            if(~suf.nx[a[i].S][j]) dp[a[i].S]+=dp[suf.nx[a[i].S][j]];
        }
    }
    memset(f,-1,sizeof f);
    while(n--){
        cin >> t;
        ll k=t.size(),r=0,v=0,ans=0;
        t=t+t;
        for(ll i=0; i<k; i++){
            while(r-i<k){
                ll c=t[r]-'a';
                if(~suf.nx[v][c]){
                    v=suf.nx[v][c];
                    r++;
                }else{
                    break;
                }
            }
            if(r-i==k && f[v]!=n){
                f[v]=n;
                ans+=dp[v];
            }
            if(r==i){
                r++;
            }else{
                if(r-i-1<=suf.len[suf.lnk[v]]) v=suf.lnk[v];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}