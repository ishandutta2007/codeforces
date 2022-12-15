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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll ask(ii a, ii b)
{
    cout<<"? "<<a.X<<" "<<a.Y<<" "<<b.X<<" "<<b.Y<<endl;
    ll t;
    cin>>t;
    return t % 2;
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    vector<ll> r, c;
    REP1(i,n)if(ask({i, 1}, {i, n}))r.pb(i);
    REP1(i,n)if(ask({1, i}, {n, i}))c.pb(i);
    if(SZ(r) == 2 && SZ(c) == 2)
    {
        vector<ii> ans;
        REP(i, 2)REP(j, 2)if(ask({r[i], c[j]}, {r[i], c[j]}))ans.pb(ii(r[i], c[j]));
        cout<<"! "<<ans[0].X<<" "<<ans[0].Y<<" "<<ans[1].X<<" "<<ans[1].Y<<endl;
        return 0;
    }
    else if(SZ(r) == 2)
    {
        ll h = (r[0] + r[1]) / 2;
        ll tl = 0, tr = n;
        while(tl != tr-1)
        {
            ll hh = (tl + tr) / 2;
            if(ask({1, 1}, {h, hh}))tr = hh;
            else tl = hh;
        }
        vector<ii> ans;
        ans.pb(ii(r[0], tr));
        ans.pb(ii(r[1], tr));
        cout<<"! "<<ans[0].X<<" "<<ans[0].Y<<" "<<ans[1].X<<" "<<ans[1].Y<<endl;
    }
    else
    {
        ll h = (c[0] + c[1]) / 2;
        ll tl = 0, tr = n;
        while(tl != tr-1)
        {
            ll hh = (tl + tr) / 2;
            if(ask({1, 1}, {hh, h}))tr = hh;
            else tl = hh;
        }
        vector<ii> ans;
        ans.pb(ii(tr, c[0]));
        ans.pb(ii(tr, c[1]));
        cout<<"! "<<ans[0].X<<" "<<ans[0].Y<<" "<<ans[1].X<<" "<<ans[1].Y<<endl;
    }
}