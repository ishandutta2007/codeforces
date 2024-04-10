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

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=100005,maxm=10000005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,x[maxn],y[maxn],c[maxn],res;
int cntr[maxn][3];//# of cells with color j in ith row
int cntc[maxn][3];
vector<int> vec[3];

void solve(){
    rep(n) rep1(j,3) cntr[i][j]=cntc[i][j]=0;
    rep(n) cntr[x[i]][c[i]]++,cntc[y[i]][c[i]]++;
    rep(3) vec[i].clear();
    rep(n) vec[c[i]].pb(i);
    //Case 1
    array<int,3> arr;
    rep(3) arr[i]=i;
    do{
        int l=0,r=n/3;
        while(l<r){
            int mid=l+r+1>>1;
            int cnt[3],cur=0;
            rep(3) cnt[i]=0;
            bool flag=0;
            rep(n){
                cnt[arr[cur]]+=cntr[i][arr[cur]];
                if(cnt[arr[cur]]>=mid) cur++;
                if(cur==3){
                    flag=1;
                    break;
                }
            }
            if(flag) l=mid;
            else r=mid-1;
        }
        chkmax(res,l);
        rep(3) bug(arr[i]);
        bug(l);
    }while(next_permutation(all(arr)));
    //Case 2
    int cnt1[maxn],cnt2[maxn];
    do{
        int l=0,r=n/3;
        while(l<r){
            int mid=l+r+1>>1;
            int de=0,pos=n;
            rep(n){
                de+=cntr[i][arr[0]];
                if(de>=mid){
                    pos=i+1;
                    break;
                }
            }
            memset(cnt1,0,sizeof cnt1);
            memset(cnt2,0,sizeof cnt2);
            for(auto i: vec[arr[1]]){
                if(x[i]>=pos) cnt1[y[i]]++;
            }
            for(auto i: vec[arr[2]]){
                if(x[i]>=pos) cnt2[y[i]]++;
            }
            rep(n-1) cnt1[i+1]+=cnt1[i];
            rep3(i,n-2,0) cnt2[i]+=cnt2[i+1];
            bool flag=0;
            rep(n-1) if(cnt1[i]>=mid&&cnt2[i+1]>=mid) flag=1;
            if(flag) l=mid;
            else r=mid-1;
        }
        chkmax(res,l);
    }while(next_permutation(all(arr)));
    //Case 3
    do{
        int l=0,r=n/3;
        while(l<r){
            int mid=l+r+1>>1;
            int de=0,pos=-1;
            rep3(i,n-1,0){
                de+=cntr[i][arr[0]];
                if(de>=mid){
                    pos=i-1;
                    break;
                }
            }
            memset(cnt1,0,sizeof cnt1);
            memset(cnt2,0,sizeof cnt2);
            for(auto i: vec[arr[1]]){
                if(x[i]<=pos) cnt1[y[i]]++;
            }
            for(auto i: vec[arr[2]]){
                if(x[i]<=pos) cnt2[y[i]]++;
            }
            rep(n-1) cnt1[i+1]+=cnt1[i];
            rep3(i,n-2,0) cnt2[i]+=cnt2[i+1];
            bool flag=0;
            rep(n-1) if(cnt1[i]>=mid&&cnt2[i+1]>=mid) flag=1;
            if(flag) l=mid;
            else r=mid-1;
        }
        chkmax(res,l);
    }while(next_permutation(all(arr)));
}

void orzck(){
    cin >> n;
    rep(n) cin >> x[i] >> y[i] >> c[i];
    rep(n) c[i]--;
    vector<int> vec1,vec2;
    rep(n) vec1.pb(x[i]),vec2.pb(y[i]);
    sort(all(vec1)),sort(all(vec2));
    vec1.resize(unique(all(vec1))-vec1.begin());
    vec2.resize(unique(all(vec2))-vec2.begin());
    rep(n) x[i]=lower_bound(all(vec1),x[i])-vec1.begin();
    rep(n) y[i]=lower_bound(all(vec2),y[i])-vec2.begin();
    rep(n) bug(x[i],y[i]);
    solve();
    rep(n) swap(x[i],y[i]);
    solve();
    print(res*3);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
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