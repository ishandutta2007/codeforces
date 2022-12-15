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

#define blk(_a) ((_a)*2)
#define wit(_a) ((_a)*2+1)
ll g[2*MAXn],sz[2*MAXn],st=1;
ll fd(ll a){debug(a);assert(a>=0&&a<2*MAXn);return (g[a]==a?a:fd(g[a]));}
struct tg{
  ll id,st,x,y,sz;
  tg(ll idi,ll sti,ll xi,ll yi,ll szi):id(idi),st(sti),x(xi),y(yi),sz(szi){}
};
vector<tg> ch;

ll idit=0;
struct node{
  ll l,r,id;
  node *lc,*rc;
  vector<ii> d;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),id(idit++),lc(lci),rc(rci){d.clear();}
  void ins(ll li,ll ri,ii di)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)d.pb(di);
    else lc->ins(li,ri,di),rc->ins(li,ri,di);
  }
  void go()
  {
      //debug(l,r,d);
      pary(g,g+6);
      if(st)for(ii &t:d)
      {
        ll nst=1,a=t.X,b=t.Y;
        ll k[4]={fd(blk(a)),fd(wit(a)),fd(blk(b)),fd(wit(b))};
        pary(k,k+4);
        if(k[0]!=k[3])
        {
          if(k[0]==k[2]||k[1]==k[3])
          {
            ch.pb(tg(id,1,-1,-1,-1));
            st=0;
            break;
          }
          if(sz[k[0]]>sz[k[3]])swap(k[0],k[3]);
          ch.pb(tg(id,st,k[0],k[3],sz[k[3]]));
          sz[k[3]]+=sz[k[0]];
          g[k[0]]=k[3];

          if(sz[k[1]]>sz[k[2]])swap(k[1],k[2]);
          ch.pb(tg(id,st,k[1],k[2],sz[k[2]]));
          sz[k[2]]+=sz[k[1]];
          g[k[1]]=k[2];
        }
      }
      if(l!=r-1)lc->go(),rc->go();
      else cout<<(st?"YES":"NO")<<endl;
      while(SZ(ch)&&ch.back().id==id)
      {
        tg &t=ch.back();
        st=t.st;
        if(t.x!=-1)g[t.x]=t.x;
        if(t.y!=-1)sz[t.y]=t.sz;
        ch.pop_back();
      }
  }
};

node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

map<ii,ll> mp;
node *rt=0;

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    rt=build(0,q);
    REP(i,q)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      auto it=mp.insert(make_pair(ii(a,b),i));
      if(!it.Y)rt->ins(it.X->Y,i,ii(a,b)),mp.erase(it.X);
    }
    for(auto &tmp:mp)rt->ins(tmp.Y,q,tmp.X);
    REP(i,2*n)g[i]=i;
    rt->go();
    pary(g,g+6);
}