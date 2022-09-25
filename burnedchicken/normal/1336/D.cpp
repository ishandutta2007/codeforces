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
const int maxn=105;

//i_am_noob
//#define wiwihorz  
int n,x,y,a[maxn],b[maxn];
vector<int> vec1,vec2;

void query(int k){
    print("+",k+1);
    cout << flush;
    int a,b;
    cin >> a >> b;
    vec1.pb(a-x),vec2.pb(b-y);
    x=a,y=b;
}

void orzck(){
    cin >> n >> x >> y;
    query(0);
    rep3(i,n-2,0) query(i);
    rep2(i,1,105) if(vec1.back()==i*(i-1)/2){
        a[0]=i-1;
        break;
    }
    int val1=vec2[0],val2=vec2.back()-vec2[0]-1;
    int rt1=(val2+round(sqrt(val2*val2-4*val1)))/2;
    int rt2=val2-rt1;
    assert(rt1*rt2==val1);
    bool flag=1;
    rep1(_,2){
        if(_) a[1]=rt1,a[2]=rt2;
        else a[1]=rt2,a[2]=rt1;
        rep(n-1) b[i]=1;
        b[n-1]=0;
        rep2(i,3,n){
            int val=vec2[n-i+1];
            b[i-2]=0;
            if(i>=4) val-=(a[i-4]+b[i-4])*(a[i-3]+b[i-3]);
            val-=(a[i-3]+b[i-3])*(a[i-1]+b[i-1]);
            if(val%(a[i-1]+b[i-1])){
                flag=0;
                break;
            }
            a[i]=val/(a[i-1]+1)-b[i];
            if(a[i]<0||a[i]>n){
                flag=0;
                break;
            }
        }
        if((a[n-4]+b[n-4])*(a[n-3]+b[n-3])+(a[n-3]+b[n-3])*(a[n-1]+b[n-1])!=vec2[1]) flag=0;
        if(flag) break;
        rep(n) bug(a[i]);
    }
    print0("!");
    rep(n) print0(a[i]);
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    //freopen("input1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    //freopen("output2.txt","w",stderr);
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