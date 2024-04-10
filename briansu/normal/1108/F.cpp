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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct edge{
    ll a, b, c;
};

vector<edge> e, u;
vector<ii> v[MAXn];
ll g[MAXn];
ll fd(ll x){return g[x] = (g[x] == x?x:fd(g[x]));}
void mg(ll a,ll b){
    a = fd(a), b = fd(b);
    g[a] = b;
}

ll p[MAXn][MAXlg], st[MAXn][MAXlg], dph[MAXn];

void dfs(ll now,ll f)
{
    for(ii k:v[now])if(k.X != f)
    {
        p[k.X][0] = now;
        st[k.X][0] = k.Y;
        dph[k.X] = dph[now] + 1;
        dfs(k.X, now);
    }
}

ll s(ll a,ll b)
{
    if(dph[a] < dph[b])swap(a, b);
    ll ret = 0;
    for(int j = MAXlg - 1;j >= 0;j --)if(dph[p[a][j]] > dph[b])ret = max(ret, st[a][j]), a = p[a][j];
    if(dph[a] != dph[b])ret = max(ret, st[a][0]), a = p[a][0];
    if(a == b)return ret;
    for(int j = MAXlg - 1;j >= 0;j --)if(p[a][j] != p[b][j])ret = max({ret, st[a][j], st[b][j]}), a = p[a][j], b = p[b][j];
    return max({ret, st[a][0], st[b][0]});
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i, m)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        e.pb({a, b, c});
    }
    REP1(i,n)g[i] = i;
    sort(ALL(e), [](auto &a, auto &b){return a.c < b.c;});
    for(auto &p:e)
    {
        if(fd(p.a) != fd(p.b))
        {
            debug(p.a, p.b, p.c);
            mg(p.a, p.b);
            v[p.a].pb({p.b, p.c});
            v[p.b].pb({p.a, p.c});
        }
        else u.pb(p);
    }
    p[1][0] = 1, st[1][0] = 0;
    dfs(1, -1);
    REP1(j, MAXlg - 1)REP1(i, n)p[i][j] = p[p[i][j-1]][j-1], st[i][j] = max(st[i][j-1], st[p[i][j-1]][j-1]);
    ll tt = 0;
    for(auto &p:u)
    {
        debug(p.a, p.b, p.c);
        if(s(p.a, p.b) == p.c)tt++;
    }
    cout<<tt<<endl;
}