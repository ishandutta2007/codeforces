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


const ll MAXn=1e18+5,MAXlg=__lg(MAXn)+1;
const ll MOD=1000000007;
const ll INF=ll(1e15);
const double EPS = 1e-9;

ll d[MAXlg + 2];
vector<ii> v[MAXlg];

ll solve(ll x){
  d[2] = sqrt(x + 0.5);
  for(int i = 3;i < MAXlg;i++)d[i] = prev(lower_bound(ALL(v[i]),ii(x+1,-1)))->Y;
  /*for(int i = 2;i < MAXlg;i++)d[i] = 1;
  for(ll i = 2;i <= 30;i ++)
  {
    ll tmp = 1,ct = 0;
    while(x / i >= tmp)tmp *= i,ct += 1;
    d[ct] = max(d[ct],i);
  }
  for(ll i = 2;i <= 13;i++)d[i] = min(d[i],ll(pow(x,1.0L/i)));
  for(int i = 3;i < MAXlg;i++)d[i] = min(d[i],d[i-1]);*/
  //for(int i = 2;i < MAXlg;i++)debug(x,i,d[i]);
  for(int i = 2;i < MAXlg;i++)d[i] -= 1;
  for(int i = MAXlg - 1;i >= 2;i--)for(int j = 2;j<i;j++)if(i % j == 0)d[i / j] -= d[i];
  //for(int i = 2;i < MAXlg;i++)for(int j = 2;i * j < MAXlg;j ++)d[i * j] -= d[i];
  //for(int i = 2;i < MAXlg;i++)debug(x,i,d[i]);
  ll tt = x - 1;
  for(int i = 2;i < MAXlg;i++)tt -= d[i];
  return tt;
}

int main()
{
    IOS();
    for(int i=3;i<MAXlg;i++)v[i].pb(ii(1,1));
    for(ll i = 2;i <= 1000000;i++)
    {
      ll now = i,ct = 1;
      while(1000000000000000000LL / i >= now){
        now *= i;ct++;
        v[ct].pb(ii(now,i));
      }
    }
    ll T;
    cin>>T;
    while(T--)
    {
      ll x;
      cin>>x;
      cout<<solve(x)<<endl;
    }
}