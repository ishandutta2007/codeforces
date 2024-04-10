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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll mypow(ll x,ll a){
  if(a==0)return 1LL;
  ll t = mypow(x,a/2);
  t = t * t % MOD;
  if(a & 1)return t * x % MOD;
  else return t;
}

ll g[MAXn],ans,ct;
ll fd(ll x){return g[x] = (g[x] == x?x:fd(g[x]));}
void mg(ll a,ll b){
  a = fd(a),b = fd(b);
  g[a] = b;
  ct --;
}


ll d[MAXn],ev[MAXn];

vector<ii> e;
vector<ll> his;

ll dt[MAXn];

void add(ll x){
  ans = (ans + x % MOD + MOD) % MOD;
}


int main()
{
    IOS();
    ll n,m,k;
    cin>>n>>m>>k;
    REP1(i,n)cin>>d[i],g[i] = i;
    ct = n;
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      e.pb(ii(a,b));
      ev[i] = (d[a] ^ d[b]);
      dt[i] = i;
    }
    sort(dt,dt+m,[](int a,int b){return ev[a] < ev[b];});
    ll usd = 0,lt = 0,it = 0;

    while(it < m)
    {
      vector<ll> tmp;
      while(it < m && ev[dt[it]] == ev[dt[lt]])tmp.pb(it),it++;
      lt = it;
      usd++;
      for(ll x : tmp)
      {
        ll a = e[dt[x]].X, b = e[dt[x]].Y;
        his.pb(a);
        his.pb(b);
        if(fd(a)!=fd(b))mg(a,b);
      }
      add(mypow(2, ct));
      for(ll x: his){
        g[x] = x;
      }
      his.clear();
      ct = n;
    }

    add((mypow(2,k) - usd + MOD) * mypow(2,n) % MOD);
    cout<<ans<<endl;
}