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


const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll sz[MAXn],d[2][MAXn];
vector<ll> v[MAXn];

ll dp[2][MAXn][MAXn];// c? subtree cnt

void minfy(ll &a,ll b){a=min(a,b);}
ll n;
void dfs(ll now)
{
  dp[0][now][0]=0;
  dp[1][now][0]=0;
  for(ll k:v[now])
  {
    dfs(k);
    for(ll f=sz[k]+sz[now];f>=0;f--)for(int i=max(1LL,f-sz[now]);i<=sz[k]&&i<=f&&f-i<=sz[now];i++)minfy(dp[0][now][f],dp[0][k][i]+dp[0][now][f-i]),
                                  minfy(dp[1][now][f],min(dp[1][k][i],dp[0][k][i])+min(dp[1][now][f-i],dp[0][now][f-i]));
    sz[now]+=sz[k];
  }
  for(int i=sz[now];i>=0;i--)minfy(dp[0][now][i+1],dp[0][now][i]+d[0][now]);
  for(int i=sz[now];i>=0;i--)dp[1][now][i+1]=dp[1][now][i]+d[1][now];
  dp[1][now][0]=INF;
  sz[now]++;
  debug(now);
  pary(dp[0][now],dp[0][now]+n+1);
  pary(dp[1][now],dp[1][now]+n+1);
}

int main()
{
    IOS();
    ll m;
    cin>>n>>m;
    REP(i,MAXn)REP(j,MAXn)dp[0][i][j]=dp[1][i][j]=INF;
    REP(i,n)
    {
      cin>>d[0][i]>>d[1][i],d[1][i]=d[0][i]-d[1][i];
      ll t;
      if(i)
      {
        cin>>t;
        t--;
        v[t].pb(i);
      }
    }
    pary(d[0],d[0]+n);
    pary(d[1],d[1]+n);

    dfs(0);
    dp[1][0][0]=0;
    cout<<max(upper_bound(dp[0][0],dp[0][0]+n+1,m)-dp[0][0],upper_bound(dp[1][0],dp[1][0]+n+1,m)-dp[1][0])-1<<endl;
}