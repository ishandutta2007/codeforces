#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=1505;
//i_am_noob
int n,x,k,b[maxn];
pii a[maxn*maxn/2];
bool child[2*maxn][2*maxn];

template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
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
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define modint Modint<MOD>

template <typename T>
struct FFT{
    int siz;
    vector<T> rt,rev_rt;
    T inv_siz;
    FFT(int _siz){
        siz=_siz;
        T x=T(3).Pow((MOD-1)>>_siz);
        rep(pow2(_siz)) rt.pb(i?rt.back()*x:T(1));
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
    void mul(vector<T>& vec1, vector<T>& vec2, vector<T>& ans){
        mul_matrix(vec1,rt),mul_matrix(vec2,rt);
        ans.resize(pow2(siz));
        rep(pow2(siz)) ans[i]=vec1[i]*vec2[i];
        mul_matrix(ans,rev_rt);
        rep(pow2(siz)) ans[i]=ans[i]*inv_siz;
    }
};
FFT<modint> fft(11);
vector<modint> vec[2*maxn];

struct dsu{
    vector<int> fa,siz,deg;
    vector<vector<int>> vec;
    dsu(int _siz){
        fa.resize(_siz),siz.resize(_siz),vec.resize(_siz),deg.resize(_siz);
        rep(_siz) fa[i]=i,siz[i]=1,deg[i]=0;
        rep(_siz) vec[i].pb(i);
    }
    int Find(int _x){return fa[_x]==_x?_x:fa[_x]=Find(fa[_x]);}
    void Union(int _x, int _y){
        int _a=Find(_x),_b=Find(_y);
        if(_a==_b){
            deg[_a]++;
            if(deg[_a]==siz[_a]*(siz[_a]-1)/2){
                for(auto i: vec[_a]){
                    child[k][b[i]]=true;
                    b[i]=k;
                }
                k++;
            }
            return;
        }
        if(siz[_a]<siz[_b]) swap(_a,_b);
        fa[_b]=_a;
        siz[_a]+=siz[_b];
        for(auto i: vec[_b]) vec[_a].pb(i);
        vec[_b].clear();
        deg[_a]+=deg[_b]+1;
        if(deg[_a]==siz[_a]*(siz[_a]-1)/2){
            for(auto i: vec[_a]){
                child[k][b[i]]=true;
                b[i]=k;
            }
            k++;
        }
    }
}d(maxn);

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) rep1(j,n){
        cin >> x;
        if(i<j) a[x-1]={i,j};
    }
    rep(2*maxn) vec[i].resize(pow2(11));
    rep(2*maxn){
        if(i<n) vec[i][1]+=1;
        else vec[i][0]+=1;
    }
    rep(n) b[i]=i;
    k=n;
    rep(n*(n-1)/2) d.Union(a[i].first,a[i].second);
    rep2(i,n,k){
        rep1(j,i) if(child[i][j]) fft.mul(vec[i],vec[j],vec[i]);
        vec[i][1]+=1;
    }
    rep2(i,1,n+1) print0(vec[k-1][i]);
    cout << "\n";
    return 0;
}