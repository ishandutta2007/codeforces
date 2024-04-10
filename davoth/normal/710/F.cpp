#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=/*long long*/ int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<ld>;
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
const int N=3e5+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
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
ll q,L,R,Q[N],F[LN*2][N],G[LN*2][N],sz[LN*2],T;
string S[N];
vector<ll> vec[LN*2];
vector<vector<ll>> C[LN*2];
void AddTrie(int t, int i){
    int v=0;
    for(char c : S[i]){
        if(!C[t][v][c-'a']) C[t][v][c-'a']=++T;
        v=C[t][v][c-'a'];
    }
    G[t][v]++;
}
void BuildAho(int t){
    L=R=0;
    for(int i=0; i<26; i++) if(C[t][0][i]) Q[R++]=C[t][0][i];
    while(L<R){
        int v=Q[L++];
        G[t][v]+=G[t][F[t][v]];
        for(int i=0; i<26; i++){
            if(!C[t][v][i]) C[t][v][i]=C[t][F[t][v]][i];
            else{
                F[t][C[t][v][i]]=C[t][F[t][v]][i];
                Q[R++]=C[t][v][i];
            }
        }
    }
}
int main(){
    fast_io;
    cin >> q;
    for(ll I=1; I<=q; I++){
        ll t;
        cin >> t >> S[I];
        if(t==3){
            ll ans=0;
            for(ll i=0; i<LN; i++){
                if(!sz[i]) continue;
                ll v=0;
                for(char c : S[I]){
                    v=C[i][v][c-'a'];
                    ans+=G[i][v];
                }
            }
            for(ll i=LN; i<LN+LN; i++){
                if(!sz[i]) continue;
                ll v=0;
                for(char c : S[I]){
                    v=C[i][v][c-'a'];
                    ans-=G[i][v];
                }
            }
            cout << ans << endl;
        }else if(t==1){
            ll j=0;
            vector<ll> tp={I};
            while(sz[j]){
                for(ll x : vec[j]) tp.pb(x);
                vec[j].clear();
                for(ll x=0; x<=sz[j]; x++){
                    F[j][x]=G[j][x]=0;
                }
                C[j].clear();
                sz[j++]=0;
            }
            T=0;
            for(ll k : tp){
                sz[j]+=S[k].size();
            }
            vector<ll> zr(26,0);
            C[j].resize(sz[j]+1,zr);
            for(ll k : tp){
                AddTrie(j,k);
            }
            BuildAho(j);
            vec[j]=tp;
        }else{
            ll j=LN;
            vector<ll> tp={I};
            while(sz[j]){
                for(ll x : vec[j]) tp.pb(x);
                vec[j].clear();
                for(ll x=0; x<=sz[j]; x++){
                    F[j][x]=G[j][x]=0;
                }
                C[j].clear();
                sz[j++]=0;
            }
            T=0;
            for(ll k : tp){
                sz[j]+=S[k].size();
            }
            vector<ll> zr(26,0);
            C[j].resize(sz[j]+1,zr);
            for(ll k : tp){
                AddTrie(j,k);
            }
            BuildAho(j);
            vec[j]=tp;
        }
    }
    return 0;
}