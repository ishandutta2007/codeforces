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
  ll d;
  node(ll li,ll ri,node* lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0){}
  node(node *a):l(a->l),r(a->r),lc(a->lc),rc(a->rc),d(a->d){}
  void ins(ll x)
  {
    if(l==r-1)d++;
    else
    {
      if(x<(l+r)/2)
      {
        lc=new node(lc);
        lc->ins(x);
      }
      else
      {
        rc=new node(rc);
        rc->ins(x);
      }
      d=lc->d+rc->d;
    }
  }
  ll qr(ll li,ll ri)
  {
    debug(l,r,li,ri,d);
    if(li>=r||ri<=l)return 0;
    else if(li<=l&&ri>=r)return d;
    else return lc->qr(li,ri)+rc->qr(li,ri);
  }

};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
queue<ll> q[MAXn];

ll d[MAXn];
vector<ii> dt;
node *rt[MAXn];
int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP(i,n)cin>>d[i];
    REP(i,MAXn)q[i].push(-1);
    REP(i,n)
    {
      dt.pb(ii(q[d[i]].front(),i));
      q[d[i]].push(i);
      if(SZ(q[d[i]])>k)q[d[i]].pop();
    }
    sort(ALL(dt));
    rt[0]=build(0,n);
    REP1(i,n)
    {
      rt[i]=new node(rt[i-1]);
      rt[i]->ins(dt[i-1].Y);
    }
    debug(dt);
    ll q,lt=0;
    cin>>q;
    REP(i,q)
    {
      ll l,r;
      cin>>l>>r;
      l=(l+lt)%n+1;
      r=(r+lt)%n+1;
      if(l>r)swap(l,r);
      debug(l,r);
      l--;
      ll t=lower_bound(ALL(dt),ii(l,-1))-dt.begin();
      debug(t);
      lt=rt[t]->qr(l,r);
      cout<<lt<<endl;
    }
}