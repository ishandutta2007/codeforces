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
const int maxn=200005;

//i_am_noob
#define wiwihorz  

int n,m,a[maxn],l[maxn],r[maxn],val[3],nval[3];
pii b[maxn];

void orzck(){
    cin >> n >> m;
    rep(n) cin >> a[i];
    rep(m) cin >> b[i].first >> b[i].second;
    sort(a,a+n);
    sort(b,b+m);
    vector<pii> vec;
    rep(m){
        while(sz(vec)&&b[i].second<=vec.back().second) vec.pop_back();
        vec.pb(b[i]);
    }
    m=sz(vec);
    rep(m) b[i]=vec[i];
    rep(n){
        if(b[m-1].second<a[i]){
            l[i]=m,r[i]=m;
            continue;
        }
        if(b[0].first>a[i]){
            l[i]=-1,r[i]=-1;
            continue;
        }
        int L=0,R=m-1;
        while(L<R){
            int mid=L+R>>1;
            if(b[mid].second>=a[i]) R=mid;
            else L=mid+1;
        }
        l[i]=L;
        L=0,R=m-1;
        while(L<R){
            int mid=L+R+1>>1;
            if(b[mid].first>a[i]) R=mid-1;
            else L=mid;
        }
        r[i]=L;
    }
    if(l[0]<=0) val[0]=val[1]=0;
    else val[0]=(a[0]-b[0].second)*2,val[1]=a[0]-b[0].second;
    rep(n-1){
        if(r[i]+1<l[i+1]){
            vector<int> vec1,vec2;
            vec1.pb(0);
            rep2(j,r[i]+1,l[i+1]) vec1.pb(b[j].first-a[i]);
            rep2(j,r[i]+1,l[i+1]) vec2.pb(a[i+1]-b[j].second);
            vec2.pb(0);
            nval[0]=nval[1]=inf;
            chkmin(nval[0],min(val[0]+vec1.back(),val[1]+vec1.back()*2));
            chkmin(nval[1],min(val[0],val[1])+vec2[0]);
            int minn=inf;
            rep1(j,sz(vec1)) chkmin(minn,vec1[j]+vec2[j]);
            chkmin(nval[1],val[0]+minn);
            chkmin(nval[0],val[1]+2*minn);
            minn=inf;
            rep1(j,sz(vec1)) chkmin(minn,vec1[j]*2+vec2[j]);
            chkmin(nval[1],val[1]+minn);
            minn=inf;
            rep1(j,sz(vec1)) chkmin(minn,vec1[j]+vec2[j]*2);
            chkmin(nval[0],val[0]+minn);
            rep1(j,2) val[j]=nval[j];
            bug(val[0],val[1]);
        }
        else chkmin(val[0],val[1]);
    }
    if(r[n-1]>=m-1) print(min(val[0],val[1]));
    else print(min(val[0]+b[m-1].first-a[n-1],val[1]+(b[m-1].first-a[n-1])*2));
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