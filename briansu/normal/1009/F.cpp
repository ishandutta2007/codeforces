//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct node{
  ll dph,ct;
  node *nxt;
};

vector<ll> v[MAXn];
ll dph[MAXn],p[MAXn],h[MAXn];
node *nd[MAXn];
ii mx[MAXn];
ll ans[MAXn];


ii mg(node *&a,node *b)
{
  ii rt = {0,0};
  if(a)debug(a->dph);
  if(b)debug(b->dph);
  if(!a){
    a=b;
    return rt;
  }
  node * ta = a,* tb = b;
  while(ta && tb){
    ta->ct += tb->ct;
    debug(ta->ct);
    rt = max(rt,{ta->ct,-ta->dph});
    if(!ta->nxt){
      ta->nxt = tb->nxt;
      break;
    }
    ta = ta->nxt;
    tb = tb->nxt;
  }
  return rt;
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      v[b].pb(a);
    }
    FILL(dph,-1);
    queue<ll> q;
    q.push(1);
    dph[1] = 0;
    p[1] = -1;
    while(SZ(q))
    {
      ll t = q.front();q.pop();
      for(ll k:v[t])if(dph[k] == -1)
      {
        dph[k] = dph[t] + 1;
        q.push(k);
        p[k] = t;
      }
    }
    vector<ll> dt;
    REP1(i,n)dt.pb(i);
    sort(ALL(dt),[](int a,int b){return dph[a] > dph[b];});
    debug(dt);
    for(ll t : dt){
      nd[t] = new node{dph[t],1,0};
      mx[t] = ii(1,-dph[t]);
      //if(p[t]!=-1)h[p[t]] = h[t] + 1;
      for(ll k : v[t])if(dph[k] == dph[t] + 1)
      {
        debug(t,k,mx[t],mx[k]);
        mx[t] = max(mx[t],mx[k]);
        mx[t] = max(mx[t],mg(nd[t]->nxt,nd[k]));
      }
      ans[t] = -mx[t].Y - dph[t];
    }
    REP1(i,n)debug(i,mx[i]);
    REP1(i,n)cout<<ans[i]<<endl;
}