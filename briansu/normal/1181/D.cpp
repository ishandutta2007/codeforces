//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(2e18);


namespace bit{
    const int N = (1<<19);
    int bit[N];
    void ins(int x)
    {
        while(x < N)bit[x]++,x += x & -x;
    }
    ll f(ll t)
    {
        int l = 0, len = (1<<18);
        while(len)
        {
            if(bit[l + len] < t)t -= bit[l + len], l += len;
            len>>=1;
        }
        return l + 1;
    }
};

ll pct[MAXn], ans[MAXn];

vector<ii> dt, qr;

int main()
{
    IOS();
    ll n, m, q;
    cin>>n>>m>>q;
    REP1(i,n)
    {
        ll x;
        cin>>x;
        pct[x] ++;
    }
    REP1(i, q)
    {
        ll t;
        cin>>t;
        qr.pb(ii(t, i));        
    }
    sort(ALL(qr));
    REP1(i,m)dt.pb(ii(pct[i], i));
    sort(ALL(dt));
    ll it = 0, ct = 0, qit = 0;
    n ++;
    debug(dt);
    while(it < m)
    {
        ll t = it;
        while(t < m && dt[t].X == dt[it].X)bit::ins(dt[t++].Y), ct++;
        ll bs = dt[it].X, len;
        if(t == m)len = INF;
        else len = ct * (dt[t].X - bs);
        debug(ct, bs, len);
        while(qit < SZ(qr) && qr[qit].X < n + len)
        {
            ll b = (qr[qit].X - n) % ct;
            ans[qr[qit].Y] = bit::f(b + 1);
            qit++;
        }
        n += len;
        it = t;
    }
    REP1(i,q)cout<<ans[i]<<endl;
}