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

struct mut{
  vector<vector<ll> > dt;
  ll n,m;
  mut(ll ni,ll mi):n(ni),m(mi){dt.resize(n,vector<ll>(m,0));}
};
mut operator * (const mut &a,const mut &b)
{
  ll n=a.n,m=b.m;
  mut rt(n,m);

  REP(i,n)REP(j,m)
  {
    REP(k,a.m)rt.dt[i][j]=(rt.dt[i][j]+a.dt[i][k]*b.dt[k][j])%MOD;
  }
  return rt;
}

mut pw(mut &x,ll k)
{
  if(k==0)
  {
    mut rt(x.n,x.n);
    REP(i,x.n)rt.dt[i][i]=1;
    return rt;
  }
  mut a=pw(x,k/2);
  if(k&1)return a*a*x;
  else return a*a;
}
int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    mut dt(16,1);
    dt.dt[0][0]=1;
    REP(T,n)
    {
      ll l,r,c;
      cin>>l>>r>>c;
      r=min(r,k);
      mut tr(16,16);
      REP(i,16)REP(j,16)
      {
        if(i<=c&&j<=c&&abs(j-i)<=1)tr.dt[i][j]=1;
      }
      dt=dt*pw(tr,r-l);
    }
    cout<<dt.dt[0][0]<<endl;
}