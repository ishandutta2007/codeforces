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
const ll INF=ll(1e9);

struct frc{
  ll a,b;
  frc(ll ai=1,ll bi=1)
  {
    if(bi<0)a=-ai,b=-bi;
    else a=ai,b=bi;
  }
  bool operator < (const frc &t){return a*t.b<b*t.a;}
  bool operator <= (const frc &t){return a*t.b<=b*t.a;}
  frc operator + (const frc &t){return frc(a*t.b+b*t.a,b*t.b);}
  frc operator * (const frc &t){return frc(a*t.a,b*t.b);}
};


ll u,d,l,r;
ll vx[MAXn],vy[MAXn];
ll px[MAXn],py[MAXn];
ll n;

frc mn[MAXn],mx[MAXn];


pair<lf,lf> cal(int i,lf t)
{
  return make_pair(px[i]+vx[i]*t,py[i]+vy[i]*t);
}
frc calx(int i,ll x)
{
  return frc((x-px[i]),vx[i]);
}
frc caly(int i,ll y)
{
  return frc((y-py[i]),vy[i]);
}
void qt()
{
  cout<<-1<<endl;
  exit(0);
}
#define min(_a,_b) ((_a)<(_b)?(_a):(_b))
#define max(_a,_b) ((_a)<(_b)?(_b):(_a))
int main()
{
    IOS();
    cin>>n;
    cin>>l>>d>>r>>u;
    REP(i,n)cin>>px[i]>>py[i]>>vx[i]>>vy[i];
    REP(i,n)
    {
      mn[i]=frc(-INF,1);
      mx[i]=frc(INF,1);

      if(vx[i]==0)
      {
        if(!(px[i]>l&&px[i]<r))qt();
      }
      else mn[i]=min(calx(i,l),calx(i,r)),mx[i]=max(calx(i,l),calx(i,r));
      if(vy[i]==0)
      {
        if(!(py[i]>d&&py[i]<u))qt();
      }
      else mn[i]=max(mn[i],min(caly(i,d),caly(i,u))),mx[i]=min(mx[i],max(caly(i,d),caly(i,u)));
      if(!(mn[i]<mx[i]))qt();
    }
    frc ans=mn[0],mans=mx[0];
    REP(i,n)ans=max(ans,mn[i]),mans=min(mans,mx[i]);
    ans=max(ans,frc(0,1));
    debug(123,ans.a,ans.b);
    //cout<<123<<endl;
    /*REP(i,n)
    {
      frc x=frc(px[i],1)+frc(vx[i],1)*ans;
      frc y=frc(py[i],1)+frc(vy[i],1)*ans;
      if(!(x<frc(r,1)&&frc(l,1)<x&&frc(d,1)<y&&y<frc(u,1)))qt();
    }*/

    if(ans<mans)cout<<fixed<<setprecision(12)<<lf(ans.a)/lf(ans.b)<<endl;
    else qt();
}