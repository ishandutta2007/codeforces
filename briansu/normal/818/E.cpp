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

ll n,k;

struct node{
  ll l,r;
  node *lc,*rc;
  ll d;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(1){}
  void ins(ll li,ll ri,ll x)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)d=__gcd(d*x,k);
    else lc->ins(li,ri,x),rc->ins(li,ri,x);
  }
  ll qr(ll x)
  {
    if(l==r-1)return d;
    else if(x<(l+r)/2)return __gcd(d*lc->qr(x),k);
    else return __gcd(d*rc->qr(x),k);
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt;
int main()
{
    IOS();
    ll it=-1,a=0;
    cin>>n>>k;
    rt=build(0,n+1);
    REP(i,n)
    {
      ll t;
      cin>>t;

      rt->ins(0,i+1,t);
      while(it+1<=i&&rt->qr(it+1)==k)it++;
      a+=it+1;
      debug(it);
    }
    cout<<a<<endl;
}