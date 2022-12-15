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



ll pw(ll x,ll k)
{
  if(k==0)return 1;
  ll t=pw(x,k/2);
  if(k%2==0)return t*t%MOD;
  else return t*t%MOD*x%MOD;
}

ll c[100][100][100];

ll d[MAXn],p[MAXn];

void add(ll &a,ll b)
{
  a+=b;
  a=(a%MOD+MOD)%MOD;
}

int main()
{
    IOS();
    /*
    for(int n=3;n<=20;n+=4){
    REP(i,n)c[0][i][i]=1;
    bool b=1;
    REP1(i,n-1)
    {
      REP(j,n-i)
      {
        if(b)
        {
          REP(k,n)c[i][j][k]=c[i-1][j][k]+c[i-1][j+1][k];
        }
        else REP(k,n)c[i][j][k]=c[i-1][j][k]-c[i-1][j+1][k];
        b=!b;
      }
    }
    //for(int i=0;i<n;i+=2)cout<<c[n-1][0][i]<<" ";
    //cout<<" , ";
    //for(int i=1;i<n;i+=2)cout<<c[n-1][0][i]<<" ";

    REP(i,n)cout<<c[n-1][0][i]<<" ";
    cout<<endl;
  }
  */

  p[0]=1;
  REP1(i,MAXn-1)p[i]=p[i-1]*i%MOD;


  ll n;

  cin>>n;
  REP(i,n)cin>>d[i];

  ll ans=0;

  if(n%4==1)
  {
    ll t=n/2;
    REP(i,n)
    {
        if(i%2==0)add(ans,p[t]*pw(p[i/2],MOD-2)%MOD*pw(p[t-i/2],MOD-2)%MOD*d[i]);
        debug(ans);
    }
  }
  else if(n%4==2)
  {
    ll t=(n-1)/2;
    REP(i,n)
    {
        add(ans,p[t]*pw(p[i/2],MOD-2)%MOD*pw(p[t-i/2],MOD-2)%MOD*d[i]);
    }
  }
  else if(n%4==3)
  {
    ll t=(n/2)-1;
    ll lt=0;
    REP(i,n-1)
    {
      if(i%2==0)
      {
        ll tmp=(p[t]*pw(p[i/2],MOD-2)%MOD*pw(p[t-i/2],MOD-2)%MOD);
        add(ans,(tmp-lt)*d[i]);
        lt=tmp;
      }
      else add(ans,p[t]*pw(p[i/2],MOD-2)%MOD*pw(p[t-i/2],MOD-2)%MOD*d[i]*2);
    }
    add(ans,d[n-1]*-1);
  }
  else
  {
    ll t=(n-1)/2;
    REP(i,n)
    {
        add(ans,p[t]*pw(p[i/2],MOD-2)%MOD*pw(p[t-i/2],MOD-2)%MOD*d[i]*(i%2==0?1:-1));

    }
  }
  cout<<ans<<endl;
}