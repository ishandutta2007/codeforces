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


const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ii> v[MAXn];
vector<ii> e;
ll d[MAXn*MAXn];
ll it[MAXn];

ll dg[MAXn];

bool vis[MAXn];
vector<ll> od;


void dfs(ll now)
{

  vis[now]=1;
  if(dg[now]%2==1)od.pb(now);
  for(auto &k:v[now])if(!vis[k.X])dfs(k.X);
}

void build(ll now)
{
  while(1){
  while(it[now]<SZ(v[now])&&d[v[now][it[now]].Y]!=-1)it[now]++;
  if(it[now]==SZ(v[now]))return;
  auto &k=v[now][it[now]];
  d[k.Y]=(now==e[k.Y].X?0:1);
  build(k.X);
  }
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    ll n,m;
    while(T--&&cin>>n>>m)
    {
      REP1(i,n)v[i].clear();
      e.clear();
      FILL(d,-1);
      FILL(it,0);
      FILL(vis,0);
      ll ans=n;

      REP(i,m)
      {
        ll a,b;
        cin>>a>>b;
        e.pb(ii(a,b));
        v[a].pb(ii(b,i));
        v[b].pb(ii(a,i));
      }
      //e.pb(ii(-1,-1));
      REP1(i,n)dg[i]=SZ(v[i]);
      REP1(i,n)if(!vis[i])
      {
        od.clear();
        dfs(i);
        for(int j=0;j<SZ(od);j+=2)
        {
          e.pb(ii(od[j],od[j+1]));
          v[od[j]].pb(ii(od[j+1],SZ(e)-1));
          v[od[j+1]].pb(ii(od[j],SZ(e)-1));
          d[SZ(e)-1]=-1;
        }
        ans-=SZ(od);
        debug(i,od);
        build(i);
      }

      cout<<ans<<endl;
      REP(i,m)
      {
        if(d[i]==0)cout<<e[i].X<<" "<<e[i].Y<<endl;
        else       cout<<e[i].Y<<" "<<e[i].X<<endl;
      }

    }
}