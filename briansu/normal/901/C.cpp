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


struct node{
  ll l,r;
  node *lc,*rc;
  ll mn,mx;
  void ins(ll x,ll k)
  {
    if(l==r-1)mx=mn=k;
    else
    {
      if(x<(l+r)/2)lc->ins(x,k);
      else rc->ins(x,k);
      mx=max(lc->mx,rc->mx);
      mn=min(lc->mn,rc->mn);
    }
  }
  ii qr(ll li,ll ri)
  {
    if(li>=r||ri<=l)return ii(INF,-INF);
    else if(li<=l&&ri>=r)return ii(mn,mx);
    else
    {
      ii a=lc->qr(li,ri),b=rc->qr(li,ri);
      return ii(min(a.X,b.X),max(a.Y,b.Y));
    }
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node{l,r,0,0,0,0};
  else return new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),0,0};
}
node *rt;

vector<ll> v[MAXn];
ll vis[MAXn],dp[MAXn];
vector<ii> dt;

void dfs(ll now,ll f)
{
  debug(now,f);
  vis[now]=1;
  rt->ins(dp[now],now);
  for(ll k:v[now])if(k!=f)
  {
    if(vis[k])
    {
      if(dp[k]<dp[now])dt.pb(rt->qr(dp[k],dp[now]+1));
    }
    else dp[k]=dp[now]+1,dfs(k,now);
  }
}


ll d[MAXn],pred[MAXn];

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    rt = build(0,n);
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    REP(i,n)if(!vis[i])
    {
      dp[i]=0;
      dfs(i,-1);
    }
    debug(dt);
    sort(ALL(dt),[](ii a,ii b){return a>b;});
    ll mn=n,it=0;
    for(int i=n-1;i>=0;i--)
    {
      while(it<SZ(dt)&&dt[it].X==i)mn=min(mn,dt[it++].Y);
      d[i]=mn;
    }
    partial_sum(d,d+n,pred+1);
    ll q;
    cin>>q;
    pary(d,d+n);
    pary(pred,pred+n+1);
    while(q--)
    {
      ll l,r;
      cin>>l>>r;
      l--;
      auto tmp=lower_bound(d+l,d+r,r)-d;
      debug(l,r,tmp);
      ll tt=pred[tmp]-pred[l]+(r-tmp)*r-(l+r-1)*(r-l)/2;
      cout<<tt<<endl;
    }
}