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


void add(ll &a,ll b)
{
  a+=b%MOD;
  if(a>=MOD)a-=MOD;
}

void cal(ll d[3][3],ll x)
{
  ll dt[2][3][3],t=0,mx=0;
  while((1LL<<(mx+1))<=x)mx++;
  FILL(dt,0);
  REP(i,3)dt[0][i][i]=1;
  for(ll it=mx;it>=0;it--)
  {
    t=!t;
    FILL(dt[t],0);
    REP(i,3)REP(j,3)REP(k,3)add(dt[t][i][j],dt[!t][i][k]*dt[!t][k][j]);
    if((1LL<<it)&x)
    {
      t=!t;
      FILL(dt[t],0);
      REP(i,3)REP(j,3)REP(k,3)add(dt[t][i][j],dt[!t][i][k]*d[k][j]);
    }
  }
  REP(i,3)REP(j,3)d[i][j]=dt[t][i][j];
}

struct tg{ll a,l,r;};
vector<tg> dt;
vector<ll> uni;

ll dp[MAXn][5],d[MAXn][5],len[MAXn];
ll mul[10][3][3];
int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    uni.pb(1);
    REP(i,n)
    {
      ll a,l,r;
      cin>>a>>l>>r;
      dt.pb({a,l,r});
      uni.pb(l-1);
      uni.pb(r);
    }
    uni.pb(m);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());
    for(auto tmp:dt)
    {
      ll l=lower_bound(ALL(uni),tmp.l-1)-uni.begin();
      ll r=lower_bound(ALL(uni),tmp.r)-uni.begin();
      d[r][tmp.a-1]++;
      d[l][tmp.a-1]--;
      debug(tmp.a,l,r);
    }
    for(int i=SZ(uni)-1;i>0;i--)REP(j,3)d[i-1][j]+=d[i][j];
    REP1(i,SZ(uni)-1)len[i]=uni[i]-uni[i-1];
    REP(i,SZ(uni))REP(j,3)debug(i,j,d[i][j]);
    REP(i,(1<<3))
    {
      if(!(i&1))mul[i][0][0]=mul[i][0][1]=1;
      if(!(i&2))mul[i][1][0]=mul[i][1][1]=mul[i][1][2]=1;
      if(!(i&4))mul[i][2][1]=mul[i][2][2]=1;
      REP(j,3)REP(k,3)debug(i,j,k,mul[i][j][k]);
    }
    debug(uni);
    dp[0][1] = 1;
    REP1(i,SZ(uni)-1)
    {
      ll msk=0;
      if(d[i][0])msk+=1;
      if(d[i][1])msk+=2;
      if(d[i][2])msk+=4;
      debug(msk);
      ll tmp[3][3];
      REP(j,3)REP(k,3)tmp[j][k]=mul[msk][j][k];
      cal(tmp,len[i]);
      REP(j,3)REP(k,3)debug(j,k,tmp[j][k]);
      REP(j,3)REP(k,3)add(dp[i][j],tmp[j][k]*dp[i-1][k]);
      debug(i,len[i]);
    }
    REP(i,SZ(uni))REP(j,3)debug(i,j,dp[i][j]);
    cout<<dp[SZ(uni)-1][1]<<endl;
}