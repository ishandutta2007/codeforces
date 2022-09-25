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
const int MOD=Mod;
const int maxn=200005;

//i_am_noob
#define wiwihorz  

int n,a[maxn];
vector<int> res;

void op(int x){
    int k=a[x]^a[x+1]^a[x+2];
    a[x]=a[x+1]=a[x+2]=k;
    res.pb(x);
}

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    if(accumulate(a,a+n,0ll)&1){
        print("NO");
        return;
    }
    res.clear();
    bug(n);
    int cnt=0;
    int x=-1;
    rep(n){
        if(a[i]) cnt++;
        else if(cnt%2==0){
            x=i;
            break;
        }
    }
    if(x==-1){
        rep(n-2){
            if(a[i+1]==0){
                if(a[i+2]){
                    op(i);
                    x=i;
                    break;
                }
                op(i);
            }
        }
    }
    if(x==-1){
        print("NO");
        return;
    }
    int l=x;
    while(l<n-1){
        if(a[l+1]==0){
            l++;
            continue;
        }
        if(a[l+2]==1){
            op(l);
            l+=2;
            continue;
        }
        if(a[l+3]==1){
            op(l+1);
            l+=3;
            continue;
        }
        op(l+1);
        op(l);
        l+=2;
    }
    int r=x;
    while(r){
        if(a[r-1]==0){
            r--;
            continue;
        }
        if(a[r-2]==1){
            op(r-2);
            r-=2;
            continue;
        }
        if(a[r-3]==1){
            op(r-3);
            r-=3;
            continue;
        }
        op(r-3);
        op(r-2);
        r-=2;
    }
    rep(n) bug(a[i]);
    print("YES");
    print(sz(res));
    for(auto i: res) print0(i+1);
    cout << "\n";
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