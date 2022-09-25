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

const int maxn=100005,maxm=pow2(17),maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,t;
ld m;

struct line{
    int a,p;
}l[maxn];

pii inter(line a, line b){
    return {b.a*b.p-a.a*a.p,a.p-b.p};
}

bool comp(pii p1, pii p2){
    assert(p1.second&&p2.second);
    if(p1.second<0) p1.first*=-1,p1.second*=-1;
    if(p2.second<0) p2.first*=-1,p2.second*=-1;
    return (__int128(p1.first))*p2.second<(__int128(p2.first))*p1.second;
}

vector<line> stk;
vector<ld> turns;

int pos(ld x){
    int l=0,r=sz(stk)-1;
    while(l<r){
        int mid=l+r>>1;
        if(turns[mid]>x) r=mid;
        else l=mid+1;
    }
    return l;
}

void orzck(){
    cin >> n >> t;
    rep(n){
        int b;
        cin >> l[i].a >> b;
        string str;
        cin >> str;
        bool flag=0;
        int cnt=0;
        for(auto c: str){
            if(c=='.'){
                flag=1;
                continue;
            }
            if(flag){
                l[i].p=l[i].p*10+(c-'0');
                cnt++;
            }
        }
        while(cnt<9) l[i].p*=10,cnt++;
        chkmax(m,b*l[i].p/1e9l);
    }
    sort(l,l+n,[](auto i, auto j){return i.p<j.p;});
    rep(n){
        if(sz(stk)>=1&&inter(stk.back(),l[i]).second==0){
            if(stk.back().a<l[i].a) stk.pop_back(),stk.pb(l[i]);
            continue;
        }
        while(sz(stk)>=2&&comp(inter(stk.back(),l[i]),inter(stk[sz(stk)-2],stk.back()))) stk.pop_back();
        stk.pb(l[i]);
    }
    rep(sz(stk)-1){
        pii p=inter(stk[i],stk[i+1]);
        ld x=p.first;
        x/=p.second;
        turns.pb(x);
    }
    ld cur=0,maxx=m*t;
    ld fix=inf;
    rep(n) chkmin(fix,m/l[i].p*1e9l-l[i].a);
    int de=0;
    int pre=-1;
    while(t){
        int l=0,r=t;
        int curpos=pos(cur);
        if(pre!=-1&&pre==curpos) break;
        pre=curpos;
        ld X=m/stk[curpos].p*1e9l-stk[curpos].a;
        while(l<r){
            int mid=l+r+1>>1;
            ld nxt=X-(X-cur)*pow(1-stk[curpos].p/1e9l,mid);
            if(pos(nxt)!=curpos) r=mid-1;
            else l=mid;
        }
        cur=X-(X-cur)*pow(1-stk[curpos].p/1e9l,l);
        t-=l;
        rep1(_,5) if(t){
            int curpos=pos(cur);
            cur+=m-stk[curpos].p/1e9l*(stk[curpos].a+cur);
            t--;
        }
        de++;
    }
    print(maxx-cur);
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
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}