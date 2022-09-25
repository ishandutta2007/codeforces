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
//#define wiwihorz  
int n,k,old,x,cnt[maxn],res;

void orzck(){
    cin >> n >> k;
    if(n%2==1&&k%2==0){
        print(-1);
        return;
    }
    bool rev=false;
    old=k;
    if(n==k) x=1;
    else if(2*k==n) x=2;
    else if((n+k)%2){
        x=max(ceiling(n,n-k),ceiling(n,k));
        if(x%2==1) x++;
    }
    else{
        x=max(3ll,ceiling(n,k));
        if(x%2==0) x++;
        if(k%2==0){
            int y=max(ceiling(n,n-k),ceiling(n,k));
            if(y%2==1) y++;
            chkmin(x,y);
        }
    }
    rep(n) cnt[i]=1;
    rep((x*k-n)/2) cnt[i%n]+=2;
    bug(x);
    rep(n) bug(cnt[i]);
    rep1(_,x){
        vector<int> vec1;
        int tmp[n+5];
        rep(n) tmp[i]=i;
        sort(tmp,tmp+n,[](int i1, int i2){return cnt[i1]>cnt[i2];});
        if(rev){
            rep(n-k) vec1.pb(tmp[i]);
        }
        else rep(k) vec1.pb(tmp[i]);
        rep(k) cnt[tmp[i]]--;
        print0("?");
        for(auto i: vec1) print0(i+1);
        cout << endl;
        int tmp2;
        cin >> tmp2;
        res^=tmp2;
    }
    print("!",res);
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