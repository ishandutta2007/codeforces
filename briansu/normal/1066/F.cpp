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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll val(ii p)
{
  ll k = max(p.X,p.Y);
  if(p.Y == k)return p.X;
  else return k + (k-p.Y);
}

map<ll,ii> mn,mx;
vector<ii> mnd,mxd;
ll dp[MAXn][2];

ll dis(ii a,ii b)
{
  debug(a,b);
  return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)
    {
      ll x,y;
      cin>>x>>y;
      ll k = max(x,y);
      ll v = val(ii(x,y));
      if(mn.count(k))
      {
        if(v < val(mn[k]))mn[k] = ii(x,y);
        if(v > val(mx[k]))mx[k] = ii(x,y);
      }
      else mn[k] = ii(x,y),mx[k] = ii(x,y);
    }
    mn[0] = ii(0,0);
    mx[0] = ii(0,0);
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(auto tmp:mn)mnd.pb(tmp.Y);
    for(auto tmp:mx)mxd.pb(tmp.Y);
    REP1(i,SZ(mnd) - 1)
    {
      dp[i][0] = min(dp[i-1][0] + dis(mnd[i-1],mxd[i]),dp[i-1][1] + dis(mxd[i-1],mxd[i])) + dis(mnd[i],mxd[i]);
      dp[i][1] = min(dp[i-1][0] + dis(mnd[i-1],mnd[i]),dp[i-1][1] + dis(mxd[i-1],mnd[i])) + dis(mnd[i],mxd[i]);
    }
    cout<<min(dp[SZ(mnd)-1][0],dp[SZ(mnd)-1][1])<<endl;
}