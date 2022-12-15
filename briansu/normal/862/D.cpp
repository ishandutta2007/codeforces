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
//#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll bk;
ll n;

ll ask(ll l,ll r)//[l,r)
{
  string s="";
  REP(i,n)if(i>=l&&i<r)s+="1";else s+="0";
  cout<<"? "<<s<<endl;
  ll t;
  cin>>t;
  return (bk-t+r-l)/2;
}

ll ans[2];

int main()
{
    IOS();
    cin>>n;
    string s="";
    REP(i,n)s+="0";
    cout<<"? "<<s<<endl;
    cin>>bk;
    ll l=0,r=n;

    while(1)
    {
      if(l==r-1)
      {
        ll t=ask(l,r);
        if(t)ans[1]=l;
        else ans[0]=l;
        break;
      }
      else
      {
        ll t=ask(l,(l+r)/2);
        if(t==0)
        {
          ans[0]=l;
          l=(l+r)/2;
        }
        else if(t==(l+r)/2-l)
        {
          ans[1]=l;
          l=(l+r)/2;
        }
        else r=(l+r)/2;
      }
    }
    cout<<"! "<<ans[0]+1<<" "<<ans[1]+1<<endl;
}