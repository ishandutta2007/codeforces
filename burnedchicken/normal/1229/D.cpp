#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 2000000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...)
#endif
template<typename T> void print(T x) {cout << x << "\n";}
template<typename T, typename... S> void print(T x, S... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=200005;
//i_am_noob
int n,k,a[maxn][5],b[maxn],fact[6]={1,1,2,6,24,120},val[125][125],pos[125],ans=0;
vector<int> invf[125];
set<pii> st;

inline int f(vector<int>& vec){
    bool vis[5];
    memset(vis,0,sizeof(vis));
    int res=0,cnt;
    rep(k){
        cnt=0;
        rep1(j,k){
            if(j==vec[i]){
                vis[j]=true;
                res+=cnt*fact[k-1-i];
                break;
            }
            if(!vis[j]) cnt++;
        }
    }
    return res;
}

template <int maxn>
struct dsu{
    int fa[maxn],siz[maxn];
    dsu(){rep(maxn) fa[i]=i,siz[i]=1;}
    void init(int _n){rep(_n) fa[i]=i,siz[i]=1;}
    int Find(int _x){return fa[_x]==_x?_x:fa[_x]=Find(fa[_x]);}
    void Union(int _x, int _y){
        int _a=Find(_x),_b=Find(_y);
        if(_a==_b) return;
        if(siz[_a]<siz[_b]) swap(_a,_b);
        fa[_b]=_a;
        siz[_a]+=siz[_b];
    }
};
dsu<125> d;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    rep(n) rep1(j,k) cin >> a[i][j];
    rep(k) invf[0].pb(i);
    rep2(i,1,fact[k]){
        invf[i]=invf[i-1];
        next_permutation(all(invf[i]));
    }
    rep(fact[k]) rep1(j,fact[k]){
        vector<int> vec=invf[j];
        vector<int> vec1(k);
        rep1(ii,k) vec1[invf[i][ii]]=invf[j][ii];
        val[i][j]=f(vec1);
    }
    rep(n) rep1(j,k) a[i][j]--;
    rep(n){
        vector<int> vec;
        rep1(j,k) vec.pb(a[i][j]);
        b[i]=f(vec);
    }
    st.insert({n,-1});
    rep(fact[k]) pos[i]=-1;
    rep3(i,n-1,0){
        if(pos[b[i]]!=-1) st.erase({pos[b[i]],b[i]});
        pos[b[i]]=i;
        st.insert({i,b[i]});
        d.init(fact[k]);
        int cur=1;
        for(auto it=st.begin(); it!=st.end(); it++){
            if(next(it)==st.end()) break;
            int x=(*it).first,y=(*it).second;
            if(d.Find(0)!=d.Find(val[y][0])) rep1(j,fact[k]) d.Union(j,val[y][j]);
            cur=d.siz[d.Find(0)];
            ans+=((*next(it)).first-x)*cur;
        }
    }
    print(ans);
    return 0;
}