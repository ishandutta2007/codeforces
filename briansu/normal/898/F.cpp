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
//const ll MOD=1000000007;
const ll INF=ll(1e15);


string s;
bool ok(ll a,ll b)
{
  ll c=SZ(s)-a-b;
  if(a<=0||b<=0||(SZ(s)-a-b)<=0)return 0;
  if(a>1&&s[0]=='0')return 0;
  if(b>1&&s[a]=='0')return 0;
  if(c>1&&s[a+b]=='0')return 0;
  return 1;
}
struct solve{
  ll n,M,neg[MAXn],pw[MAXn],d[MAXn];
  inline ll add(ll a,ll b){
    a+=b;
    if(a>=M)a-=M;
    return a;
  }
  inline ll sub(ll a,ll b)
  {
    a-=b;
    if(a<0)a+=M;
    return a;
  }
  inline ll mypw(ll x,ll k)
  {
    if(!k)return 1;
    ll a=mypw(x,k/2);
    a=a*a%M;
    if(k&1)return a*x%M;
    else return a;
  }
  solve(ll Mi)
  {
    M=Mi;
    ll t=mypw(10,M-2);
    neg[0]=pw[0]=1;
    REP1(i,MAXn-1)neg[i]=neg[i-1]*t%M,pw[i]=pw[i-1]*10%M;
  }
  ll cal(ll a,ll b)
  {
    ll c=n-a-b;
    ll x=sub(d[0],d[a])*neg[n-a]%M,y=sub(d[a],d[a+b])*neg[c]%M,z=d[a+b];
    debug(a,b,x,y,z);
    if(add(x,y)==z)return 1;
    else return 0;
  }
};
solve s1 = solve(1000000007),s2 = solve(970000007);
void sol(ll a,ll b)
{
  if(!ok(a,b)||!s1.cal(a,b)||!s2.cal(a,b))return;
  cout<<s.substr(0,a)<<"+"<<s.substr(a,b)<<"="<<s.substr(a+b)<<endl;
  exit(0);
}

void init(solve &d)
{
  ll n=SZ(s);
  d.n=n;
  for(int i=n-1;i>=0;i--)d.d[i]=(d.d[i+1]+d.pw[n-i-1]*(s[i]-'0'))%d.M;
}

int main()
{
    IOS();
    cin>>s;ll n=SZ(s);
    init(s1);init(s2);

    pary(s1.d,s1.d+n);

    for(int a=1;a<SZ(s);a++)
    {
      sol(a,n-2*a);
      sol(a,n-2*a-1);
      sol(a,(n-a)/2);
    }
}