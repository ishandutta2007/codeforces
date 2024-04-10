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
const int maxn=300005;

//i_am_noob
#define wiwihorz  

int bal,l,r,cnt,hidden,MAX=100000000000000;

bool query(int x){
    cnt++;
    if(cnt>=1000) exit(0);
    #ifdef i_am_noob
    //print("?",x);
    if(x<=hidden) bal+=x;
    else bal-=x;
    if(bal<0){
        print("de");
        exit(0);
    }
    return x<=hidden;
    #else
    print("?",x);
    cout << flush;
    string str;
    cin >> str;
    if(str[1]=='i') exit(0);
    if(str[1]=='u') bal+=x;
    else bal-=x;
    return str[1]=='u';
    #endif
}

void Report(int x){
    #ifdef i_am_noob
    if(x!=hidden){
        print("DE");
        exit(0);
    }
    print(cnt);
    if(cnt>105) bug("DE");
    #else
    print("!",x);
    cout << flush;
    #endif
}

int findVal(int l, int r, int bal){
    if(r==l+1) return r;
    ld L=0,R=1;
    R/=2;
    rep1(_,50){
        ld MID=(L+R)/2;
        int k=0,dbal=0;
        int tmp=r;
        while(r>l){
            r=ceil(l+(r-l)*MID)+eps;
            k++;
            dbal-=r;
            r--;
        }
        r=tmp;
        while(bal+dbal<0) dbal+=l,k++;
        if(cnt+k>=104) R=MID;
        else L=MID;
    }
    //print(L);
    return max(ceil(l+(r-l)*L)+eps,(ld)l+1);
}

void orzck(){
    #ifdef i_am_noob
    cin >> hidden;
    #endif
    bal=1;
    cnt=0;
    rep(47){
        if(!query(pow2(i))){
            if(i==0){
                Report(0);
                return;
            }
            l=pow2(i-1);
            r=pow2(i)-1;
            break;
        }
        if(i==46) l=pow2(46),r=MAX;
    }
    while(l<r){
        //print(l,r);
        int mid=findVal(l,r,bal);
        while(bal<mid) query(l);
        if(query(mid)) l=mid;
        else r=mid-1;
    }
    Report(l);
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