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
    
struct edge{
    ll a, b, c;
};

vector<edge> e;
vector<ll> v[MAXn];
ll n, m, vis[MAXn], t[MAXn], tit;

void dfs(ll now)
{
    vis[now] = 1;
    for(ll k:v[now])if(!vis[k])dfs(k);
    t[now] = tit++;
}

bool cal(ll h)
{
    REP1(i,n)v[i].clear();
    for(auto &p:e)if(p.c > h)v[p.a].pb(p.b);
    FILL(vis, 0);
    tit = 0;
    REP1(i,n)if(!vis[i])dfs(i);
    bool fg = 1;
    for(auto &p:e)if(p.c > h && t[p.b] > t[p.a])fg = 0;
    return fg;
}

int main()
{
    IOS();
    cin>>n>>m;
    REP(i, m)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        e.pb({a,b,c});
    }
    ll l = -1, r = 1000000000;
    while(l != r-1)
    {
        ll h = (l + r) / 2;
        if(cal(h))r = h;
        else l = h;
    }
    assert(cal(r));
    vector<ll> dt;
    REP(i, m)
    {
        auto &p = e[i];
        if(p.c <= r && t[p.b] > t[p.a])dt.pb(i+1);
    }
    cout<<r<<" "<<SZ(dt)<<endl;
    for(ll x:dt)cout<<x<<" ";
}