//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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


const ll MAXn=5e2+5,MAXm=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll stk[MAXn],it=0;

vector<ll> v[MAXn];
ll from[MAXm],to[MAXm],nu[MAXm];
ll vis[MAXn],instk[MAXn];
vector<ll> dt;

bool dfs(ll now)
{
  vis[now]=1;
  instk[now]=1;
  for(ll edg:v[now])
  {
    if(nu[edg])continue;
    ll k = to[edg];
    stk[it++]=edg;
    if(instk[k])return 0;
    else if(!vis[k]&&!dfs(k))return 0;
    it--;
  }
  instk[now]=0;
  return 1;
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,m)cin>>from[i]>>to[i],v[from[i]].pb(i);
    REP1(i,n)if(!vis[i])
    {
      if(!dfs(i))break;
    }
    if(it==0)
    {
      cout<<"YES"<<endl;
      return 0;
    }
    REP(i,it)dt.pb(stk[i]);
    debug(dt);
    for(ll edg:dt)
    {
      nu[edg]=1;
      FILL(vis,0);
      FILL(instk,0);
      it=0;
      bool ok=1;
      REP1(j,n)if(!vis[j])
      {
        if(!dfs(j))
        {
          ok=0;
          break;
        }
      }
      if(ok)
      {
        cout<<"YES"<<endl;
        return 0;
      }
      nu[edg]=0;
    }
    cout<<"NO"<<endl;
}