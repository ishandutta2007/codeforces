#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

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
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int maxn=100005;

//i_am_noob
//#define wiwihorz  
int n,m,a[maxn],val1,val2;
set<pii> st;

bool check(int x, int d){
    bug(x,d);
    if(!d) return 0;
    if(m<10){
        rep(n){
            int y=(x+i*d)%m;
            if(!binary_search(a,a+n,y)) return 0;
        }
        return 1;
    }
    if((n*x+n*(n-1)/2%m*d)%m!=val1) return 0;
    if((n*x%m*x+n*(n-1)%m*x%m*d+n*(n-1)*(2*n-1)/6%m*d%m*d)%m!=val2) return 0;
    if(st.count({x,d})) return 0;
    st.insert({x,d});
    rep(n){
        int y=(x+i*d)%m;
        if(!binary_search(a,a+n,y)) return 0;
    }
    return 1;
}

int Pow(int x, int y){
    int res=1;
    while(y){
        if(y&1) res=res*x%m;
        x=x*x%m,y>>=1;
    }
    return res;
}

void orzck(){
    cin >> m >> n;
    rep(n) cin >> a[i];
    sort(a,a+n);
    rep(n) val1=(val1+a[i])%m;
    rep(n) val2=(val2+a[i]*a[i])%m;
    bug(val1,val2);
    if(m==n){
        print(0,1);
        return;
    }
    if(m==n+1){
        rep(n-1) if(a[i+1]!=a[i]+1){
            print(a[i+1],1);
            return;
        }
        if(a[0]==0) print(0,1);
        else print(1,1);
        return;
    }
    if(n==1){
        print(a[0],1);
        return;
    }
    int invn=Pow(n,m-2);
    int t=Pow(n-1,m-2)*2%m;
    rep(n){
        int x=a[i];
        int d=(val1*invn-x+m)%m*t%m;
        if(check(x,d)){
            print(x,d);
            return;
        }
    }
    print(-1);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}