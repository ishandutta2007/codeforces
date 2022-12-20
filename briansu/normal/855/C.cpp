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


vector<ll> v[MAXn];
ll dp[MAXn][5][15];

ll n,m,K,x;

ll mul(ll a,ll b)
{
  return a*b%MOD;
}

void add(ll &a,ll b)
{
  a=(a+b)%MOD;
}



void dfs(ll now,ll f)
{
  dp[now][0][0]=K-1;
  dp[now][1][1]=1;
  dp[now][2][0]=m-K;

  for(ll k:v[now])
  {
    if(k==f)continue;
    dfs(k,now);
    for(int i=x;i>=0;i--)
    {
      ll a=0,b=0,c=0;
      for(int j=0;j<=i;j++)
      {
        add(a,mul(dp[now][0][i-j],dp[k][0][j])+mul(dp[now][0][i-j],dp[k][1][j])+mul(dp[now][0][i-j],dp[k][2][j]));
        add(b,mul(dp[now][1][i-j],dp[k][0][j]));
        add(c,mul(dp[now][2][i-j],dp[k][0][j])+mul(dp[now][2][i-j],dp[k][2][j]));
      }
      dp[now][0][i]=a;
      dp[now][1][i]=b;
      dp[now][2][i]=c;
    }
  }
}

int main()
{
    IOS();
    cin>>n>>m;
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    cin>>K>>x;
    dfs(0,-1);
    ll tt=0;
    REP(t,n)REP(i,3)REP(j,x+1)debug(t,i,j,dp[t][i][j]);
    REP(i,x+1)REP(j,3)add(tt,dp[0][j][i]);
    cout<<tt<<endl;
}