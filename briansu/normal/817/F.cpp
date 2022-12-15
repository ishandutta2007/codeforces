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
  ll d,tg;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0)
  {
    if(l==r-1)tg=0;
    else tg=-1;
  }
  void push(ll t)
  {
    if(tg==-1||t!=2)tg=t;
    else if(tg==2)tg=-1;
    else if(tg==0)tg=1;
    else tg=0;
  }
  ll gdt()
  {
    if(tg==-1)return d;
    else if(tg==0)return 0;
    else if(tg==1)return r-l;
    else return r-l-d;
  }
  void pull()
  {
    d=lc->gdt()+rc->gdt();
  }
  void ins(ll li,ll ri,ll k)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)push(k);
    else
    {
      if(tg!=-1)lc->push(tg),rc->push(tg);
      tg=-1;
      lc->ins(li,ri,k);
      rc->ins(li,ri,k);
      pull();
    }
  }
  ll qr()
  {
    if(l==r-1)return l;
    else
    {
      if(tg!=-1)lc->push(tg),rc->push(tg);
      tg=-1;
      pull();
      if(lc->gdt()==lc->r-lc->l)return rc->qr();
      else return lc->qr();
    }
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

vector<ll> uni;
ll t[MAXn],l[MAXn],r[MAXn];
node *rt=0;

int main()
{
    IOS();
    ll q;
    cin>>q;
    uni.pb(1);
    REP(i,q)cin>>t[i]>>l[i]>>r[i],uni.pb(l[i]),uni.pb(r[i]+1);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());
    REP(i,q)l[i]=lower_bound(ALL(uni),l[i])-uni.begin(),r[i]=upper_bound(ALL(uni),r[i])-uni.begin();

    rt=build(0,SZ(uni)+1);

    REP(i,q)
    {
        ll dt[]={0,1,0,2};
        rt->ins(l[i],r[i],dt[t[i]]);
        cout<<uni[rt->qr()]<<endl;
    }
}