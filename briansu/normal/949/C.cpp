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

vector<ll> v[MAXn],vr[MAXn];
ll d[MAXn],out[MAXn],g[MAXn],ct[MAXn];
ll vis[MAXn];
vector<ll> tp;

void dfs1(ll now)
{
  vis[now]=1;
  for(ll k:v[now])if(!vis[k])dfs1(k);
  tp.pb(now);
}
void dfs2(ll now,ll gid)
{
  g[now]=gid;
  vis[now]=1;
  for(ll k:vr[now])if(!vis[k])dfs2(k,gid);
}
int main()
{
    IOS();
    ll n,m,h;
    cin>>n>>m>>h;
    REP(i,n)cin>>d[i];
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      if((d[a]+1)%h==d[b])v[a].pb(b),vr[b].pb(a);
      if((d[b]+1)%h==d[a])v[b].pb(a),vr[a].pb(b);
    }
    REP(i,n)if(!vis[i])dfs1(i);
    FILL(vis,0);
    ll nit=0;
    while(SZ(tp))
    {
      if(!vis[tp.back()])dfs2(tp.back(),nit++);
      tp.pop_back();
    }
    REP(i,n)
    {
      ct[g[i]]++;
      for(ll k:v[i])if(g[i]!=g[k])out[g[i]]++;
    }
    ll mn=INF,id;
    REP(i,nit)if(out[i]==0&&ct[i]<mn)mn=ct[i],id=i;
    cout<<mn<<endl;
    REP(i,n)if(g[i]==id)cout<<i+1<<" ";
}