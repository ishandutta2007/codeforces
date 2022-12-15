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

typedef long double ld;

struct val{
  ld mul,add;//first mul, then add
};

ll d[MAXn];

struct node{
  ll l,r;
  node *lc,*rc;
  ld tt; bool fg; val dt;
  void pull()
  {
    if(l!=r-1)tt=lc->tt+rc->tt;
    else tt=d[l];
    if(fg)tt=tt*dt.mul+dt.add*(r-l);
  }
  void push(val v)
  {
    if(!fg)dt.mul=v.mul,dt.add=v.add;
    else dt.mul*=v.mul,dt.add=dt.add*v.mul+v.add;
    fg=1;
    pull();
  }
  void ins(ll li,ll ri,val v)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)push(v);
    else
    {
      if(fg)lc->push(dt),rc->push(dt);
      fg=0;
      lc->ins(li,ri,v);rc->ins(li,ri,v);
      pull();
    }
  }
  ld qr(ll li,ll ri)
  {
    if(li>=r||ri<=l)return 0.0;
    else if(li<=l&&ri>=r)return tt;
    else
    {
      ld tmp=lc->qr(li,ri)+rc->qr(li,ri);
      if(fg)tmp=tmp*dt.mul+(min(r,ri)-max(l,li))*dt.add;
      return tmp;
    }
  }
};

node *build(ll l,ll r)
{
  if(l==r-1)return new node{l,r,0,0,(ld)d[l],0,{0,0}};
  else
  {
    node *rt=new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),0,0,{0,0}};
    rt->pull();
    return rt;
  }
}
node *rt;
int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP(i,n)cin>>d[i];
    rt=build(0,n);
    while(q--)
    {
      ll t;
      cin>>t;
      if(t==1)
      {
        ll l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        l1--;l2--;
        ld a=rt->qr(l1,r1)/(ld)(r1-l1),b=rt->qr(l2,r2)/(ld)(r2-l2);
        rt->ins(l1,r1,{(ld)(r1-l1-1)/(ld)(r1-l1),b/(ld)(r1-l1)});
        rt->ins(l2,r2,{(ld)(r2-l2-1)/(ld)(r2-l2),a/(ld)(r2-l2)});
      }
      else
      {
        ll l,r;
        cin>>l>>r;
        l--;
        cout<<fixed<<setprecision(12)<<rt->qr(l,r)<<endl;
      }

    }
}