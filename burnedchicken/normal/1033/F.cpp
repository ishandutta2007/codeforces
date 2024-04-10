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
const int maxn=pow2(12)+5;

//i_am_noob
//#define wiwihorz  
int n,q,w,cnt[maxn],dp[550000],pw3[49],a[49],bad;

inline bool f(char c, bool x, bool y){
    if(c=='A') return x&&y;
    if(c=='O') return x||y;
    if(c=='X') return x^y;
    if(c=='a') return !(x&&y);
    if(c=='o') return !(x||y);
    if(c=='x') return !(x^y);
}

void orzck(){
    cin >> w >> n >> q;
    rep(n){
        int x;
        cin >> x;
        cnt[x]++;
    }
    pw3[0]=1;
    rep2(i,1,w+1) pw3[i]=pw3[i-1]*3;
    rep1(mask,pw3[w]){
        int tmp=mask;
        rep(w){
            a[i]=tmp%3;
            tmp/=3;
        }
        bool flag=0;
        rep3(i,w-1,0) if(a[i]==2){
            dp[mask]=dp[mask-pw3[i]]+dp[mask-pw3[i]*2];
            flag=1;
            break;
        }
        if(!flag){
            int k=0;
            rep(w) if(a[i]) k+=pow2(i);
            dp[mask]=cnt[k];
        }
        bug(mask,dp[mask]);
        if(mask==362) rep(w) bug(a[i]);
    }
    while(q--){
        string str;
        cin >> str;
        reverse(all(str));
        rep(w) a[i]=0;
        int curmask=0;
        bad=0;
        rep(w){
            if(!f(str[i],0,0)) a[i]++;
            if(!f(str[i],0,1)) a[i]+=2;
            a[i]--;
            if(a[i]==-1) bad++;
            else curmask+=a[i]*pw3[i];
        }
        int res=0;
        rep1(mask,pow2(w)){
            if(!bad) res+=cnt[mask]*dp[curmask];
            bug(mask,curmask,res);
            if(mask+1==pow2(w)) break;
            rep(w){
                int x=mask>>i&1;
                if(a[i]==-1) bad--;
                else curmask-=a[i]*pw3[i];
                a[i]=0;
                if(!f(str[i],0,x^1)) a[i]++;
                if(!f(str[i],1,x^1)) a[i]+=2;
                a[i]--;
                if(a[i]==-1) bad++;
                else curmask+=a[i]*pw3[i];
                if(x^1) break;
            }
        }
        print(res);
    }
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