#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

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
    int fac_cnt(int x){
        assert(x>=1&&x<maxn);
        int res=1,lst=0,cur=0;
        while(x>1){
            int p=lpd[x];
            if(p!=lst) res*=cur+1,cur=0;
            cur++;
            lst=p;
            x/=p;
        }
        return res*(cur+1);
    }
    vector<int> pfactors(int x){
        assert(x>=1&&x<maxn);
        vector<int> res;
        while(x>1){
            res.pb(lpd[x]);
            x/=lpd[x];
        }
        return res;
    }
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=200005,maxm=7777714,maxk=7777714;
    
//i_am_noob
#define wiwihorz  
NT<1000005> nt;
int n,k,a[maxn];
vector<int> vec[maxn];

void orzck(){
    cin >> n >> k;
    rep(n) cin >> a[i];
    rep(n) vec[i].clear();
    rep(n) vec[i%k].pb(a[i]);
    int res=0;
    rep1(j,k){
        vector<int> val(sz(vec[j]));
        rep(sz(vec[j])){
            if(vec[j][i]==1){
                if(i==0) val[i]=0;
                else val[i]=val[i-1];
                res+=val[i];
            }
            else if(!nt.isp(vec[j][i])){
                val[i]=0;
            }
            else{
                val[i]=1;
                rep3(ii,i-1,0){
                    if(vec[j][ii]!=1) break;
                    val[i]++;
                }
                res+=val[i];
                res--;
            }
        }
    }
    print(res);
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