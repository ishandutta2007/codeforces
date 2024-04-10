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
const ll INF=ll(1e15);

vector<ii> v[MAXn];
bool d[MAXn],dp[MAXn];
ll h[MAXn],mn[MAXn];

void dfs(ll now,ll f)
{
  h[now]=(d[now]?0:INF);
  mn[now]=-1;
  for(ii k:v[now])
  {
    if(k.X==f)continue;
    dfs(k.X,now);
    if(h[k.X]+1<h[now])
    {
      h[now]=h[k.X]+1;
      mn[now]=k.X;
    }
  }
}
vector<ll> ans;
void dfs2(ll now,ll f,ll t)
{
  if(t<h[now])
  {
    h[now]=t;
    dp[now]=1;
    mn[now]=-1;
  }
  t=min(t,h[now])+1;
  for(ii k:v[now])
  {
    if(k.X==f)continue;
    dfs2(k.X,now,t);
    if(mn[now]!=k.X&&!dp[k.X])ans.pb(k.Y);
  }
}

int main()
{
    IOS();
    ll n,k,p;
    cin>>n>>k>>p;
    REP(i,k)
    {
      ll t;
      cin>>t;
      t--;
      d[t]=1;
    }
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(ii(b,i+1));
      v[b].pb(ii(a,i+1));
    }
    dfs(0,-1);
    dfs2(0,-1,INF);
    cout<<SZ(ans)<<endl;
    for(ll t:ans)cout<<t<<" ";
    cout<<endl;
}