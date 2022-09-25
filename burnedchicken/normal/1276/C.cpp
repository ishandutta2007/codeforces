#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

#define int long long
#define ull unsigned long long
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxn=400005;
//i_am_noob
int n,k,a[maxn],maxx=-inf,maxid,p,q,curx,cury;
map<int,int> mm;
vector<int> vec[1000];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n;
    rep(n){
        cin >> k;
        mm[k]++;
    }
    for(auto& [x,y]: mm) a[y]++;
    rep3(i,n-1,1) a[i]+=a[i+1];
    rep2(i,2,n+1) a[i]+=a[i-1];
    rep2(i,1,n+1){
        if(i*i>a[i]) break;
        if(a[i]/i*i>maxx) maxx=a[i]/i*i,maxid=i;
    }
    p=maxid,q=a[maxid]/maxid;
    print(p*q);
    print(p,q);
    rep(p) vec[i].resize(q);
    for(auto& [x,y]: mm) if(y>=p){
        rep(p) vec[i][(i+curx)%q]=x;
        curx++;
    }
    for(auto& [x,y]: mm) if(y<p){
        bug(x,y);
        rep(y) if(curx<q){
            bug(curx,cury);
            vec[cury][(curx+cury)%q]=x;
            cury++;
            if(cury==p) curx++,cury=0;
        }
    }
    rep(p){
        for(auto j: vec[i]) print0(j);
        cout << "\n";
    }
    return 0;
}