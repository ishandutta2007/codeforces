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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e17);

struct edge{ll to,len,id;};

vector<edge> v[MAXn];
ll u[MAXn],dis[MAXn],vis[MAXn],dg[MAXn];
ii p[MAXn];
ll n,m,k;
ll ct = 0;

void dfs(ll now)
{
    vis[now] = 1;
    for(auto &e:v[now])if(!vis[e.to] && dis[e.to] == dis[now] + e.len)
    {
        dg[now] ++;
        p[e.to] = {now,e.id};
        u[e.id] = 1;
        dfs(e.to);
    }
}

int main()
{
    IOS();
    cin>>n>>m>>k;
    REP1(i,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c,i});
        v[b].pb({a,c,i});
    }
    priority_queue<ii,vector<ii>, greater<ii> > pq;
    REP1(i,n)dis[i] = INF;
    dis[1] = 0;
    pq.push({0,1});
    while(SZ(pq))
    {
        ll t = pq.top().Y,tmpd = pq.top().X;
        pq.pop();
        if(tmpd != dis[t])continue;
        for(auto &e:v[t])if(dis[e.to] > dis[t] + e.len)
        {
            dis[e.to] = dis[t] + e.len;
            pq.push({dis[e.to],e.to});
        }
    }
    dfs(1);
    if(n - 1 <= k)
    {
        cout<<n-1<<endl;
        REP1(i,m)if(u[i])
        {
            ct++;
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else
    {
        ct = n - 1 - k;
        queue<ll> q;
        REP1(i,n)if(dg[i] == 0)q.push(i);
        while(SZ(q) && ct > 0)
        {
            ll t = q.front();q.pop();
            ct --;
            u[p[t].Y] = 0;
            dg[p[t].X] --;
            if(!dg[p[t].X])q.push(p[t].X);
        }
        cout<<k<<endl;
        REP1(i,m)if(u[i])cout<<i<<" ";
        cout<<endl;
    }
}