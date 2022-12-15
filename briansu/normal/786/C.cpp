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

struct node{
  ll l,r;
  node *lc,*rc;
  ll tt;
  node(ll l,ll r,node *lc=0,node *rc=0):l(l),r(r),lc(lc),rc(rc),tt(0){}
  void ins(ll x,ll p)
  {
    if(l == r-1)tt+=p;
    else
    {
      if(x < (l+r)/2)lc->ins(x,p);
      else rc->ins(x,p);
      tt = lc->tt + rc->tt;
    }
  }
  ll fd(ll x)
  {
    if(l == r-1)return l;
    if(lc->tt <= x)return rc->fd(x - lc->tt);
    else return lc->fd(x);
  }
};

ll d[MAXn],ans[MAXn];
vector<ll> v[MAXn];

ll lst[MAXn],nxt[MAXn];

node *build(ll l,ll r)
{
  if(l == r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt;

int main()
{
    IOS();
    ll n;
    cin>>n;
    rt = build(0,n+1);
    REP(i,n)cin>>d[i];
    REP1(i,n)v[0].pb(i);
    FILL(lst,-1);
    for(int i = n-1;i>=0;i--)
    {
      nxt[i] = lst[d[i]];
      lst[d[i]] = i;
    }
    REP1(i,n)if(lst[i] != -1)rt->ins(lst[i],1);
    REP(i,n)
    {
      for(ll k:v[i])
      {
        ll tmp = rt->fd(k);
        debug(k,i,tmp);
        ans[k]++;
        v[tmp].pb(k);
      }
      v[i].clear();
      v[i].shrink_to_fit();
      rt->ins(i,-1);
      if(nxt[i] != -1)rt->ins(nxt[i],1);
    }
    REP1(i,n)cout<<ans[i]<<" ";
    cout<<endl;
}