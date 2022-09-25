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
const int maxn=105;

//i_am_noob
//#define wiwihorz  
int n,m,a[maxn],b[maxn],ans[3];

void orzck(){
    cin >> n >> m;
    rep(n) cin >> a[i];
    rep2(s,2,2*m+1){
        rep(n) b[i]=a[i]%s;
        sort(b,b+n);
        rep(n) bug(b[i]);
        b[n]=s-1;
        if(s%2==0){
            rep(n+1) if(b[i]>=s/2){
                if((n-i)&1) ans[1]++;
                else ans[2]++;
                break;
            }
        }
        int l=(s+2)/2;
        rep(n+1) if(b[i]>=l){
            int r=min(b[i],m);
            if((n-i)&1){
                int k=inf;
                if(n>=2) chkmin(k,s-b[n-2]/2-1);
                if(i) chkmin(k,s-b[i-1]-1);
                ans[1]+=max(0ll,2*(min(k,r)-l+1));
                ans[0]+=max(0ll,r-max(k+1,l)+1);
            }
            else{
                int k=inf;
                if(n>=1) chkmin(k,s-b[n-1]/2-1);
                if(i) chkmin(k,s-b[i-1]-1);
                ans[2]+=max(0ll,2*(min(k,r)-l+1));
                ans[0]+=max(0ll,r-max(k+1,l)+1);
            }
            
            l=r+1;
        }
    }
    print(ans[0],ans[0],ans[1],ans[2]);
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