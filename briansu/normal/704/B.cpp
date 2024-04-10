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
const ll INF=ll(1e17);

ll dp[2][MAXn][3]; //i, in , out(0-> in-1 1-> in 2-> in+1)

ll d[MAXn],lj[MAXn],rj[MAXn],lld[MAXn],rld[MAXn];

inline void setmin(ll &a,ll b){a=min(a,b);}

int main()
{
    IOS();
    ll n,s,e;
    cin>>n>>s>>e;
    REP1(i,n)cin>>d[i];
    REP1(i,n)cin>>rld[i];
    REP1(i,n)cin>>lld[i];
    REP1(i,n)cin>>lj[i];
    REP1(i,n)cin>>rj[i];
    REP(i,2)REP(j,n)REP(k,3)dp[i][j][k]=INF;
    dp[0][0][1]=0;
    ll fg=0;
    REP1(i,n)
    {
      fg=!fg;
      REP(j,n)REP(k,3)dp[fg][j][k]=INF;
      //REP(j,n)REP(k,3)dp[i][j][k]=dp[!fg][j][k]+(j+j+k-1)*(d[i]-d[i-1]);
      if(i==s)
      {
        REP(j,n)REP(k,2)if(j+k-1>=0)
        {
          if(j==0&&j+k-1==0&&i-1!=0)continue;
          ll tmp=dp[!fg][j][k]+(j+j+k-1)*(d[i]-d[i-1]);
          setmin(dp[fg][j][k+1],tmp+rj[i]);
          if(j!=0)setmin(dp[fg][j-1][k+1],tmp+lj[i]);
        }
      }
      else if(i==e)
      {
        REP(j,n)REP1(k,2)if(j+k-1>=0)
        {
          if(j==0&&j+k-1==0&&i-1!=0)continue;
          ll tmp=dp[!fg][j][k]+(j+j+k-1)*(d[i]-d[i-1]);
          if(j+k-1!=0)setmin(dp[fg][j][k-1],tmp+rld[i]);
          if(j!=n-1)setmin(dp[fg][j+1][k-1],tmp+lld[i]);
        }
      }
      else
      {
        REP(j,n)REP(k,3)if(j+k-1>=0)
        {
          if(j==0&&j+k-1==0&&i-1!=0)continue;
          ll tmp=dp[!fg][j][k]+(j+j+k-1)*(d[i]-d[i-1]);
          if(j!=0)setmin(dp[fg][j-1][k],tmp+rld[i]+lj[i]);
          if(j!=n-1)setmin(dp[fg][j+1][k],tmp+lld[i]+rj[i]);
          if(j!=0)setmin(dp[fg][j][k],tmp+lld[i]+lj[i]);
          if(j+k-1!=0)setmin(dp[fg][j][k],tmp+rld[i]+rj[i]);
        }
      }
    }
    cout<<dp[fg][0][1]<<endl;

    //REP(i,n+1)REP(j,n)REP(k,3)debug(i,j,j+k-1,dp[i][j][k]);

}