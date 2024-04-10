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
const ll INF=ll(1e15);

vector<ll> dt[MAXn];


int main()
{
    IOS();
    ll t=0;
    dt[1].pb(2);
    for(int i=2;;i++)
    {
      t+=i-1;
      if(t>100000)break;
      //debug(t);
      for(int j=t;j<=100000;j++)
      {
        if(SZ(dt[j-t])>=26||SZ(dt[j-t])==0)continue;
        if(!SZ(dt[j])||SZ(dt[j])>SZ(dt[j-t])+1)
        {
          dt[j]=dt[j-t];
          dt[j].pb(i);
        }
      }
    }
    for(int i=2;i<=100000;i++)
    {
      if(SZ(dt[i])!=0&&SZ(dt[i])<=26)continue;
      cout<<i<<endl;
      debug(dt[i]);
      return 0;
    }
    ll n;
    cin>>n;
    debug(dt[n]);
    if(n==0)
    {
      cout<<"a"<<endl;
      return 0;
    }
    REP(i,SZ(dt[n]))
    {
      REP(j,dt[n][i])cout<<char('a'+i);
    }
    cout<<endl;
}