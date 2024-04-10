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
const int maxn=200005;

//i_am_noob
#define wiwihorz  

template<int maxn>
struct NT{
    vector<int> pr;
    int lpd[maxn];
    NT(){
        pr.clear();
        rep(maxn) lpd[i]=-1;
        rep2(i,2,maxn){
            if(lpd[i]==-1) lpd[i]=i,pr.pb(i);
            for(auto p: pr){
                if(p*i>=maxn) break;
                lpd[p*i]=p;
                if(i%p==0) break;
            }
        }
    }
    inline bool isp(int x){return lpd[x]==x;}
};
NT<maxn> nt;
ykh;

int n,a[maxn],b[maxn];

int cnt;

int query(int x, int y){
    assert(cnt);
    cnt--;
    int res;
    #ifdef i_am_noob
    res=b[x]*b[y]/__gcd(b[x],b[y]);
    #else
    print("?",x+1,y+1);
    cout << flush;
    cin >> res;
    #endif
    return res;
}

void report(){
    #ifdef i_am_noob
    rep(n) if(a[i]!=b[i]){
        bug(i,a[i],b[i]);
        exit(0);
    }
    rep(n) print0(a[i]);
    cout << "\n";
    #else
    print0("!");
    rep(n) print0(a[i]);
    cout << endl;
    #endif
}

void orzck(){
    cin >> n;
    #ifdef i_am_noob
    rep(n) cin >> b[i];
    #endif
    cnt=n+5000;
    int maxx=0,x,y;
    rep1(_,100){
        int tmp1=rng()%n,tmp2=rng()%n;
        while(tmp1==tmp2) tmp2=rng()%n;
        int tmp=query(tmp1,tmp2);
        if(tmp>maxx) maxx=tmp,x=tmp1,y=tmp2;
    }
    bug(x,y);
    rep(n) a[i]=0;
    if(n<=4900){
        rep(n) if(i!=x&&i!=y){
            int tmp1=query(i,x),tmp2=query(i,y);
            a[i]=__gcd(tmp1,tmp2);
            a[x]=__gcd(a[x],tmp1);
            a[y]=__gcd(a[y],tmp2);
        }
        int tmp=query(x,y);
        a[x]=__gcd(a[x],tmp),a[y]=__gcd(a[y],tmp);
    }
    else{
        int k,maxx=0;
        rep1(_,2000){
            int tmp=rng()%n;
            while(tmp==x||tmp==y||a[tmp]) tmp=rng()%n;
            int tmp1=query(tmp,x),tmp2=query(tmp,y);
            a[tmp]=__gcd(tmp1,tmp2);
            if(nt.isp(a[tmp])&&a[tmp]>maxx){
                k=tmp;
                maxx=a[tmp];
            }
        }
        rep(n) if(i!=k){
            int tmp=query(i,k);
            a[i]=tmp/a[k];
        }
    }
    int l,r;
    l=*min_element(a,a+n),r=*max_element(a,a+n);
    if(n==3){
        rep(n) if(a[i]>l+2) a[i]/=2;
        l=*min_element(a,a+n),r=*max_element(a,a+n);
    }
    bug(l,r);
    assert(r-l+1==n);
    report();
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