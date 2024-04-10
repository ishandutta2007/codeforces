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
int n,sum1[maxn],sum2[maxn];
string str1,str2;
vector<pii> res;

bool add(int x){
    if(sum1[x+2]-sum1[x+1]==0) return 0;
    if(sum1[x+1]-sum1[x]==9) return 0;
    sum1[x+1]++;
    if(sz(res)<100000) res.pb({x+1,(x&1)?-1:1});
    return 1;
}

bool sub(int x){
    if(sum1[x+1]-sum1[x]==0||(x==0&&sum1[x+1]-sum1[x]==1)) return 0;
    if(sum1[x+2]-sum1[x+1]==9) return 0;
    sum1[x+1]--;
    if(sz(res)<100000) res.pb({x+1,(x&1)?1:-1});
    return 1;
}

void orzck(){
    cin >> n >> str1 >> str2;
    rep(n){
        if(i&1){
            sum1[i+1]=sum1[i]+('9'-str1[i]);
            sum2[i+1]=sum2[i]+('9'-str2[i]);
        }
        else{
            sum1[i+1]=sum1[i]+(str1[i]-'0');
            sum2[i+1]=sum2[i]+(str2[i]-'0');
        }
    }
    if(sum1[n]!=sum2[n]){
        print(-1);
        return;
    }
    int tot=0;
    rep2(i,1,n) tot+=abs(sum1[i]-sum2[i]);
    rep2(i,1,n) while(sum1[i]!=sum2[i]&&sz(res)<100000){
        if(sum1[i]>sum2[i]){
            rep2(j,i,n) if(sub(j-1)){
                rep3(k,j-1,i) sub(k-1);
                break;
            }
        }
        else{
            rep2(j,i,n) if(add(j-1)){
                rep3(k,j-1,i) add(k-1);
                break;
            }
        }
    }
    print(tot);
    for(auto [x,y]: res) print(x,y);
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