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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll mypw(ll x,ll k)
{
  if(!k)return 1;
  ll a=mypw(x,k/2);
  a=a*a%MOD;
  if(k&1)return a*x%MOD;
  else return a;
}

map<ll,ll> dp;
inline void sub(ll &a,ll b)
{
  a-=b;
  if(a<0)a+=MOD;
}

ll it(ll x)
{
  debug(x);
  if(x==1)return 1;
  else if(dp.count(x))return dp[x];
  ll tt=mypw(2,x-1);
  debug(tt);
  for(ll i=1;i*i<=x;i++)
  {
    if(x%i!=0)continue;
    debug(i);
    if(i*i!=x)sub(tt,it(i));
    if(i!=1)sub(tt,it(x/i));
  }
  return dp[x]=tt;
}


int main()
{
    IOS();
    ll x,y;
    cin>>x>>y;
    if(y%x!=0)
    {
      cout<<0<<endl;
      return 0;
    }
    y/=x;
    cout<<it(y)<<endl;
    debug(dp);
}