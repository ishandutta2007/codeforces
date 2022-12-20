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


const ll MAXn=2e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll pw(ll x,ll k)
{
  if(!k)return 1;
  ll a=pw(x,k/2);
  a=a*a%MOD;
  if(k&1)return a*x%MOD;
  else return a;
}


ll fac[MAXn],ifac[MAXn];
ll d[MAXn];

vector<ii> dt;

ll h(ll a,ll b)
{
  debug(a,b);
  return fac[a+b-1]*ifac[a-1]%MOD*ifac[b]%MOD;
}

int main()
{
    IOS();
    fac[0]=1;
    REP1(i,MAXn-1)fac[i]=fac[i-1]*i%MOD;
    ifac[MAXn-1]=pw(fac[MAXn-1],MOD-2);
    for(ll i=MAXn-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%MOD;
    debug(h(1,2),fac[MAXn-1]*ifac[MAXn-1]%MOD);
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    sort(d,d+n);
    ll tt=0,mx=*max_element(d,d+n);
    REP(i,n)if(!SZ(dt)||dt.back().X!=d[i])dt.pb(ii(d[i],1));else dt.back().Y++;
    debug(dt);
    ll pre=0;
    REP(i,SZ(dt))if(dt[i].X!=mx)
    {
      ll tmp=fac[pre]*fac[n-pre-1]%MOD;
      debug(i,tmp);
      tmp=tmp*h(pre+1,n-pre)%MOD*dt[i].Y%MOD*dt[i].X%MOD;
      debug(i,tmp);
      tt=(tt+tmp)%MOD;
      pre+=dt[i].Y;
    }
    cout<<tt<<endl;

}