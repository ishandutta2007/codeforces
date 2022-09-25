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

const int maxn=300005;

//i_am_noob
//#define wiwihorz  
int n,k,cnt[maxn];
bool isp[maxn],de[maxn];

void orzck(){
    cin >> n >> k;
    rep2(i,2,n+1) isp[i]=1;
    rep2(i,2,n+1) if(isp[i]) for(int j=i*2; j<=n; j+=i) isp[j]=0;
    rep2(i,1,n+1) for(int j=i*2; j<=n; j+=i) cnt[j]++;
    int cur=0,x=n;
    rep2(i,1,n+1){
        cur+=cnt[i];
        if(cur>=k){
            x=i;
            break;
        }
    }
    if(cur<k){
        print("No");
        return;
    }
    rep2(i,1,x+1) de[i]=1;
    rep2(i,1,x+1) if(isp[i]&&cur-x/i>=k) de[i]=0,cur-=x/i;
    assert(cur==k);
    vector<int> res;
    rep2(i,1,x+1) if(de[i]) res.pb(i);
    print("Yes");
    print(sz(res));
    for(auto i: res) print0(i);
    cout << "\n";
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