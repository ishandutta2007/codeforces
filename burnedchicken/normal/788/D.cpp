#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
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
const int maxn=10005;

//i_am_noob
//#define wiwihorz  

int n,m,a[maxn],b[maxn];
vector<int> vec1,vec2,res1,res2;
map<int,int> m1,m2;
ykh;
uniform_int_distribution<int> dis(-100000000,100000000),dis2(-100000000,100000000);

int query(int x, int y){
    static int cnt=300000;
    //if(cnt==0) assert(0);
    cnt--;
    int res;
    #ifdef i_am_noob
    res=inf;
    res=min(res,*lower_bound(a,a+n+2,x)-x);
    res=min(res,x-*(upper_bound(a,a+n+2,x)-1));
    res=min(res,*lower_bound(b,b+m+2,y)-y);
    res=min(res,y-*(upper_bound(b,b+m+2,y)-1));
    #else
    print(0,x,y);
    cout << flush;
    cin >> res;
    #endif
    return res;
}

void getremain(){
    vec1.clear(),vec2.clear();
    int lst=-100000000,cur=0;
    for(auto [x,y]: m1){
        cur+=y;
        if(!cur) lst=x;
        else{
            rep2(i,lst,x) vec1.pb(i);
            lst=inf;
        }
    }
    rep2(i,lst,100000001) vec1.pb(i);
    lst=-100000000,cur=0;
    for(auto [x,y]: m2){
        cur+=y;
        if(!cur) lst=x;
        else{
            rep2(i,lst,x) vec2.pb(i);
            lst=inf;
        }
    }
    rep2(i,lst,100000001) vec2.pb(i);
}

void report(){
    #ifdef i_am_noob
    bool flag=1;
    if(sz(res1)!=n||sz(res2)!=m) flag=0;
    if(flag){
        rep(n) if(res1[i]!=a[i+1]) flag=0;
        rep(m) if(res2[i]!=b[i+1]) flag=0;
    }
    print(flag);
    #else
    print(1,sz(res1),sz(res2));
    cout << flush;
    rep(sz(res1)) print0(res1[i]);
    cout << endl;
    rep(sz(res2)) print0(res2[i]);
    cout << endl;
    #endif
}

void orzck(){
    #ifdef i_am_noob

    n=m=10000;
    a[0]=b[0]=-inf;
    a[n+1]=b[m+1]=inf;
    
    set<int> st;
    while(sz(st)<n) st.insert(dis2(rng));
    rep(n){
        a[i+1]=*st.begin();
        st.erase(st.begin());
    }
    st.clear();
    while(sz(st)<m) st.insert(dis2(rng));
    rep(m){
        b[i+1]=*st.begin();
        st.erase(st.begin());
    }
    #endif
    rep(150000){
        int x=dis(rng),y=dis(rng);
        int d=query(x,y);
        if(d){
            m1[x-d+1]++;
            m1[x+d]--;
            m2[y-d+1]++;
            m2[y+d]--;
        }
    }
    getremain();
    bug(sz(vec1),sz(vec2));
    rep1(_,10){
        rep(5000){
            int x=vec1[rng()%sz(vec1)],y=vec2[rng()%sz(vec2)];
            int d=query(x,y);
            if(d){
                m1[x-d+1]++;
                m1[x+d]--;
                m2[y-d+1]++;
                m2[y+d]--;
            }
        }
        getremain();
        bug(sz(vec1),sz(vec2));
    }
    int xx,yy;
    if(vec1[0]>-100000000) xx=-100000000;
    else if(vec1.back()<100000000) xx=100000000;
    else{
        rep(sz(vec1)-1) if(vec1[i+1]>vec1[i]+1){
            xx=vec1[i]+1;
            break;
        }
    }
    if(vec2[0]>-100000000) yy=-100000000;
    else if(vec2.back()<100000000) yy=100000000;
    else{
        rep(sz(vec2)-1) if(vec2[i+1]>vec2[i]+1){
            yy=vec2[i]+1;
            break;
        }
    }
    for(auto i: vec1){
        /*
        bool flag=1;
        rep1(_,3) if(query(i,dis(rng))){
            flag=0;
            break;
        }
        */
        if(!query(i,yy)) res1.pb(i);
    }
    for(auto i: vec2){
        /*
        bool flag=1;
        rep1(_,3) if(query(dis(rng),i)){
            flag=0;
            break;
        }
        */
        if(!query(xx,i)) res2.pb(i);
    }
    bug(sz(res1),sz(res2));
    report();
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
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