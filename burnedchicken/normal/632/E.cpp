#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
 
using namespace std;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
int n,k,a[maxn];
 
template <int mod>
struct modint{
    int val;
    modint(int _val=0){val=_val;}
    modint operator +(const modint& o) const {return val+o.val>=mod?modint(val+o.val-mod):modint(val+o.val);}
    modint operator -() const {return val?modint(mod-val):*this;}
    modint operator -(const modint& o) const {return val-o.val<0?modint(val-o.val+mod):modint(val-o.val);}
    modint operator *(const modint& o) const {return modint(val*o.val%mod);}
    modint operator +=(const modint& o) const {*this=(*this)+o;return *this;}
    modint operator -=(const modint& o) const {*this=(*this)-o;return *this;}
    modint Pow(const int& b){
        if(!b) return modint(1);
        modint tmp=Pow(b>>1);
        tmp=tmp*tmp;
        return (b&1?tmp*(*this):tmp);
    }
    modint Pow(const modint& a, const int& b){return a.Pow(b);}
    inline modint inv(){return (*this).Pow(mod-2);}
    modint operator /(const modint& o) const {return (*this)*(o.inv());}
    bool operator ==(const modint& o) const {return val==o.val;}
};
 
template <typename T>
struct FFT{
    int siz;
    vector<T> rt,rev_rt;
    T inv_siz;
    FFT(int _siz){
        siz=_siz;
        T x=T(3).Pow((MOD-1)>>_siz);
        rep(pow2(_siz)) rt.pb(i?rt.back()*x:1);
        rep(pow2(_siz)) rev_rt.pb(i?rt[pow2(_siz)-i]:T(1));
        inv_siz=T(pow2(siz)).inv();
    }
    void mul_matrix(vector<T>& vec, vector<T>& RT){
        vec.resize(pow2(siz));
        int rev=0;
        rep(pow2(siz)){
            if(i>rev) swap(vec[i],vec[rev]);
            for(int j=pow2(siz-1); (rev^=j)<j; j>>=1);
        }
        T tmp;
        rep2(layer,1,siz+1) for(int i=0; i<pow2(siz); i+=pow2(layer)) for(int j=i; j<i+pow2(layer-1); j++){
            tmp=RT[(j-i)<<(siz-layer)]*vec[j+pow2(layer-1)];
            vec[j+pow2(layer-1)]=vec[j]-tmp;
            vec[j]=vec[j]+tmp;
        }
    }
    void sqr(vector<T>& vec, vector<T>& ans){
        mul_matrix(vec,rt);
        ans.resize(pow2(siz));
        rep(pow2(siz)) ans[i]=vec[i]*vec[i];
        mul_matrix(ans,rev_rt);
        rep(pow2(siz)) ans[i]=ans[i]*inv_siz;
    }
    void mul(vector<T>& vec1, vector<T>& vec2, vector<T>& ans){
        mul_matrix(vec1,rt),mul_matrix(vec2,rt);
        ans.resize(pow2(siz));
        rep(pow2(siz)) ans[i]=vec1[i]*vec2[i];
        mul_matrix(ans,rev_rt);
        rep(pow2(siz)) ans[i]=ans[i]*inv_siz;
    }
};
FFT<modint<MOD>> fft(20);
vector<modint<MOD>> vec[10],tmp,ans;
 
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    rep(n) cin >> a[i];
    vec[0].resize(pow2(20));
    rep(n) vec[0][a[i]]=vec[0][a[i]]+modint<MOD>(1);
    rep(1005) if(vec[0][i].val) vec[0][i].val=1;
    rep2(i,1,10){
        tmp=vec[i-1];
        fft.sqr(tmp,vec[i]);
        rep1(j,pow2(20)) if(vec[i][j].val) vec[i][j].val=1;
    }
    ans.pb(modint<MOD>(1));
    rep(10) if(k&pow2(i)){
        tmp=ans;
        fft.mul(tmp,vec[i],ans);
        rep1(j,pow2(20)) if(ans[j].val) ans[j].val=1;
    }
    rep(pow2(20)) if(ans[i].val) print0(i);
    cout << "\n";
    return 0;
}