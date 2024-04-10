//  228

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define inv(n) power((n), mod - 2)
#define ff(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define fff(i,a,b) for (int (i) = (a); (i) <= b; (i)++)
#define bff(i,a,b) for (int (i) = (b)-1; (i) >= (a); (i)--)
#define bfff(i,a,b) for (int (i) = (b); (i) >= (a); (i)--)
#define sum_overflow(a,b) __builtin_add_overflow_p (a, b, (__typeof__ ((a) + (b))) 0)
#define mul_overflow(a,b) __builtin_mul_overflow_p (a, b, (__typeof__ ((a) + (b))) 0)

using namespace std;
long double typedef ld;
unsigned int typedef ui;
long long int typedef li;
pair<int,int> typedef pii;
pair<li,li> typedef pli;
pair<ld,ld> typedef pld;
vector<vector<int>> typedef graph;
unsigned long long int typedef ull;
const ld PI = 3.14159265359;
//const int mod = 998244353;
const int mod = 1000000007;
const li inf = ((1ll<<63)-1-(1ll<<31));

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type,greater<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

inline int power(li _a, int _n)
{
    li _c=1;
    while (_n>0)
    {
        if (_n%2) _c=_c*_a%mod;
        _a=_a*_a%mod; _n/=2;
    } return _c;
}

template<typename _broj> _broj _nzd(_broj _a, _broj _b, pair<_broj,_broj> &_r)
{
    if (_b==0)
    {
        _r={1,0};
        return _a;
    }

    _broj _d=_nzd(_b,_a%_b,_r);
    _r={_r.yy,_r.xx-(_a/_b)*_r.yy};

    return _d;
}
template<typename _broj> _broj nzd(_broj _a, _broj _b, pair<_broj,_broj> &_r)
{
    if (abs(_a)<abs(_b))
    {
        _broj d=_nzd(_b,_a,_r);
        _r={_r.yy,_r.xx}; return d;
    }
    return _nzd(_a,_b,_r);
}
template <typename _broj> _broj bigmod(_broj _a, _broj _b, _broj _m)
{
    if (_b==0) return 0;
    if (_b&1) return (bigmod(_a,_b-1,_m)+_a)%_m;
    return (bigmod(_a,_b/2,_m)*2)%_m;
}
template<typename _broj> _broj kinez(_broj _a, _broj _n, _broj _b, _broj _m)
{
    if (_a==_b) return _a;
    _a%=_n; if (_a<0) _a+=_n;
    _b%=_m; if (_b<0) _b+=_m;

    pli _r;
    li _d=nzd(_n,_m,_r);
    if ((_b-_a)%_d) return -1;
    li _res,_mod=_n/__gcd(_n,_m)*_m;
    _r.xx%=_mod/_n; if (_r.xx<0) _r.xx+=_mod/_n;
    li _mnoz=(_b-_a)/_d; _mnoz%=_mod; if (_mnoz<0) _mnoz+=_mod;
    _r.xx=bigmod(_r.xx,_mnoz,_mod);
    _res=(bigmod(_r.xx,_n,_mod)+_a)%_mod;
    if (_res<0) _res+=_mod; return _res;
}

inline li sum(int _n) {return ((li)_n*(_n+1))/2;}

inline li kv(int _n) {return ((li)_n*(_n+1)*(2*_n+1))/6;}







//Note to self: Check for overflow

int n;
int niz[1000006];

class fwt
{
public:
    li a[1000006];

    li Pre(int p)
    {
        li x=0;
        while (p)
        {
            x+=a[p];
            p-=(p&-p);
        } return x;
    }

    void Upd(int p, int x)
    {
        while (p<=n)
        {
            a[p]+=x;
            p+=(p&-p);
        }
    }
};

fwt a,b;

int main()
{
    FAST;

    cin>>n;
    map<int,int> ind;
    ff(i,0,n) cin>>niz[i];

    vector<int> pom(n);
    ff(i,0,n) pom[i]=niz[i];
    sort(all(pom));
    ff(i,0,n) ind[pom[i]]=i;

    ff(i,0,n) niz[i]=n-ind[niz[i]];
    //ff(i,0,n) cout<<niz[i]<<" ";

    li ans=0;
    ff(i,0,n)
    {
        ans+=b.Pre(niz[i]);
        b.Upd(niz[i],a.Pre(niz[i]));
        a.Upd(niz[i],1);
    }

    cout<<ans;
}

//Note to self: Check for overflow