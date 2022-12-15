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


const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace dinic{
    struct edge{
        ll to, cap, rev;
    };
    vector<edge> v[MAXn];
    ll dis[MAXn], iter[MAXn];
    void init(ll n){
        REP1(i,n)v[i].clear();
    }
    void add_edge(ll from, ll to, ll cap){
        v[from].pb({to, cap, SZ(v[to])});
        v[to].pb({from, 0, SZ(v[from]) - 1});
    }
    ll dfs(ll now,ll t, ll k){
        if(now == t)return k;
        debug(now);
        for(ll &i = iter[now];i < SZ(v[now]);i ++){
            edge &e = v[now][i];
            if(e.cap && dis[e.to] == dis[now] + 1)
            {
                ll ret = dfs(e.to, t, min(k, e.cap));
                if(ret){
                    e.cap -= ret;
                    v[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    void bfs(ll s){
        dis[s] = 0;
        queue<ll> q;
        q.push(s);
        while(SZ(q)){
            ll t = q.front();
            q.pop();
            for(edge &e:v[t])if(e.cap && dis[e.to] == -1){
                dis[e.to] = dis[t] + 1;
                q.push(e.to);
            }
        }
    }
    ll flow(ll n,ll s,ll t){
        ll tt = 0;
        while(1){
            debug("in");
            REP1(i,n)dis[i] = -1, iter[i] = 0;
            bfs(s);
            if(dis[t] == -1)return tt;
            ll d;
            while((d = dfs(s, t, INF)) != 0){
                tt += d;
                debug(tt);
            }
        }
    }
};




int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP1(i,n)
    {
        ll x;
        cin>>x;
        dinic::add_edge(i, n + m + 2, x);
    }
    ll tt = 0;
    REP1(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        dinic::add_edge(n + m + 1, n + i, c);
        dinic::add_edge(n + i, a, INF);
        dinic::add_edge(n + i, b, INF);
        tt += c;
    }
    tt -= dinic::flow(n + m + 2, n + m + 1, n + m + 2);
    cout<<tt<<endl;
}