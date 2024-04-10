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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn],tt,l[MAXn],r[MAXn];

vector<ll> stk;

int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP1(i,n)cin>>d[i];
    d[0] = d[n+1] = INF;
    stk.pb(0);
    REP1(i,n)
    {
      while(d[stk.back()] < d[i])stk.pop_back();
      l[i] = stk.back();
      stk.pb(i);
    }
    stk.clear();
    stk.pb(n + 1);
    for(int i = n;i > 0;i--)
    {
      while(d[stk.back()] <= d[i])stk.pop_back();
      r[i] = stk.back();
      stk.pb(i);
    }
    stk.clear();
    REP1(i,n)
    {
      ll a = i - l[i],b = r[i] - i, ct = 0, now = 0;
      if(a > b)swap(a,b);
      debug(i,a,b);
      if(a >= k)
      {
        now = (a - k) / (k - 1) + 1;
        ct += (k + now * (k - 1) + 1) * now / 2;
      }
      debug(ct);
      if(b >= now * (k-1) + k)
      {
        ll tmp = (b - k) / (k-1) + 1;
        ct += a * (tmp - now);
        now = tmp;
      }
      debug(ct);
      if(a + b > now * (k-1) + k)
      {
        ll tmp = (a + b - 1 - k) / (k - 1) + 1, x = a + b - now * (k-1) - k;
        debug(now,tmp,x);
        ct += ((2 * x) - (tmp - now - 1) * (k - 1)) * (tmp - now) / 2;
      }
      debug(i,ct);
      tt += ct % MOD * d[i] % MOD;
    }
    tt %= MOD;
    cout<<tt<<endl;
}