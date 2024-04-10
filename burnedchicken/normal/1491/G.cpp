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
const int maxn=200005;
//i_am_noob
//#define wiwihorz  
int n,to[maxn];
bool a[maxn],vis[maxn];
vector<int> vec,vec1,vec2;
vector<pii> res;

void Swap(int x, int y){
    swap(to[x],to[y]);
    a[x]^=1,a[y]^=1;
    res.pb({to[x]+1,to[y]+1});
}

void hhhhauraorz(){
    cin >> n;
    rep(n){
        int x;
        cin >> x;
        to[x-1]=i;
    }
    rep(n){
        if(vis[i]) continue;
        vis[i]=true;
        if(to[i]==i) continue;
        vec.pb(i);
        for(int j=to[i]; j!=i; j=to[j]) vis[j]=true;
    }
    rep(sz(vec)/2){
        int x=vec[2*i],y=vec[2*i+1];
        Swap(x,y);
        vec1.clear(),vec2.clear();
        for(int j=to[x]; j!=y; j=to[j]) vec1.pb(j);
        vec1.pb(y);
        for(int j=to[y]; j!=x; j=to[j]) vec2.pb(j);
        vec2.pb(x);
        rep3(j,sz(vec1)-2,0) Swap(vec1[j],vec1[j+1]);
        rep3(j,sz(vec2)-2,0) Swap(vec2[j],vec2[j+1]);
        Swap(vec1[0],vec2[0]);
    }
    if(sz(vec)&1){
        int x=vec.back();
        vec1={x};
        for(int i=to[x]; i!=x; i=to[i]) vec1.pb(i);
        if(sz(vec1)==2){
            int y;
            rep(n) if(i!=x&&i!=vec1[1]){
                y=i;
                break;
            }
            Swap(y,x);
            Swap(x,vec1[1]);
            Swap(y,vec1[1]);
        }
        else{
            Swap(x,vec1.back());
            Swap(x,vec1[1]);
            rep3(i,sz(vec1)-2,2) Swap(vec1[i],vec1[i+1]);
            Swap(x,vec1[2]);
            Swap(x,vec1[1]);
        }
    }
    print(sz(res));
    for(auto& [x,y]: res) print(x,y);
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