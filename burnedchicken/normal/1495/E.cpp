#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=5000005;
//i_am_noob
//#define wiwihorz  
int n,m,seed,base,ret,p[200005],k[200005],b[200005],w[200005],a[maxn],minn[maxn],ans[maxn],cur,minn2,x,res;
bool t[maxn];

void hhhhauraorz(){
    cin >> n >> m;
    rep2(i,1,m+1) cin >> p[i] >> k[i] >> b[i] >> w[i];
    seed=base=ret=0;
    auto rnd=[](){
        ret=seed;
        seed=(seed*base+233)%MOD;
        return ret;
    };
    p[0]=0;
    rep2(i,1,m+1){
        seed=b[i],base=w[i];
        rep2(j,p[i-1],p[i]){
            t[j]=rnd()%2;
            a[j]=rnd()%k[i]+1;
        }
    }
    int sum0=0,sum1=0;
    bool win;
    //rep(n) bug(t[i],a[i]);
    rep(n){
        if(t[i]) sum1+=a[i];
        else sum0+=a[i];
    }
    if(sum1>sum0) win=1;
    else win=0;
    if(t[0]==win) a[0]--;
    cur=minn[n]=0;
    rep3(i,n-1,0){
        cur+=t[i]==win?a[i]:-a[i];
        minn[i]=min(minn[i+1],cur);
    }
    cur=minn2=0;
    rep(n){
        if(t[i]==win){
            x=min(minn2,cur+minn[i+1]);
            if(x>=0) ans[i]=a[i];
            else if(x<=-a[i]) ans[i]=0;
            else ans[i]=a[i]+x;
        }
        cur+=t[i]==win?a[i]:-a[i];
        minn2=min(minn2+(t[i]==win?a[i]:-a[i]),0ll);
    }
    //rep(n) bug(ans[i]);
    int tot=0;
    rep(n) tot+=ans[i];
    bug(win,t[0]);
    bug(sum0,sum1,tot,sum1+tot);
    if(t[0]==win) ans[0]=(a[0]+1)-ans[0];
    else ans[0]=a[0]-ans[0];
    rep2(i,1,n) ans[i]=a[i]-ans[i];
    res=1;
    rep(n) res=res*(((ans[i]^((i+1)*(i+1)))+1)%MOD)%MOD;
    print(res);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}