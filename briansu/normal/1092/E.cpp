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

vector<ll> v[MAXn], his;
vector<ii> dt;
ll h[MAXn][2], vis[MAXn], far[MAXn];

void dfs1(ll now,ll f)
{
    vis[now] = 1;
    his.pb(now);
    for(ll k:v[now])if(k!=f)
    {
        dfs1(k,now);
        if(h[k][0] + 1 >= h[now][0])h[now][1] = h[now][0], h[now][0] = h[k][0] + 1;
        else if(h[k][0] + 1 >= h[now][1])h[now][1] = h[k][0] + 1;
    }
}
void dfs2(ll now,ll f,ll tp)
{
    far[now] = max(tp,h[now][0]);
    for(ll k:v[now])if(k!=f)
    {
        if(h[k][0] + 1 == h[now][0])dfs2(k,now, max(tp,h[now][1]) + 1);
        else dfs2(k, now, max(tp, h[now][0]) + 1);
    }
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll ans = 0;
    REP1(i,n)if(!vis[i])
    {
        his.clear();
        dfs1(i,-1);
        dfs2(i,-1,0);
        ll mn = INF, mnid = -1;
        for(ll x:his)
        {
            if(far[x] < mn)mn = far[x], mnid = x;
            ans = max(ans, far[x]);
        }
        dt.pb({far[mnid], mnid});
    }
    pary(far+1,far+1+n);
    sort(ALL(dt),greater<ii>());
    debug(dt,ans);
    if(SZ(dt) > 1)ans = max(ans, dt[0].X + dt[1].X + 1);
    if(SZ(dt) > 2)ans = max(ans, dt[1].X + 2 + dt[2].X);
    cout<<ans<<endl;
    REP1(i,SZ(dt) - 1)cout<<dt[0].Y<<" "<<dt[i].Y<<endl;
}