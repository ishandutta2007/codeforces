//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

struct node
{
  ll l,r;
  node *lc,*rc;
  ll mx,tg;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),mx(0),tg(0){}
  void ins(ll li,ll ri,ll x)
  {
    if(li>=r||ri<=l)return;
    if(li<=l&&ri>=r)
    {
      tg+=x;
      mx=(l==r-1?0:max(lc->mx,rc->mx))+tg;
    }
    else
    {
      lc->ins(li,ri,x);
      rc->ins(li,ri,x);
      mx=(l==r-1?0:max(lc->mx,rc->mx))+tg;
    }
  }
  ll qr(ll t)
  {
    if(l==r-1)return l;
    t+=tg;
    if(rc->mx+t>0)return rc->qr(t);
    else return lc->qr(t);
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
ll d[MAXn];
ll n;
node *rt;
int main()
{
    IOS();
    cin>>n;
    rt=build(0,n);
    REP(i,n)
    {
      ll p,t;
      cin>>p>>t;
      p--;
      if(t==0)
      {
        rt->ins(0,p+1,-1);
      }
      else
      {
        ll x;
        cin>>x;
        d[p]=x;
        rt->ins(0,p+1,1);
      }
      if(rt->mx<=0)cout<<-1<<endl;
      else
      {
        ll tmp=rt->qr(0);
        debug(tmp);
        cout<<d[tmp]<<endl;
      }
    }
}