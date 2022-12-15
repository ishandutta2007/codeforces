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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace CostFlow{
    struct edge{
        ll to, cap, rev, cost;
    };
    ll n, s, t;
    vector<edge> v[MAXn];
    ll inq[MAXn], dis[MAXn];
    ii prv[MAXn];
    void init(ll ni, ll si, ll ti)
    {
        n = ni, s = si, t = ti;
        for(int i = 0;i <= n;i ++)v[i].clear();
    }
    void add_edge(ll from, ll to, ll cap, ll cost)
    {
        v[from].pb({to, cap, SZ(v[to]), -cost});
        v[to].pb({from, 0, SZ(v[from]) - 1, cost});
    }
    ii flow()
    {
        ll cost = 0, tt = 0;
        while(1)
        {
            queue<ll> q;
            for(int i = 0;i <= n;i ++)dis[i] = INF, inq[i] = 0;
            q.push(s);
            dis[s] = 0;
            inq[s] = 1;
            while(SZ(q))
            {
                ll t = q.front();q.pop();
                inq[t] = 0;
                ll id = 0;
                for(edge &e:v[t])
                {
                    if(e.cap && dis[t] + e.cost < dis[e.to])
                    {
                        dis[e.to] = dis[t] + e.cost;
                        prv[e.to] = ii(t, id);
                        if(!inq[e.to])q.push(e.to);
                    }
                    id++;
                }
            }
            if(dis[t] == INF)return ii(tt, -cost);
            ll flw = INF;
            for(ll now = t; now != s; now = prv[now].X)flw = min(v[prv[now].X][prv[now].Y].cap, flw);
            tt += flw;
            for(ll now = t; now != s; now = prv[now].X)v[prv[now].X][prv[now].Y].cap -= flw, v[now][v[prv[now].X][prv[now].Y].rev].cap += flw;
            cost += flw * dis[t];
        }
    }
    
};

ll d[MAXn],g[2][MAXn],dt[2][MAXn],dp[2][MAXn],ct[2][MAXn],ord[MAXn];
vector<ll> v[2][MAXn],h;

void qt()
{
    cout<<-1<<endl;
    exit(0);
}

void dfs(ll now,ll f,ll t)
{
    if(dt[t][now] != -1)h.pb(now);
    g[t][now] = h.back();
    for(ll k:v[t][now])if(k != f)
    {
        dfs(k,now,t);
        dp[t][now] += dp[t][k];
    }
    if(dt[t][now] != -1)
    {
        dt[t][now] -= dp[t][now],dp[t][now] += dt[t][now];
        if(dt[t][now] < 0)qt();
    }
    if(h.back() == now)h.pop_back();
}

int main()
{
    IOS();
    ll n,x,y;
    cin>>n>>x>>y;
    REP1(i,n)cin>>d[i];
    FILL(dt,-1);
    REP(j,2)REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[j][a].pb(b);
        v[j][b].pb(a);
    }
    REP(j,2)
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll k,x;
            cin>>k>>x;
            dt[j][k] = x;
        }
    }
    if(dt[0][x] != dt[1][y])qt();
    ll ttf = dt[0][x];
    dfs(x,-1,0);
    dfs(y,-1,1);
    //REP(j,2)REP1(i,n)debug(j,i,g[j][i], dt[j][g[j][i]]);
    CostFlow::init(3 * n + 2, 3 * n + 1, 3 * n + 2);
    REP1(i,n)
    {
        CostFlow::add_edge(g[0][i], n + i, 1, d[i]);
        if(g[0][i] == i)CostFlow::add_edge(3 * n + 1, i, dt[0][i], 0);
    }
    REP1(i,n)
    {
        CostFlow::add_edge(n + i, 2 * n + g[1][i], 1, 0);
        if(g[1][i] == i)CostFlow::add_edge(2 * n + i, 3 * n + 2, dt[1][i], 0);
    }
    debug("Start");
    ii f = CostFlow::flow();
    if(f.X != ttf)qt();
    else cout<<f.Y<<endl;
}