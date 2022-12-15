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

ll n,r;
ll l[MAXn],t[MAXn];
vector<ll> dt;
ll ans=0;


int main()
{
    IOS();
    cin>>n>>r;
    REP(i,n)cin>>l[i];
    REP(i,n)
    {
      cin>>t[i];
      if(t[i]<l[i]){cout<<-1<<endl;return 0;}
    }

    ll mx=0,lt=0;
    REP(i,n)
    {
      if(mx-lt>=l[i])lt+=l[i],mx=max(mx,lt);
      else if(2*(l[i]-(mx-lt))+mx-lt<=t[i])lt+=2*(l[i]-(mx-lt))+mx-lt,mx=lt;
      else
      {
        ll tmpl=l[i]-(mx-lt),tmpt=t[i]-(mx-lt);
        lt=mx;
        ll x=2*tmpl-tmpt;
        if(x>0)
        {
          ll c=(x-1)/r+1;
          ans+=(x-1)/r+1;
          lt+=tmpt;
          mx=lt-x+c*r;
          if(ans<=100000)for(ll a=lt-x;a<lt;a+=r)dt.pb(a);
        }
      }
    }
    debug(mx,lt);
    cout<<ans<<endl;
    if(ans<=100000)for(ll k:dt)cout<<k<<" ";
    cout<<endl;
}