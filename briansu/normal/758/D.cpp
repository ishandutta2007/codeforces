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
const ll INF=ll(3e18);

vector<ll> dp[MAXn];

ll sti(string s)
{
  stringstream ss(s);
  ll t;
  ss>>t;
  return t;
}
bool cmp(vector<ll> &a,vector<ll> &b)
{
  for(int i=SZ(a)-1;i>=0;i--)
  {
    if(a[i]<b[i])return 1;
    else if(a[i]>b[i])return 0;
  }
  return 0;
}
int main()
{
    IOS();
    ll n;
    string s;
    cin>>n>>s;
    REP(i,100)REP(j,65)dp[i].pb(0);
    dp[0].clear();
    REP1(i,SZ(s))
    {
      if(s[SZ(s)-i]=='0')
      {
        dp[i]=dp[i-1];
        dp[i].pb(0);
        continue;
      }
      for(int j=1;j<=i;j++)
      {
        ll t=sti(s.substr(SZ(s)-i,j));
        if(t>=n)break;
        else if(SZ(dp[i-j])+1<SZ(dp[i]))
        {
          dp[i]=dp[i-j];
          dp[i].pb(t);
        }
        else if(SZ(dp[i-j])+1==SZ(dp[i]))
        {
          vector<ll> tmp=dp[i-j];
          tmp.pb(t);
          if(cmp(tmp,dp[i]))dp[i]=tmp;
        }
      }
    }
    REP(i,SZ(s)+1)debug(dp[i]);
    ll a=0,t=1;
    for(ll k:dp[SZ(s)])
    {
      a+=k*t;
      t*=n;
    }
    cout<<a<<endl;
}