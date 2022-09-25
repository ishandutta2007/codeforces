#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=200005;
//i_am_noob
//#define wiwihorz 
int n,q,a[maxn],lpd[5100000],ans[1100000],cur,y,maxpos[15];
vector<int> pr;
vector<pii> vec[5100000];

struct Query{int l,r,id;}qry[1100000];

void hhhhauraorz(){
    lpd[0]=lpd[1]=0;
    rep2(i,2,5100000){
        if(!lpd[i]){
            lpd[i]=i;
            pr.pb(i);
        }
        for(auto p: pr){
            if(p*i>=5100000) break;
            lpd[p*i]=p;
            if(i%p==0) break;
        }
    }
    cin >> n >> q;
    rep(n) cin >> a[i];
    rep(q) cin >> qry[i].l >> qry[i].r;
    rep(q) qry[i].l--,qry[i].r--,qry[i].id=i;
    sort(qry,qry+q,[](Query& i, Query& j){return i.r<j.r;});
    vector<int> vec1;
    int x;
    rep(15) maxpos[i]=-1;
    rep(n){
        vec1.clear();
        for(int j=a[i]; j>1; j/=lpd[j]){
            if(vec1.empty()||vec1.back()!=lpd[j]) vec1.pb(lpd[j]);
            else vec1.pop_back();
        }
        for(auto j: vec1) bug(j);
        bug("a");
        rep1(mask,pow2(sz(vec1))){
            x=1;
            rep1(j,sz(vec1)) if(mask&pow2(j)) x*=vec1[j];
            y=__builtin_popcountll(mask);
            for(auto& [c,d]: vec[x]) maxpos[c+sz(vec1)-2*y]=max(maxpos[c+sz(vec1)-2*y],d);
            while(sz(vec[x])&&vec[x].back().first>=sz(vec1)) vec[x].pop_back();
            vec[x].pb({sz(vec1),i});
        }
        while(cur<q&&qry[cur].r==i){
            rep3(j,14,0) if(maxpos[j]>=qry[cur].l) ans[qry[cur].id]=j;
            bug(qry[cur].id);
            cur++;
        }
    }
    rep(q) print(ans[i]);
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