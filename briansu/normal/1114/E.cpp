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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ct = 0;

int main()
{
    IOS();
    ll n;
    cin>>n;
    ll l = -1, r = 1000000000;
    while(l != r-1)
    {
        ll h = (l + r) / 2;
        cout<<"> "<<h<<endl;
        ll x;
        cin>>x;
        if(x)l = h;
        else r = h;
        ct++;
    }
    ll mx = l + 1;
    vector<ll> dt;
    #ifdef brian
    while(ct < 35)
    #else
    while(ct < 60)
    #endif
    {
        ct++;
        cout<<"? "<<rng() % n + 1<<endl;
        ll x;
        cin>>x;
        dt.pb(x);
    }
    sort(ALL(dt));
    ll g = dt[1] - dt[0];
    for(int i = 2;i < SZ(dt);i ++)g = __gcd(g, dt[i] - dt[i-1]);
    cout<<"! "<<mx - (n-1) * g<<" "<<g<<endl;
}

/*
14,24,9,19
*/