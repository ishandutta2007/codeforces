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
ykh;
int ans1,ans2,cnt;
const int MAX=1000000000000000000;
//const int MAX=100;
#ifdef i_am_noob
int query(int x, int y){
    cnt++;
    if(x==ans1&&y==ans2) return 0;
    bool b[3];
    rep(3) b[i]=0;
    if(x<ans1) b[0]=1;
    if(y<ans2) b[1]=1;
    if(x>ans1||y>ans2) b[2]=1;
    vector<int> vec={0,1,2};
    shuffle(all(vec),rng);
    for(auto i: vec) if(b[i]) return i+1;
    assert(0);
    return 49;
}
#else
int query(int x, int y){
    print(x,y);
    cout << flush;
    int res;
    cin >> res;
    return res;
}
#endif

void init(){
    int d=rng()%3;
    if(d==0) ans1=uniform_int_distribution<int>(1,MAX)(rng);
    if(d==1) ans1=uniform_int_distribution<int>(1,1000)(rng);
    if(d==2) ans1=uniform_int_distribution<int>(MAX-1000,MAX)(rng);
    d=rng()%3;
    if(d==0) ans2=uniform_int_distribution<int>(1,MAX)(rng);
    if(d==1) ans2=uniform_int_distribution<int>(1,1000)(rng);
    if(d==2) ans2=uniform_int_distribution<int>(MAX-1000,MAX)(rng);
    bug(ans1,ans2);
    cnt=0;
}

long double golden=(sqrt(5.0l)-1)/2;

int l1,l2,r1,r2,r3,r4;

void orzck(){
    //bug(golden);
    #ifdef i_am_noob
    init();
    l1=l2=1,r1=r2=MAX;
    #else
    int n;
    cin >> n;
    l1=l2=1,r1=r2=n;
    #endif
    //int de=0;
    while(1){
        //de++;
        //if(de>100) break;
        //bug(l1,r1,l2,r2);
        bug(r1-l1+1,r2-l2+1);
        int mid1,mid2;
        __int128 pro=1;
        pro*=r1-l1+1;
        pro*=r2-l2+1;
        ld s;
        if(min(r1-l1+1,r2-l2+1)<10){
            mid1=(l1+r1)/2;
            mid2=(l2+r2)/2;
            s=0.5;
        }
        else{
            ld L=0,R=1;
            rep1(_,49){
                ld mid=(L+R)/2;
                int k=log(min(r1-l1+1,r2-l2+1)*(1-mid)*(1-mid))/log(1/(1-mid));
                if(pow(mid,k)<1-mid) L=mid;
                else R=mid;
            }
            bug(L);
            s=L;
            mid1=l1+(int)((r1-l1)*(1-L));
            mid2=l2+(int)((r2-l2)*(1-L));
        }
        int t=query(mid1,mid2);
        bug(t);
        //bug(mid1,mid2,t);
        if(t==0){
            #ifdef i_am_noob
            print("number of queries used:",cnt);
            #endif
            return;
        }
        if(t==1) l1=mid1+1;
        else if(t==2) l2=mid2+1;
        else{
            r3=r1,r4=r2;
            r1=mid1-1;
            r4=mid2-1;
            while(1){
                if(r1<l1){
                    r1=r3,r2=r4;
                    break;
                }
                if(r4<l2){
                    break;
                }
                mid1=l1+(int)((r1-l1)*s);
                mid2=l2+(int)((r4-l2)*s);
                t=query(mid1,mid2);
                if(t==0){
                    #ifdef i_am_noob
                    print("number of queries used:",cnt);
                    #endif
                    return;
                }
                if(t==1) l1=mid1+1;
                else if(t==2) l2=mid2+1;
                else r1=mid1-1,r4=mid2-1;
            }
        }
    }
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