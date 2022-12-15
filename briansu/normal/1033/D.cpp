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
const ll MOD= 998244353;
const ll INF=ll(1e15);

ll d[MAXn];
bool fg[MAXn];
map<ll,ll> mp;

vector<ll> pm;
ll ispm[2000005];

int main()
{
    IOS();
    for(ll i = 2;i<=1500000;i++)
    {
      if(!ispm[i])pm.pb(i);
      for(ll j = 0;pm[j] * i <= 1500000;j++)
      {
        ispm[pm[j] * i] = 1;
        if(i % pm[j] == 0)break;
      }
    }
    debug(SZ(pm));
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n){
      ll tmp = d[i];
      for(ll k:pm)
      {
        while(tmp % k == 0)
        {
          mp[k] ++;
          tmp /= k;
          fg[i] = 1;
        }
      }
      if(fg[i] && tmp != 1)mp[tmp]++;
    }
    REP(i,n)if(!fg[i])
    {
      ll tmp = sqrt(d[i] + 0.5);
      if(tmp * tmp == d[i])
      {
        fg[i] = 1;
        mp[tmp] += 2;
      }
    }
    map<ll,ll> mp2;
    REP(i,n)if(!fg[i])
    {
      ll a = -1,b = -1;
      REP(j,n)if(i!=j)
      {
        debug(i,j);
        ll g = __gcd(d[i],d[j]);
        if(g != 1 && g != d[i])
        {
          if(a == -1)a = g;
          else if(a != g)b = g;
        }
      }
      if(a == -1)mp2[d[i]] ++;
      else
      {
        if(b == -1)b = d[i] / a;
        mp[a] ++;
        mp[b] ++;
      }
    }
    ll ans = 1;
    for(ii tmp:mp2)ans = ans * (tmp.Y + 1) % MOD * (tmp.Y + 1) % MOD;
    for(ii tmp:mp)ans = ans * (tmp.Y + 1) % MOD;
    cout<<ans<<endl;
}