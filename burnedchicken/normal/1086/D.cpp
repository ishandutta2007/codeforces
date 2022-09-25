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
//#define wiwihorz  
template<typename T, signed N>
struct BIT{
    T val[N];
    void modify(signed x, T y){for(signed i=++x; i<N; i+=i&-i) val[i]+=y;}
    T query(signed x, signed y){
        T ret=0;
        for(signed i=++y; i; i-=i&-i) ret+=val[i];
        for(signed i=x; i; i-=i&-i) ret-=val[i];
        return ret;
    }
    signed first_true(function<bool(T,signed)> f){
        if(f(0,0)) return 0;
        signed cur=0;
        T curval=0;
        for(signed i=__lg(N); i>=0; --i) if(cur+(1<<i)<N){
            if(!f(curval+val[cur+(1<<i)],cur+(1<<i))) cur+=1<<i,curval+=val[cur];
        }
        return min(cur,N-2);
    }
};

BIT<int,maxn> bit[3];

int n,q,a[maxn],cnt[3];
string str;

void solve(){
    int res=n;
    rep(3){
        if(cnt[(i+2)%3]==0){
            if(cnt[(i+1)%3]) res-=cnt[i];
            break;
        }
        int x=bit[(i+2)%3].first_true([](int val, int pos){return val>0;});
        int y=bit[(i+1)%3].first_true([](int val, int pos){return val>0;});
        bug(i,x,y);
        if(y<=x) res-=bit[i].query(y,x);
        x=bit[(i+2)%3].first_true([&i](int val, int pos){return val>=cnt[(i+2)%3];});
        y=bit[(i+1)%3].first_true([&i](int val, int pos){return val>=cnt[(i+1)%3];});
        bug(i,x,y);
        if(x<=y) res-=bit[i].query(x,y);
        bug(i,res);
    }
    print(res);
}

void orzck(){
    cin >> n >> q >> str;
    rep(n){
        if(str[i]=='R') a[i]=0;
        else if(str[i]=='P') a[i]=1;
        else a[i]=2;
        bit[a[i]].modify(i,1);
        cnt[a[i]]++;
    }
    solve();
    while(q--){
        int x;
        char c;
        cin >> x >> c;
        x--;
        bit[a[x]].modify(x,-1);
        cnt[a[x]]--;
        if(c=='R') a[x]=0;
        else if(c=='P') a[x]=1;
        else a[x]=2;
        bit[a[x]].modify(x,1);
        cnt[a[x]]++;
        solve();
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