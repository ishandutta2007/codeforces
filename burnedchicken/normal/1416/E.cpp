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

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val%mod;if(val<0) val+=mod;}
    Modint operator +(const Modint& o) const {
        Modint res;
        res.val=val+o.val;
        if(res.val>=mod) res.val-=mod;
        return res;
    }
    Modint operator +(const int& o) const {return Modint(val+o);}
    Modint operator -() const {
        Modint res;
        res.val=-val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const Modint& o) const {
        Modint res;
        res.val=val-o.val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const int& o) const {return Modint(val-o);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val);}
    Modint operator *(const int& o) const {return Modint(val*(o%mod));}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    Modint operator /(const int& o) const {return *this*Modint(o).inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
template<int mod>
ostream& operator << (ostream& o, Modint<mod> x){return o << x.val;}
template<int mod>
Modint<mod> operator +(const int& x, const Modint<mod>& y){return Modint<mod>(x+y.val);}
template<int mod>
Modint<mod> operator -(const int& x, const Modint<mod>& y){return Modint<mod>(x-y.val);}
template<int mod>
Modint<mod> operator *(const int& x, const Modint<mod>& y){return Modint<mod>(x%mod*y.val);}
#define modint Modint<MOD>
vector<modint> inv,fac,invfac;
void init_comb(int N){
    inv.resize(N),fac.resize(N),invfac.resize(N);
    inv[1]=1,fac[0]=1,invfac[0]=1;
    rep2(i,2,N) inv[i]=inv[MOD%i]*(MOD-MOD/i);
    rep2(i,1,N) fac[i]=fac[i-1]*i;
    rep2(i,1,N) invfac[i]=invfac[i-1]*inv[i];
}
inline modint C(int n, int m){return m>n||m<0?modint(0):fac[n]*invfac[m]*invfac[n-m];}
inline modint H(int n, int m){return C(n+m-1,n);}
template<typename T, int maxn, int type>
struct sparse{
    vector<T> val[22];
    sparse(){rep(__lg(maxn)+1) val[i].resize(max(0ll,maxn-pow2(i)+1));}
    inline T oper(T i, T j){return type?max(i,j):min(i,j);}
    void init(vector<T>& vec){
        rep(sz(vec)) val[0][i]=vec[i];
        rep2(i,1,__lg(maxn)+1) rep1(j,sz(vec)-pow2(i)+1) val[i][j]=oper(val[i-1][j],val[i-1][j+pow2(i-1)]);
    }
    T query(int l, int r){return oper(val[__lg(r-l+1)][l],val[__lg(r-l+1)][r-pow2(__lg(r-l+1))+1]);}
};
template<typename T, T(*op)(T,T), T(*e)(), signed N>
struct segtree{
    static const signed maxn=1<<__lg(N-1)+1;
    T val[maxn<<1];
    segtree(){rep(maxn<<1) val[i]=e();}
    void pull(signed k){val[k]=op(val[k<<1],val[k<<1|1]);}
    void modify(signed p, T x){
        p+=maxn;
        val[p]=x;
        for(p>>=1; p; p>>=1) pull(p);
    }
    T query(signed l, signed r){
        T resl=e(),resr=e();
        l+=maxn,r+=maxn+1;
        while(l<r){
            if(l&1) resl=op(resl,val[l++]);
            if(r&1) resr=op(val[--r],resr);
            l>>=1,r>>=1;
        }
        return op(resl,resr);
    }
};
const int maxn=500005,maxm=100005,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,a[maxn],val[maxn],dp[maxn];
sparse<int,maxn/2,1> sp1;//max
sparse<int,maxn/2,0> sp0;//min
int op(int x, int y){return max(x,y);}
int e(){return -inf;}
segtree<int,op,e,maxn> tree;
vector<int> vec;
int level[maxn],lst[maxn];
set<pii> best;
vector<priority_queue<signed>> pq;
vector<vector<signed>> to_erase;

bool good(int l, int r){
    int maxx=sp1.query(l/2,r/2);
    int minn=sp0.query((l+1)/2,(r+1)/2);
    return -maxx+minn>=0;
}

bool good(int l, int r, int x){
    bug(l,r,x);
    int maxx=sp1.query(l/2,r/2);
    int minn=sp0.query((l+1)/2,(r+1)/2);
    bug(maxx,minn);
    return -maxx>=x&&x>=-minn;
}

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    pq.resize(n+1);
    to_erase.resize(n+1);
    rep(n){
        a[i]-=2;
        val[i]=-1;
        tree.modify(i,0);
        while(!pq[i].empty()) pq[i].pop();
        to_erase[i].clear();
        level[i]=0;
        lst[i]=-1;
    }
    tree.modify(n,0);
    while(!pq[n].empty()) pq[n].pop();
    to_erase[n].clear();
    level[n]=0;
    lst[n]=-1;
    vector<int> vec0,vec1;
    vec0.pb(0);
    int cur=0;
    vec.clear();
    rep(n){
        cur=a[i]-cur;
        if(i&1) vec0.pb(cur);
        else vec1.pb(-cur);
        if(a[i]%2==0){
            if(i&1) val[i]=a[i]/2-cur;
            else val[i]=-a[i]/2+cur;
            vec.pb(val[i]);
        }
        bug(i,cur);
    }
    bug(vec0),bug(vec1);
    sp0.init(vec0),sp1.init(vec1);
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    rep(n) if(a[i]%2==0) val[i]=lower_bound(all(vec),val[i])-vec.begin();
    dp[0]=0;
    best.clear();
    rep(n){
        bug(i);
        int res=-inf;
        int l=0,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(good(mid,i)) r=mid;
            else l=mid+1;
        }
        chkmax(res,tree.query(l,i)-1);
        for(auto j: to_erase[i]) if(!pq[j].empty()){
            bug(j);
            best.erase({(pq[j].top())+level[j],j});
            while(!pq[j].empty()) pq[j].pop();
            level[j]=0;
        }
        bug(i);
        if(a[i]%2==0){
            bug(i,val[i],vec[val[i]]);
            int l=lst[val[i]]+1,r=i;
            while(l<r){
                int mid=l+r>>1;
                if(good(mid,i,vec[val[i]])) r=mid;
                else l=mid+1;
            }
            bug(l,i,tree.query(l,i),level[val[i]]);
            if(!pq[val[i]].empty()) best.erase({(pq[val[i]].top())+level[val[i]],val[i]});
            pq[val[i]].push(tree.query(l,i)-level[val[i]]);
            level[val[i]]++;
            best.insert({(pq[val[i]].top())+level[val[i]],val[i]});
            l=i,r=n-1;
            while(l<r){
                int mid=l+r+1>>1;
                if(good(i,mid,vec[val[i]])) l=mid;
                else r=mid-1;
            }
            bug(i,l);
            if(l+1<n) to_erase[l+1].pb(val[i]);
            lst[val[i]]=i;
        }
        if(sz(best)) chkmax(res,(*best.rbegin()).first-1);
        dp[i+1]=res;
        tree.modify(i+1,res);
        bug(i+1,res);
    }
    print(n-dp[n]);
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