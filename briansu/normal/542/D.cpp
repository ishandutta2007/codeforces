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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> pm;
vector<ll> ppm[112345];
ll ispm[MAXn];

bool chkpm(ll x)
{
    //return 1;
    for(int i = 0;i < SZ(pm) && pm[i] * pm[i] <= x;i ++)if(x % pm[i] == 0)return 0;
    return 1;
}

ll go(ll now, ll p)
{
    if(now == 1)return 1;
    ll tt = 0;
    if(chkpm(now - 1))
    {
        if(p == SZ(pm) && now - 1 > pm.back())tt ++;
        else if(p < SZ(pm) && now - 1 >= pm[p])tt ++;
    }
    debug(now, pm[p], tt);
    if(p >= SZ(pm))return tt;
    for(ll i = p;i < SZ(pm) && (pm[i] * pm[i]) + 1 <= now;i ++)
    {
        for(int j = 0;j < SZ(ppm[i]) && ppm[i][j] + 1 <= now;j ++)
        {
            if(now % (ppm[i][j] + 1) == 0)tt += go(now / (ppm[i][j] + 1), i + 1);
        }
    }
    return tt;
}

int main()
{
    IOS();
    for(ll i = 2;i < MAXn;i ++)
    {
        if(!ispm[i])pm.pb(i);
        for(int j = 0;pm[j] * i < MAXn;j ++)
        {
            ispm[pm[j] * i] = 1;
            if(i % pm[j] == 0)break;
        }
    }
    debug(SZ(pm), pm.back());
    ll tt = 0;
    REP(i, SZ(pm))
    {
        ll t = 1;
        while(t * pm[i] <= 1000000000000LL)
        {
            t *= pm[i];
            ppm[i].pb(t);
        }
        tt += SZ(ppm[i]);
    }
    debug(tt);
    ll n;
    cin>>n;
    cout<<go(n, 0)<<endl;
}