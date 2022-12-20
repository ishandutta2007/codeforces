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
const ll INF=ll(1e18)+5;

ll dp[20][100][(1<<12)][3];

ll cal(ll b,ll x)//cnt for all <= x;
{
  ll tt=0,pre=0;
  vector<ll> dig;
  while(x>0)
  {
    dig.pb(x%b);
    x/=b;
  }
  debug(b,x,dig);
  for(int i=SZ(dig)-1;i>=0;i--)
  {
    REP(j,dig[i])if(j||i!=SZ(dig)-1)tt+=dp[b][i][pre^(1<<j)][1];
    pre^=(1<<dig[i]);
    debug(pre,tt);
  }
  tt+=dp[b][0][pre][1];
  if(SZ(dig))tt+=dp[b][SZ(dig)-1][0][0];
  else tt--;
  //debug(dp[b][SZ(dig)-1][0],dp[b][SZ(dig)-2][0]);
  return tt;
}

int main()
{
    IOS();
    for(int i=2;i<=10;i++)
    {
      dp[i][0][0][1]=1;
      REP1(j,60)REP(k,i)REP(I,(1<<(i+1)))
      {
        dp[i][j][I][1]+=dp[i][j-1][I^(1<<k)][1];
        if(!k)dp[i][j][I][0]+=dp[i][j-1][I][0];
        else dp[i][j][I][0]+=dp[i][j-1][I^(1<<k)][1];
      }

    }

    ll q;
    cin>>q;
    while(q--)
    {
      ll b,l,r;
      cin>>b>>l>>r;
      ll x=cal(b,r);
      ll y=cal(b,l-1);
      debug(x,y);
      cout<<x-y<<endl;
    }
}