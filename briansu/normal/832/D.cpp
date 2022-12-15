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
ll dp[MAXn];
ll st[MAXn][MAXlg];

void dfs(ll now,ll f,ll dps)
{
  st[now][0]=f;
  dp[now]=dps;
  for(ll k:v[now])if(k!=f)dfs(k,now,dps+1);
}

ll lca(ll a,ll b)
{
  if(dp[a]<dp[b])swap(a,b);
  for(int j=MAXlg-1;j>=0;j--)if(st[a][j]!=-1&&dp[st[a][j]]>=dp[b])a=st[a][j];
  if(a==b)return a;
  for(int j=MAXlg-1;j>=0;j--)if(st[a][j]!=st[b][j])a=st[a][j],b=st[b][j];
  return st[a][0];
}

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP1(i,n-1)
    {
      ll a;
      cin>>a;
      v[a].pb(i+1);
      v[i+1].pb(a);
    }
    dfs(1,-1,0);
    REP1(j,MAXlg-1)REP1(i,n)if(st[i][j-1]!=-1)st[i][j]=st[st[i][j-1]][j-1];

    REP(t,q)
    {
      ll d[3];
      ll dt[3][3]={{0,1,2},{1,0,2},{2,0,1}};
      REP(i,3)cin>>d[i];
      ll ans=0;
      REP(i,3)
      {
        ll la[3][3];
        ll a[3];
        REP(j,3)a[j]=d[dt[i][j]];
        REP(j,3)REP(k,3)if(j<k)la[j][k]=la[k][j]=lca(d[dt[i][j]],d[dt[i][k]]);
        if(dp[la[0][1]]<=dp[la[1][2]]&&dp[la[0][2]]<=dp[la[1][2]])ans=max(ans,1+dp[la[1][2]]+dp[a[0]]-2*dp[la[0][2]]);
        else  if(la[0][1]==la[1][2])//right
        {
          ans=max(ans,dp[a[0]]-dp[la[0][2]]+1);
        }
        else //left
        {
          ans=max(ans,dp[a[0]]-dp[la[0][1]]+1);
        }
      }
      cout<<ans<<endl;
    }
}