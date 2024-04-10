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
#define eb emplace_back
#define sort_unique(a) sort(all(a)),a.resize(unique(all(a))-a.begin())
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

const int maxn=300005,maxm=pow2(17),maxk=7777714;

//i_am_noob
//#define wiwihorz  
void balbitorz(){}
const int dx[8]={0,1,0,-1,1,1,-1,-1},dy[8]={1,0,-1,0,1,-1,1,-1};
int n,m,p,q,res=inf;
vector<vector<char>> tab;
vector<vector<int>> dis;
vector<vector<signed>> vis;
vector<vector<pii>> to;

bool valid(int x, int y){return x>=0&&x<n&&y>=0&&y<m;}

bool btw(int x, int y, int z){
    if(x>y) swap(x,y);
    return x<=z&&z<=y;
}

void orzck(){
    cin >> n >> m >> p >> q;
    tab.resize(n);
    for(auto& vec: tab) vec.resize(m);
    dis.resize(n);
    for(auto& vec: dis) vec.resize(m);
    vis.resize(n);
    for(auto& vec: vis) vec.resize(m);
    to.resize(n);
    for(auto& vec: to) vec.resize(m);
    rep(n) rep1(j,m) cin >> tab[i][j],dis[i][j]=inf,to[i][j]={-1,-1};
    rep(n) rep1(j,m) if(tab[i][j]!='.'&&tab[i][j]!='#'){
        if(tab[i][j]=='R') to[i][j]={i,j-1};
        if(tab[i][j]=='L') to[i][j]={i,j+1};
        if(tab[i][j]=='U') to[i][j]={i+1,j};
        if(tab[i][j]=='D') to[i][j]={i-1,j};
        bug(i,j,to[i][j].first,to[i][j].second);
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    rep(n) rep1(j,m) if(tab[i][j]=='.'){
        dis[i][j]=0;
        pq.push({0,i,j});
    }
    while(!pq.empty()){
        auto [d,x,y]=pq.top(); pq.pop();
        if(vis[x][y]) continue;
        vis[x][y]=1;
        rep(8){
            int nx,ny;
            if(i<4) nx=x+dx[i]*2,ny=y+dy[i]*2;
            else nx=x+dx[i],ny=y+dy[i];
            if(!valid(nx,ny)) continue;
            if(to[nx][ny].first>=0&&btw(x,nx,to[nx][ny].first)&&btw(y,ny,to[nx][ny].second)){
                int nd;
                if(i<4) nd=d+q;
                else nd=d+p;
                if(nd<dis[nx][ny]){
                    dis[nx][ny]=nd;
                    pq.push({nd,nx,ny});
                }
            }
        }
    }
    rep(n) rep1(j,m){
        rep1(ii,4){
            int ni=i+dx[ii],nj=j+dy[ii];
            if(!valid(ni,nj)) continue;
            chkmin(res,dis[i][j]+dis[ni][nj]);
        }
    }
    print(res>inf/2?-1:res);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
    cout << fixed << setprecision(15);
    ld start=clock();
    balbitorz();
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}