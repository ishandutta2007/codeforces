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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace seg{
    ll N = (1<<17);
    ll d[(1<<18)];
    void build()
    {
        for(int i = N-1;i > 0;i --)d[i] = min(d[i<<1], d[i<<1|1]);
    }
    void mod(int l,int r)
    {
        l += N, r += N;
        for(int i = l;i <= r;i ++)d[i]--;
        for(l>>=1, r>>=1;l > 0;l>>=1, r>>=1)
        {
            for(int i = l;i <= r;i ++)d[i] = min(d[i<<1], d[i<<1|1]);
        }
    }
    ll qr(int l,int r)
    {
        ll ret = INF;
        for(l += N, r += N;l < r;l>>=1, r>>=1)
        {
            if(l&1)ret = min(ret, d[l++]);
            if(r&1)ret = min(ret, d[--r]);
        }
        return ret;
    }
};

ll d[MAXn], mn[MAXn];
vector<ii> dt;
ii s[MAXn];

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    REP(i, ((seg::N)<<1))seg::d[i] = INF;
    REP(i,n)cin>>d[i];
    REP1(i,m)
    {
        ll l, r;
        cin>>l>>r;
        l--;r--;
        dt.pb(ii(l, r));
        s[i] = ii(l, r);
    }
    REP(i,n)mn[i] = d[i];
    REP(i,n)seg::d[seg::N + i] = d[i];
    seg::build();
    sort(ALL(dt), [](ii a,ii b){return a.Y < b.Y;});
    {
        ll it = 0;
        REP(i,n)
        {
            while(it < SZ(dt) && dt[it].Y < i)seg::mod(dt[it].X, dt[it].Y), it++;
            mn[i] = min(mn[i],seg::qr(0, n));
        }
    }
    REP(i,n)seg::d[seg::N + i] = d[i];
    seg::build();
    sort(ALL(dt), [](ii a,ii b){return a.X > b.X;});
    {
        ll it = 0;
        for(int i = n-1;i >= 0;i --)
        {
            while(it < SZ(dt) && dt[it].X > i)seg::mod(dt[it].X, dt[it].Y), it++;
            mn[i] = min(mn[i], seg::qr(0, n));
        }
    }
    ll ans = -1, it = -1;
    REP(i,n)if(d[i] - mn[i] > ans)ans = d[i] - mn[i], it = i;
    cout<<ans<<endl;
    vector<ll> tmp;
    REP1(i,m)if(s[i].Y < it || s[i].X > it)tmp.pb(i);
    cout<<SZ(tmp)<<endl;
    for(ll x:tmp)cout<<x<<" ";
    cout<<endl;
}