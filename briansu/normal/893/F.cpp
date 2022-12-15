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
  ll mn;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),mn(INF){}
  node(node *n){l=n->l,r=n->r,lc=n->lc,rc=n->rc,mn=n->mn;}
  void ins(ll x,ll k)
  {
    if(l==r-1)mn=min(mn,k);
    else if(x<(l+r)/2)
    {
      lc=new node(lc);
      lc->ins(x,k);
      mn=min(lc->mn,rc->mn);
    }
    else
    {
      rc=new node(rc);
      rc->ins(x,k);
      mn=min(lc->mn,rc->mn);
    }
  }
  ll qr(ll li,ll ri)
  {
    if(li>=r||ri<=l)return INF;
    else if(li<=l&&ri>=r)return mn;
    else return min(lc->qr(li,ri),rc->qr(li,ri));
  }
};

node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node* rt[MAXn];
vector<ll> v[MAXn],uni;
ll d[MAXn],l[MAXn],r[MAXn],it=0;
ll dt[MAXn],dp[MAXn];

void dfs(ll now,ll f,ll dpi)
{
  l[now]=it++;dp[now]=dpi;
  for(ll k:v[now])if(k!=f)dfs(k,now,dpi+1);
  r[now]=it;
}
int main()
{
    IOS();
    ll n,ri,q;
    cin>>n>>ri;
    rt[0]=build(0,n);
    REP(i,n)cin>>d[i],dt[i]=i;
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    dfs(ri-1,-1,1);
    sort(dt,dt+n,[](int a,int b){return dp[a]<dp[b];});
    ll nowdp=0;
    REP(i,n)
    {
      ll t=dt[i];
      if(dp[t]>nowdp)
      {
        nowdp++;
        rt[nowdp]=new node(rt[nowdp-1]);
      }
      rt[dp[t]]->ins(l[t],d[t]);
    }
    ll lt=0;
    cin>>q;
    while(q--)
    {
      ll x,k;
      cin>>x>>k;
      x=(x+lt)%n;
      k=(k+lt)%n;
      k=min(nowdp,dp[x]+k);
      lt = rt[k]->qr(l[x],r[x]);
      cout<<lt<<endl;
    }
}