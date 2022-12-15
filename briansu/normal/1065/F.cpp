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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> v[MAXn],v2[MAXn];
ll p[MAXn],up[MAXn],islf[MAXn],dph[MAXn],g[MAXn],gtt[MAXn];
vector<ll> stk,stk2;
ll n,k,git = 0;

ll dfs(ll now)
{
  stk.pb(now);
  stk2.pb(now);
  ll mn = dph[now];
  if(now != 1 && SZ(v[now]) == 0)
  {
    islf[now] = 1;
    up[now] = stk[max(0LL,dph[now] - k)];
    mn = dph[up[now]];
  }
  for(ll t:v[now])
  {
    dph[t] = dph[now] + 1;
    mn = min(dfs(t),mn);
  }
  stk.pop_back();
  if(mn == dph[now])
  {
    git++;
    while(1)
    {
      g[stk2.back()] = git;
      if(stk2.back() == now)
      {
        stk2.pop_back();
        break;
      }
      else stk2.pop_back();
    }
  }
  return mn;
}


ll dp(ll now)
{
  ll mx = 0;
  for(ll t:v2[now])
  {
    mx = max(mx,dp(t));
  }
  mx += gtt[now];
  return mx;
}

int main()
{
    IOS();
    cin>>n>>k;
    for(int i = 2;i<=n;i++)
    {
      cin>>p[i];
      v[p[i]].pb(i);
    }
    dfs(1);
    REP1(i,n){
      gtt[g[i]] += islf[i];
      if(g[p[i]] != g[i])v2[g[p[i]]].pb(g[i]);
    }
    cout<<dp(g[1])<<endl;
    REP1(i,n)debug(i,islf[i],g[i],gtt[g[i]]);
}