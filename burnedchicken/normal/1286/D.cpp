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
const int maxn=100005;
//i_am_noob
int n,x[maxn],v[maxn],p[maxn];

struct rational{
    int nu,de;
    rational(): nu(0),de(1){}
    rational(int _nu, int _de){
        if(_de<0) _nu*=-1,_de*=-1;
        nu=_nu,de=_de;
    }
    bool operator <(const rational& o) const {return nu*o.de<de*o.nu;}
    bool operator ==(const rational& o) const {return nu*o.de==de*o.nu;}
    bool operator >(const rational& o) const {return nu*o.de>de*o.nu;}
};

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
        assert(b>=0);
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
struct matrix{
    int row,col;
    T val[2][2];
    matrix():row(2),col(2){}
    matrix operator *(const matrix& o) const {
        matrix res;
        rep(row) rep1(j,o.col) rep1(k,col) res.val[i][j]+=val[i][k]*o.val[k][j];
        return res;
    }
};

template <typename T>
struct matrix_segment_tree{
    vector<matrix<T>> val;
    matrix<T> e;
    matrix_segment_tree(int _size){
        val.resize(4*_size);
        rep(e.row) e.val[i][i]=T(1);
        rep(4*_size) val[i]=e;
    }
    void pull(int k){val[k]=val[k<<1|1]*val[k<<1];}
    void modify(int k, int l, int r, int p, matrix<T>& x){
        if(p<l||p>r) return;
        if(l==r){val[k]=x;return;}
        modify(k<<1,l,l+r>>1,p,x),modify(k<<1|1,(l+r>>1)+1,r,p,x);
        pull(k);
    }
    matrix<T> query(int k, int l, int r, int ql, int qr){
        if(qr<l||ql>r) return e;
        if(ql<=l&&qr>=r) return val[k];
        return query(k<<1|1,(l+r>>1)+1,r,ql,qr)*query(k<<1,l,l+r>>1,ql,qr);
    }
};

rational f(int i, int j, bool d1, bool d2){
    if(i>j) swap(i,j),swap(d1,d2);
    if((v[i]>=v[j]&&!d1)||(v[i]<=v[j]&&d2)) return rational(2100000000,1);
    if(d1&&!d2) return rational(x[j]-x[i],v[i]+v[j]);
    else return rational(x[j]-x[i],max(v[i],v[j])-min(v[i],v[j]));
}

modint inv100=modint(100).inv(),ans,k1,k2;
vector<pair<rational,int>> vec;
matrix_segment_tree<modint> segtree(maxn);
matrix<modint> a[maxn],tmp;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    //freopen("c.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    cin >> n;
    rep(n) cin >> x[i] >> v[i] >> p[i];
    if(n==1){
        print1(0);
        return 0;
    }
    rep(n-1) rep1(j,2) rep1(k,2) vec.pb({f(i,i+1,j,k),i*4+k*2+j});
    sort(all(vec)),reverse(all(vec));
    rep(n-1) rep1(j,2) rep1(k,2){
        if(f(i,i+1,j,k)==rational(2100000000,1)){
            if(j) a[i].val[k^1][j^1]=modint(p[i])*inv100;
            else a[i].val[k^1][j^1]=modint(100-p[i])*inv100;
        }
        else a[i].val[k^1][j^1]=0;
    }
    rep(n-1) segtree.modify(1,1,n,i+1,a[i]);
    tmp=segtree.query(1,1,n,1,n);
    k1=(tmp.val[0][0]+tmp.val[0][1])*modint(p[n-1])*inv100+(tmp.val[1][0]+tmp.val[1][1])*modint(100-p[n-1])*inv100;
    rep(sz(vec)){
        if(vec[i].first.nu==2100000000) continue;
        if(vec[i].second&1) a[vec[i].second>>2].val[(vec[i].second>>1&1)^1][(vec[i].second&1)^1]=modint(p[vec[i].second>>2])*inv100;
        else a[vec[i].second>>2].val[(vec[i].second>>1&1)^1][(vec[i].second&1)^1]=modint(100-p[vec[i].second>>2])*inv100;
        segtree.modify(1,1,n,(vec[i].second>>2)+1,a[vec[i].second>>2]);
        tmp=segtree.query(1,1,n,1,n);
        k2=(tmp.val[0][0]+tmp.val[0][1])*modint(p[n-1])*inv100+(tmp.val[1][0]+tmp.val[1][1])*modint(100-p[n-1])*inv100;
        ans+=modint(vec[i].first.nu)*(modint(vec[i].first.de).inv())*(k2-k1);
        k1=k2;
    }
    print1(ans);
    return 0;
}