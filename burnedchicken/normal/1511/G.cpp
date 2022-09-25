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
//#define wiwihorz  
struct query{
    int x,l,r,id;
};

void orzck(){
    int n,m,q,a[maxn];
    bool ans[maxn];
    cin >> n >> m;
    rep(n) cin >> a[i];
    sort(a,a+n);
    cin >> q;
    query qry[maxn];
    rep(q){
        int x,y;
        cin >> x >> y;
        qry[i].x=x;
        qry[i].l=lower_bound(a,a+n,x)-a;
        qry[i].r=lower_bound(a,a+n,y+1)-a;
        qry[i].id=i;
    }
    sort(qry,qry+q,[&](query& i, query& j){return i.x!=j.x?i.x<j.x:i.r<j.r;});
    int cur=0,cur1=0,cur2=0;
    rep2(i,1,m+1){
        while(cur1<n&&i>a[cur1]) cur1++;
        cur2=cur1;
        int res=0;
        while(cur<q&&qry[cur].x==i){
            for(; cur2<qry[cur].r; ++cur2) res^=a[cur2]-i;
            ans[qry[cur].id]=res;
            cur++;
        }
    }
    rep(q) cout << (ans[i]?'A':'B');
    cout << "\n";
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
    while(t--) orzck();
    return 0;
}