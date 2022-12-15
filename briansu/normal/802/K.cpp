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

ll dp[MAXn][2];
vector<ii> v[MAXn];
ll n,k;

vector<ii> dt[MAXn];

void dfs(ll now,ll f)
{
  for(ii t:v[now])
  {
    if(t.X==f)continue;
    dfs(t.X,now);
    dt[now].pb(ii(dp[t.X][0]+t.Y,dp[t.X][1]+t.Y));
  }
  sort(ALL(dt[now]),greater<ii>() );
  REP(i,min(k-1,ll(SZ(dt[now]))))dp[now][0]+=dt[now][i].X;
  if(SZ(dt[now])<=k-1)REP(i,SZ(dt[now]))dp[now][1]=max(dp[now][1],dp[now][0]-dt[now][i].X+dt[now][i].Y);
  else
  {
    REP(i,SZ(dt[now]))if(i<k-1)dp[now][1]=max(dp[now][1],dp[now][0]-dt[now][i].X+dt[now][i].Y+dt[now][k-1].X);
                      else     dp[now][1]=max(dp[now][1],dp[now][0]+dt[now][i].Y);
  }
}
int main()
{
    IOS();
    cin>>n>>k;
    REP(i,n-1)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      v[a].pb(ii(b,c));
      v[b].pb(ii(a,c));
    }
    dfs(0,-1);
    REP(i,n)debug(i,dp[i][0],dp[i][1]);
    cout<<dp[0][1]<<endl;
}