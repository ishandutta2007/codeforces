//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _a,typename _b> ostream &operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
#else
#define debug(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=1e4+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n,m,k;
vector<ll> v[MAXn];
ll d[MAXn];
bool vis[MAXn];
ll sz[MAXn];
ll ans=0,mx=0;
void dfs(ll now)
{
    sz[now]=1;
    vis[now]=1;
    for(ll k0:v[now])
    {
        if(vis[k0])continue;
        dfs(k0);
        sz[now]+=sz[k0];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    REP(i,k)cin>>d[i];
    REP(i,k)d[i]--;
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i,k)
    {
        dfs(d[i]);
        ans+=sz[d[i]]*(sz[d[i]]-1)/2;
        mx=max(mx,sz[d[i]]);
    }
    REP(i,n)
    {
        if(!vis[i])
        {
            dfs(i);
            ans+=mx*sz[i]+(sz[i]*(sz[i]-1)/2);
            mx+=sz[i];
        }
    }
    ans-=m;
    cout<<ans<<endl;
}