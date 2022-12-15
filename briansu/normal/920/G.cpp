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


const ll MAXn=1e5+5,MAXc=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> pm;
ll mnpm[MAXc];
vector<ll> dt;


ll cal(ll x)
{
  //debug(x);
  ll tt=0,n=SZ(dt);
  REP1(i,(1<<n)-1)
  {
    ll fg=-1,mu=1;
    REP(j,n)if((1<<j)&i)fg=fg*-1,mu*=dt[j];
    tt+=(x/mu)*fg;
  }
  //debug(x,tt);
  return tt;
}

int main()
{
    IOS();

    for(ll i=2;i<MAXc;i++)
    {
      if(!mnpm[i])pm.pb(i),mnpm[i]=i;
      for(int j=0;pm[j]*i<MAXc;j++)
      {
        mnpm[pm[j]*i]=pm[j];
        if(i%pm[j]==0)break;
      }
    }

    /*vector<ll> tmp={2,3,5,7,11,13,17};
    ll tt=0;
    REP1(i,1000000)
    {
      ll t=i;
      for(ll k:tmp)while(t%k==0)
      {
        t/=k;
      }
      if(t==1)tt++;
    }
    debug(tt);*/
    ll T;
    cin>>T;
    while(T--)
    {
      dt.clear();
      ll x,p,k;
      cin>>x>>p>>k;
      while(p!=1)
      {
        ll t=mnpm[p];
        dt.pb(t);
        while(p%t==0)p/=t;
      }
      debug(dt);
      ll tmptt=cal(x);
      ll l=x,r=100000000;
      while(l!=r-1)
      {
        ll h=(l+r)/2;
        if(h-x-(cal(h)-tmptt)>=k)r=h;
        else l=h;
      }
      cout<<r<<endl;
    }
}