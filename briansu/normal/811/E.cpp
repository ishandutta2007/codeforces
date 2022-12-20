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


const ll MAXn=12,MAXm=1e5+5,MAXc=1e6+5,MAXlg=__lg(MAXm)+1;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n,m;
ll d[MAXn][MAXm];

struct tg{
  ll id,clr;
  tg(ll idi=0,ll clri=0):id(idi),clr(clri){}
};

ll g[MAXn*MAXm];

int fd(ll a){return g[a]=(g[a]==a?a:fd(g[a]));}
inline void mg(ll a,ll b){g[fd(a)]=fd(b);}

int mg(tg *la,tg *ra,tg *lb,tg *rb,tg *l,tg *r)
{
  int rt=0;

  REP(i,n)g[la[i].id]=la[i].id,g[lb[i].id]=lb[i].id,g[ra[i].id]=ra[i].id,g[rb[i].id]=rb[i].id;


  REP(i,n)
  {
    if(ra[i].clr==lb[i].clr)
    {
        if(fd(ra[i].id)!=fd(lb[i].id))
        {
          mg(ra[i].id,lb[i].id);
          rt--;
        }
    }
  }
  REP(i,n)
  {
    l[i]=tg(fd(la[i].id),la[i].clr);
    r[i]=tg(fd(rb[i].id),rb[i].clr);
  }

  return rt;
}
ll idit=0,ans;
struct node{
  ll l,r;
  node *lc,*rc;
  ll cnt;
  tg ld[MAXn],rd[MAXn],rld[MAXn],rrd[MAXn];
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),cnt(0)
  {
    if(l==r-1)
    {
      REP(i,n)
      {
        if(i==0||d[i][l]!=d[i-1][l])ld[i]=rd[i]=tg(idit++,d[i][l]),cnt++;
        else ld[i]=rd[i]=tg(ld[i-1].id,d[i][l]);
      }
    }
    else
    {
      cnt=lc->cnt+rc->cnt+mg(lc->ld,lc->rd,rc->ld,rc->rd,ld,rd);
    }
    //debug(li,ri,cnt);
    //REP(i,n)debug(i,ld[i].id,rd[i].id);
  }
  pair<tg*,tg*> qr(ll li,ll ri,ll lv)
  {
    debug(l,r,li,ri);
    ll h=(l+r)/2;
    if(li<=l&&ri>=r)
    {
      ans+=cnt;

      return make_pair(ld,rd);
    }
    else if(li>=h)return rc->qr(li,ri,lv+1);
    else if(ri<=h)return lc->qr(li,ri,lv+1);
    else
    {
      auto a=lc->qr(li,ri,lv+1);
      auto b=rc->qr(li,ri,lv+1);

      pair<tg*,tg*> tmp=make_pair(rld,rrd);
      ans+=mg(a.X,a.Y,b.X,b.Y,tmp.X,tmp.Y);
      return tmp;
    }
  }
};


node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;
int main()
{
    IOS();
    ll q;
    cin>>n>>m>>q;
    REP(i,n)REP(j,m)cin>>d[i][j];
    rt=build(0,m);
    

    REP(i,q)
    {
      ll l,r;
      cin>>l>>r;
      l--;
      ans=0;
      debug("qr",l,r);
      rt->qr(l,r,0);
      cout<<ans<<endl;
    }
}