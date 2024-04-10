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
const ll INF=ll(1e17);




ll dis[MAXn];

vector<pair<ii,ll>> v[MAXn];
priority_queue<pair<ll,ii>,vector<pair<ll,ii>>,greater<pair<ll,ii>>> pq;
set<ll> st;


struct node{
  ll l,r;
  node *lc,*rc;
  vector<ii> v;
  node(ll l,ll r,node *lc=0,node *rc=0):l(l),r(r),lc(lc),rc(rc){}
  void ins(ll li,ll ri,ll p,ll w)
  {
    if(li >= r || ri <= l)return;
    if(li<= l && ri >= r)
    {
      v.pb({p,w});
    }
    else{
      lc->ins(li,ri,p,w);
      rc->ins(li,ri,p,w);
    }
  }
  void go(ll x,ll tmpd)
  {
    for(auto tmp:v)
    {
      pq.push({tmpd + tmp.Y,{tmp.X,tmp.X}});
    }
    v.clear();
    v.shrink_to_fit();
    if(l==r-1)return;
    else if(x < (l+r)/2)lc->go(x,tmpd);
    else rc->go(x,tmpd);
  }

};

node *build(ll l,ll r)
{
  if(l == r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt;

int main()
{
    IOS();
    ll n,q,s;
    cin>>n>>q>>s;
    rt = build(0,n+2);
    REP1(i,n)dis[i] = INF;
    REP(i,q)
    {
      ll tp,p,l,r,w;
      cin>> tp;
      if(tp == 1)
      {
        cin>>p>>l>>w;
        v[p].pb({{l,l},w});
      }else if(tp == 2)
      {
        cin>>p>>l>>r>>w;
        v[p].pb({{l,r},w});
      }
      else
      {
        cin>>p>>l>>r>>w;
        rt->ins(l,r+1,p,w);
      }
    }
    REP1(i,n)st.insert(i);
    pq.push({0,{s,s}});
    while(SZ(pq))
    {
      ll tmpd = pq.top().X;
      ii rg = pq.top().Y;
      pq.pop();
      debug(SZ(pq));
      while(1)
      {
        auto it = st.lower_bound(rg.X);
        if(it == st.end() || *it > rg.Y)break;
        ll t = *it;
        dis[t] = tmpd;
        st.erase(it);
        for(auto k:v[t])pq.push({tmpd+k.Y,k.X});
        rt->go(t,tmpd);
      }
    }
    REP1(i,n)if(dis[i] == INF)cout<<-1<<" ";
    else cout<<dis[i]<<" ";
}