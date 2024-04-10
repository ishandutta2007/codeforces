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
//#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dt[6] = {0,10000,100020000LL,1000300030000LL,10004000600040000LL};

ll dfs(ll x,ll k){ //start from x, using k move
    if(k == 1)return x + min(x,10000LL) - 1;
    if(x >= 10000)return x + dt[k] - 1;
    ll lst = x - 2;
    REP(_,x+1){
      lst = dfs(lst + 2,k-1);
    }
    return lst;
}

ll doask(vector<ll> v,ll s){
  cout<<SZ(v);
  for(ll k:v)cout<<" "<<k;
  cout<<endl;
  ll t;
  cin>>t;
  if(t < 0)exit(0);
  if(t == 0)return s;
  return v[t-1] + 1;
}

int main()
{
    IOS();
    //cout<<dfs(1,5)<<endl;
    ll lst = 1;
    for(int k = 5;;k--){
      vector<ll> ask;
      if(k == 1){
        REP(i,min(lst,10000LL))ask.pb(i + lst);
      }else{
        ll now = lst;
        REP(i,min(lst,10000LL)){
          now = dfs(now,k - 1) + 2;
          ask.pb(now - 1);
        }
      }
      lst = doask(ask,lst);
    }
}