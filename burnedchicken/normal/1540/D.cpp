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
const int maxn=100005;

//i_am_noob
//#define wiwihorz  

const int K=115;
int n,a[maxn];
vector<int> vec[maxn/K+5],vec2[maxn/K+5];

template<int N>
struct BIT{
    int val[N];
    void modify(int x, int y){for(int i=++x; i<N; i+=i&-i) val[i]+=y;}
    int query(int x, int y){
        int ret=0;
        for(int i=++y; i; i-=i&-i) ret+=val[i];
        for(int i=x; i; i-=i&-i) ret-=val[i];
        return ret;
    }
};

BIT<maxn> bit;

void build(int x){
    vec[x].clear(),vec2[x].clear();
    rep(K) if(x*K+i<n){
        int cur=0,curval=0;
        int tar=a[x*K+i];
        //bug(tar);
        rep3(k,16,0){
            int ncur=cur+pow2(k);
            if(ncur<n&&ncur-(curval+bit.val[ncur])<=tar) cur=ncur,curval+=bit.val[ncur]; 
        }
        //bug(cur);
        vec[x].pb(cur);
        vec2[x].pb(cur);
        bit.modify(cur,1);
    }
    sort(all(vec[x]));
    for(auto j: vec[x]) bit.modify(j,-1);
    //bug(vec[x]),bug(vec2[x]);
}

void orzck(){
    ld start=clock();
    cin >> n;
    rep(n) cin >> a[n-1-i];
    rep(n) a[i]=(n-1-i)-a[i];
    //rep(n) bug(a[i]);
    for(int i=0; i<n; i+=K){
        build(i/K);
        
    }
    bug("de");
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int x,y;
            cin >> x >> y;
            y=x-1-y;
            x=n-x;
            a[x]=y;
            build(x/K);
        }
        else{
            int x;
            cin >> x;
            x=n-x;
            int t=x/K,cur=vec2[x/K][x%K];
            rep3(i,t-1,0){
                if(vec[i][0]>cur) continue;
                int l=0,r=sz(vec[i])-1;
                while(l<r){
                    int mid=l+r+1>>1;
                    if(vec[i][mid]-mid<=cur) l=mid;
                    else r=mid-1;
                }
                cur+=l+1;
            }
            print(cur+1);
        }
    }
    bug((clock()-start)/CLOCKS_PER_SEC);
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