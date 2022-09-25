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
const int maxn=500005,maxm=50005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,cnt[maxn],lst[maxn],res;

void orzck(){
    cin >> n;
    rep(n){
        int x;
        cin >> x;
        cnt[x]++;
    }
    rep2(i,1,maxn) cnt[i]+=cnt[i-1];
    lst[0]=-1;
    rep2(i,1,maxn){
        if(cnt[i]==cnt[i-1]) lst[i]=lst[i-1];
        else lst[i]=i;
    }
    rep2(i,2,maxn){
        int m=0,k=0;//max logs of length i
        for(int j=0; j<maxn; j+=i) m+=(cnt[min(j+i-1,maxn-1)]-(j?cnt[j-1]:0))*(j/i),k++;
        if(m<2) break;
        vector<pii> vec(k+2),suf(k+2);//2 max remainders
        vec[k].first=vec[k].second=suf[k].first=suf[k].second=-1;
        rep3(j,k-1,0){
            int maxx,maxx2;
            int cur=min(j*i+i-1,maxn-2);
            if(lst[cur]<j*i) maxx=maxx2=-1;
            else{
                cur=lst[cur];
                maxx=cur%i;
                if(cur&&cnt[cur]-cnt[cur-1]>1) maxx2=cur%i;
                else{
                    cur--;
                    if(lst[cur]<j*i) maxx2=-1;
                    else maxx2=lst[cur]%i;
                }
            }
            vec[j].first=maxx,vec[j].second=maxx2;
            suf[j].first=max(suf[j+1].first,maxx);
            suf[j].second=max(min(suf[j+1].first,maxx),max(suf[j+1].second,maxx2));
        }
        int l=1,r=min(m,maxn-2);
        while(l<r){
            int mid=l+r+1>>1;
            bool ok=0;
            //same
            if(mid*2<=maxn-2){
                int t=mid*2/i;
                int maxx=suf[t+1].first;
                if(suf[t].first>maxx&&t*i+suf[t].first>=mid*2) maxx=suf[t].first;
                if(maxx>=0&&m-ceiling(2*mid-maxx,i)>=mid) ok=1;
                bug(mid,maxx);
            }
            //different
            int t=mid/i;
            array<int,4> vals;
            vals[0]=suf[t+1].first,vals[1]=suf[t+1].second;
            if(t*i+vec[t].first>=mid) vals[2]=vec[t].first;
            else vals[2]=-1;
            if(t*i+vec[t].second>=mid) vals[3]=vec[t].second;
            else vals[3]=-1;
            int maxx=max(vals[0],vals[2]),maxx2=max(min(vals[0],vals[2]),max(vals[1],vals[3]));
            if(maxx2>=0&&m-ceiling(mid-maxx,i)-ceiling(mid-maxx2,i)>=mid) ok=1;
            if(ok) l=mid;
            else r=mid-1;
        }
        bug(i,l);
        if(l>=2) chkmax(res,i*l);
    }
    print(res);
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