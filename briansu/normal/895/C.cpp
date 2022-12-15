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


const ll MAXn=1e5+5,MAXlg=19;
const ll MOD=1000000007;
const ll INF=ll(1e15);

bool ispm(ll x)
{
  for(int i=2;i<x;i++)if(x%i==0)return 0;
  return 1;
}


vector<ll> pm;
ll cal(ll x)
{
  ll rt=0;
  REP(i,SZ(pm))
  {
    while(x%pm[i]==0)
    {
      rt^=(1<<i);
      x/=pm[i];
    }
  }
  return rt;
}

ll pw[MAXn],ct[100];
int dp[71][(1<<MAXlg)],dt[100];

int main()
{
    IOS();
    for(int i=2;i<=70;i++)if(ispm(i))pm.pb(i);
    debug(SZ(pm),pm);
    pw[0]=1;
    REP1(i,MAXn-1)pw[i]=pw[i-1]*2,pw[i]-=(pw[i]>=MOD?MOD:0);
    REP1(i,70)dt[i]=cal(i);
    ll n;
    cin>>n;
    dp[0][0]=1;
    REP(i,n)
    {
      ll t;
      cin>>t;
      ct[t]++;
    }
    REP1(i,70)
    {
      if(!ct[i])
      {
        REP(I,(1<<MAXlg))dp[i][I]=dp[i-1][I];
        continue;
      }
      ll x=pw[ct[i]-1];
      REP(I,(1<<MAXlg))dp[i][I]=(dp[i-1][I]+dp[i-1][I^dt[i]])*x%MOD;
    }
    cout<<dp[70][0]-1<<endl;
}