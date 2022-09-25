#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=201005;

//i_am_noob
//#define wiwihorz  
const int K=455;
int n,m,sum[maxn],res[maxn],lst[maxn],val[K+5][K+5],cur[K+5],x[maxn],y[maxn],z[maxn];

void orzck(){
    cin >> n >> m;
    rep(n) cin >> x[i] >> y[i];
    rep(n) z[i]=x[i]+y[i];
    rep1(j,m){
        bug(j);
        int op,k;
        cin >> op >> k;
        k--;
        if(j) res[j]=res[j-1];
        if(op==1){
            lst[k]=j;
            if(z[k]>=K){
                for(int i=j; i<m; i+=z[k]){
                    if(i+x[k]<m) sum[i+x[k]]++;
                    if(i+z[k]<m) sum[i+z[k]]--;
                }
            }
            else{
                val[z[k]][(j+x[k])%z[k]]++;
                val[z[k]][j%z[k]]--;
                res[j]++;
            }
        }
        else{
            if(z[k]>=K){
                if((j-lst[k])%z[k]==0){
                    for(int i=j; i<m; i+=z[k]){
                        if(i+x[k]<m) sum[i+x[k]]--;
                        if(i+z[k]<m) sum[i+z[k]]++;
                    }
                }
                else{
                    if((j-lst[k]+z[k])%z[k]>=x[k]) sum[j]--;
                    else if(j+(x[k]-j+lst[k]+z[k]*m)%z[k]<m) sum[j+(x[k]-j+lst[k]+z[k]*m)%z[k]]--;
                    if(j+(lst[k]-j+z[k]*m)%z[k]<m) sum[j+(lst[k]-j+z[k]*m)%z[k]]++;
                    for(int i=j+(lst[k]-j+z[k]*m)%z[k]; i<m; i+=z[k]){
                        if(i+x[k]<m) sum[i+x[k]]--;
                        if(i+z[k]<m) sum[i+z[k]]++;
                    }
                }
                
            }
            else{
                if((j-lst[k]+z[k])%z[k]>x[k]||(j-lst[k])%z[k]==0) res[j]--;
                val[z[k]][(lst[k]+x[k])%z[k]]--;
                val[z[k]][lst[k]%z[k]]++;
            }
        }
        rep2(i,1,K+1) res[j]+=val[i][cur[i]];
        rep2(i,1,K+1) cur[i]++;
        rep2(i,1,K+1) if(cur[i]==i) cur[i]=0;
    }
    rep(m) bug(sum[i]);
    rep2(i,1,m) sum[i]+=sum[i-1];
    rep(m) print(res[i]+sum[i]);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}