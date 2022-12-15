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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll a[MAXn],b[MAXn],fg[MAXn];
vector<ll> p;
vector<ll> tg;

void cal(ll x)
{

  for(ll c:p){
    if(c * c > x)break;
    if(x % c == 0)tg.pb(c);
    while(x % c == 0)x /= c;
  }
  if(x > 1)tg.pb(x);
}


int main()
{
    IOS();
    for(ll i = 2;i < 100000;i++)
    {
      if(!fg[i])p.pb(i);
      for(int j = 0;p[j] * i < 100000;j++)
      {
        fg[p[j] * i] = 1;
        if(i % p[j] == 0)break;
      }
    }
    ll n;
    cin>>n;
    REP(i,n)cin>>a[i]>>b[i];
    cal(a[0]);
    cal(b[0]);
    sort(ALL(tg));
    tg.resize(unique(ALL(tg)) - tg.begin());
    REP(i,20)debug(p[i]);
    for(ll c:tg)
    {
      ll ok = 1;
      REP(i,n)
      {
        if(a[i] % c != 0 && b[i] % c != 0){
          ok = 0;
          break;
        }
      }
      if(ok)
      {
        cout<<c<<endl;
        return 0;
      }
    }
    cout<<-1<<endl;

}