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

ii d[MAXn];

vector<ii> vx[MAXn],vy[MAXn];
vector<ll> v[MAXn];

set<ll> stx,sty;
ll vis[MAXn];
ll lp = 0;

void dfs(ll now,ll f)
{
    vis[now] = 1;
    stx.insert(d[now].X);
    sty.insert(d[now].Y);
    for(ll k:v[now])if(k!=f)
    {
        if(vis[k])
        {
            lp = 1;
            continue;
        }
        dfs(k,now);
    }
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i].X>>d[i].Y;
    {
        vector<ll> uni;
        REP(i,n)uni.pb(d[i].X);
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        REP(i,n)d[i].X = lower_bound(ALL(uni),d[i].X) - uni.begin();
    }    
    {
        vector<ll> uni;
        REP(i,n)uni.pb(d[i].Y);
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        REP(i,n)d[i].Y = lower_bound(ALL(uni),d[i].Y) - uni.begin();
    }
    REP(i,n)vx[d[i].X].pb(ii(d[i].X,i));
    REP(i,n)vy[d[i].Y].pb(ii(d[i].Y,i));
    REP(i,n)sort(ALL(vx[i])),sort(ALL(vy[i]));
    REP(i,n)
    {
        {
            auto &vv = vx[d[i].X];
            auto it = lower_bound(ALL(vv),ii(d[i].X,i));
            if(it != vv.begin())v[i].pb(prev(it)->Y);
            if(next(it) != vv.end())v[i].pb(next(it)->Y);
        }
        {
            auto &vv = vy[d[i].Y];
            auto it = lower_bound(ALL(vv),ii(d[i].Y,i));
            if(it != vv.begin())v[i].pb(prev(it)->Y);
            if(next(it) != vv.end())v[i].pb(next(it)->Y);
        }
    }
    ll tt = 1;
    REP(i,n)if(!vis[i])
    {
        stx.clear();
        sty.clear();
        lp = 0;
        dfs(i,-1);
        ll pw = 1,ct = SZ(stx) + SZ(sty);
        REP(_,ct)pw = pw * 2 % MOD;
        if(!lp)pw = (pw - 1 + MOD) % MOD;
        tt = tt * pw % MOD;
    }
    cout<<tt<<endl;
}