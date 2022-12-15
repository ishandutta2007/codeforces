//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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


const int MAXn=3e2,MAXlg=__lg(MAXn)+1;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll mx[300][300][10];

ll dp[2][300][300];

int main()
{
    //IOS();
    //debug(MAXlg);
    int n,m;
    scanf("%d %d",&n,&m);//cin>>n>>m;
    REP(i,n)REP(j,n)REP(k,9)dp[0][i][j]=mx[i][j][k]=i==j?0:-INF;
    REP(i,m)
    {
      int a,b,c,d;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      //cin>>a>>b>>c>>d;
      a--;b--;
      mx[a][b][0]=c;
      mx[b][a][0]=d;
    }
    REP1(k,9)
    {
      if(k<9)REP(i,n)REP(j,n)REP(t,n)mx[i][j][k]=max(mx[i][j][k],mx[i][t][k-1]+mx[t][j][k-1]);
      else REP(i,n)REP(t,n)mx[i][i][k]=max(mx[i][i][k],mx[i][t][k-1]+mx[t][i][k-1]);
    }
    bool b=0;
    //REP(i,n)REP(j,n)REP(k,MAXlg)debug(i,j,k,mx[i][j][k]);
    REP(i,n)if(mx[i][i][9]>0)b=1;
    if(!b){puts("0");return 0;}
    int ans=1;
    for(int k=8;k>=0;k--)
    {
      b=0;
      //bool tfg=!fg;
      REP(i,n)REP(j,n)dp[1][i][j]=dp[0][i][j];
      REP(i,n)REP(j,n)REP(t,n)dp[1][i][j]=max(dp[1][i][j],dp[0][i][t]+mx[t][j][k]);
      REP(i,n)if(dp[1][i][i]>0)b=1;
      if(!b)
      {
        ans+=(1<<k);
        REP(i,n)REP(j,n)dp[0][i][j]=dp[1][i][j];
      }
    }
    printf("%d\n",ans);
    //cout<<ans<<endl;
}