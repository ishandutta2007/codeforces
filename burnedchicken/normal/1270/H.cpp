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
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
const int maxn=500005;

//i_am_noob
//#define wiwihorz  
const int K=3005;
int n,q,a[maxn],minb[maxn/K+5],maxb[maxn/K+5],minb1[maxn/K+5],maxb1[maxn/K+5],mins[maxn/K+5][K+5],maxs[maxn/K+5][K+5],siz[maxn/K+5],sum[maxn/K+5][K+5],l[maxn/K+5],r[maxn/K+5];
set<int> st[maxn/K+5];

void calcb(int x){
    minb1[0]=inf;
    rep2(i,x,n/K+1) minb1[i+1]=min(minb1[i],minb[i]);
    maxb1[n/K+1]=-inf;
    rep3(i,x,0) maxb1[i]=max(maxb1[i+1],maxb[i]);
}

void calcs1(int x){
    minb[x]=*st[x].begin(),maxb[x]=*st[x].rbegin();
}

void calcs2(int x){
    mins[x][0]=inf;
    rep1(j,siz[x]) mins[x][j+1]=min(mins[x][j],a[x*K+j]);
    maxs[x][siz[x]]=-inf;
    rep3(j,siz[x]-1,0) maxs[x][j]=max(maxs[x][j+1],a[x*K+j]);
    sum[x][0]=sum[x][1]=0;
    rep2(j,1,siz[x]) sum[x][j+1]=sum[x][j]+(mins[x][j]>maxs[x][j]);
    sum[x][siz[x]+1]=sum[x][siz[x]];
}

void orzck(){
    cin >> n >> q;
    rep(n) cin >> a[i];
    rep(n/K+1){
        rep1(j,K) if(i*K+j<n) siz[i]++,st[i].insert(a[i*K+j]);
        calcs1(i);
        calcs2(i);
    }
    minb1[0]=inf;
    rep(n/K+1) minb1[i+1]=min(minb1[i],minb[i]);
    maxb1[n/K+1]=-inf;
    rep3(i,n/K,0) maxb1[i]=max(maxb1[i+1],maxb[i]);
    rep(n/K+1){
        r[i]=lower_bound(mins[i],mins[i]+siz[i]+1,maxb1[i+1],[&](int i1, int i2){return i1>i2;})-mins[i];
        l[i]=lower_bound(maxs[i],maxs[i]+siz[i]+1,minb1[i],[&](int i1, int i2){return i1>i2;})-maxs[i];
    }
    while(q--){
        int p,x;
        cin >> p >> x;
        p--;
        int pos=p/K;
        st[p/K].erase(a[p]);
        a[p]=x;
        st[p/K].insert(a[p]);
        calcs1(p/K);
        calcs2(p/K);
        calcb(pos);
        int res=0;
        rep2(i,1,n/K+1) if(minb1[i]>maxb1[i]) res++;
        bug(res);
        rep(n/K+1) if(minb1[i]>maxb1[i+1]){
            if(i<pos) r[i]=lower_bound(mins[i],mins[i]+siz[i]+1,maxb1[i+1],[&](int i1, int i2){return i1>i2;})-mins[i];
            if(i>pos) l[i]=lower_bound(maxs[i],maxs[i]+siz[i]+1,minb1[i],[&](int i1, int i2){return i1>i2;})-maxs[i];
            res+=sum[i][r[i]]-sum[i][l[i]];
            bug(res);
        }
        print(res+1);
    }
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