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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
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

ll p[MAXn][MAXn];

ll add(ll a,ll b)
{
  a+=b;
  if(a>=MOD)a-=MOD;
  return a;
}

int main()
{
    IOS();
    ll k,pa,pb;
    cin>>k>>pa>>pb;
    ll inv=pw(pa+pb,MOD-2);
    ll invpa=pw(pa,MOD-2);
    ll invpb=pw(pb,MOD-2);


    p[1][0]=1;
    REP1(i,k)REP(j,2*k+1)
    {
      if(ii(i,j)==ii(1,0))continue;

      if(j-i>=0&&j-i<k)
      {
        ll tmp=pb*inv%MOD;
        p[i][j]=add(p[i][j],p[i][j-i]*tmp%MOD);

      }
      if(i-1!=0&&j<k)
      {
        ll tmp = pa*inv%MOD;
        p[i][j]=add(p[i][j],p[i-1][j]*tmp%MOD);

      }
    }
    ll tt=0;
    REP1(i,k-1)REP(j,2*k+1)if(j>=k)tt=add(tt,p[i][j]*j%MOD);
    ll tmp=(pa*invpb)%MOD;
    debug(tmp);
    REP(i,k)tt=add(tt,(i+k+tmp)*p[k][i]%MOD);
    cout<<tt<<endl;
    REP1(i,k)REP(j,2*k+1)debug(i,j,p[i][j]);

}