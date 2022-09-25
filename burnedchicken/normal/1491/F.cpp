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
#define inf 1010000000
//#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=2005;
//i_am_noob
#define wiwihorz  
int n,x,y,val,l,r,mid;
vector<int> vec1,vec2,ans;

int query(vector<int>& vec1, vector<int>& vec2){
    print("?",sz(vec1),sz(vec2));
    for(auto i: vec1) print0(i+1);
    cout << "\n";
    for(auto i: vec2) print0(i+1);
    cout << "\n";
    cout << flush;
    int res;
    cin >> res;
    return res;
}

void hhhhauraorz(){
    cin >> n;
    x=n-1;
    rep(n-1){
        vec1={i};
        vec2.clear();
        rep2(j,i+1,n) vec2.pb(j);
        val=query(vec1,vec2);
        if(val){
            x=i;
            break;
        }
    }
    l=0,r=x;
    while(l<r){
        mid=l+r>>1;
        vec1.clear();
        rep(mid+1) vec1.pb(i);
        vec2={x};
        if(query(vec1,vec2)) r=mid;
        else l=mid+1;
    }
    ans.clear();
    rep(x) if(i!=l) ans.pb(i);
    rep2(i,x+1,n-1){
        vec1={x},vec2={i};
        y=query(vec1,vec2);
        if(!y) ans.pb(i);
        val-=y;
    }
    if(x<n-1&&!val) ans.pb(n-1);
    print0("!"),print0(sz(ans));
    for(auto i: ans) print0(i+1);
    cout << endl;
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