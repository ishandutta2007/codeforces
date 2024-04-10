#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005;

//i_am_noob
//#define wiwihorz  
int n,a[maxn],b[maxn],c[maxn],ans;
bool side[maxn],color[maxn];
vector<int> vec;

void hhhhauraorz(){
    cin >> n;
    rep(n) cin >> a[i] >> b[i];
    rep(n) a[i]--,b[i]--;
    rep(n) if(max(a[i],b[i])<=n-1||min(a[i],b[i])>=n){
        print(-1);
        return;
    }
    rep(n){
        if(a[i]<=n-1) c[a[i]]=b[i],side[a[i]]=0;
        else c[b[i]]=a[i],side[b[i]]=1;
    }
    rep(n){
        bug(c[i],side[i]);
        if(vec.empty()||c[i]>vec.back()) vec.pb(c[i]);
        else *lower_bound(all(vec),c[i])=c[i];
    }
    if(sz(vec)>=3){
        print(-1);
        return;
    }
    int lst=0,minn=inf,minn1,k1,k2;
    rep(n){
        minn=min(minn,c[i]);
        if(minn+i+1==2*n){
            color[lst]=0;
            minn1=c[lst];
            rep2(j,lst+1,i+1){
                if(c[j]<minn1){
                    minn1=c[j];
                    color[j]=0;
                }
                else color[j]=1;
            }
            k1=0;
            rep2(j,lst,i+1) k1+=side[j]^color[j];
            k2=0;
            rep2(j,lst,i+1) k2+=!(side[j]^color[j]);
            ans+=min(k1,k2);
            lst=i+1;
            bug(k1,k2);
        }
    }
    print(ans);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}