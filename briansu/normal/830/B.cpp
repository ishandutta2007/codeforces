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

ll bit[MAXn];
ll n;
ll d[MAXn];

void ins(ll x,ll k)
{
  x++;
  while(x<=n)bit[x]+=k,x+=x&-x;
}
ll qr(ll x)
{
  x++;ll rt=0;
  while(x>0)rt+=bit[x],x-=x&-x;
  return rt;
}
vector<ii> dt,tmpdt;
int main()
{
    IOS();
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n)ins(i+1,1);
    ll now=0;
    ll ans=0;
    REP(i,n)dt.pb(ii(d[i],i));
    sort(ALL(dt));
    debug(dt);
    ll it=0,ct=n;
    while(it<n)
    {
      ll mx=0,id,i;
      tmpdt.clear();
      for(i=it;i<n&&dt[i].X==dt[it].X;i++)
      {
        ll p=qr(dt[i].Y),t=(p+ct-now)%ct+1;
        tmpdt.pb(ii(t,dt[i].Y));
      }
      sort(ALL(tmpdt));
      for(ii tmp:tmpdt)
      {
        debug(tmp);
        ll p=qr(tmp.Y),t=(p+ct-now)%ct+1;
        ans+=t;
        ct--;
        now=p;
        if(ct)now%=ct;
        ins(tmp.Y,-1);
      }
      it=i;
      debug(ans);
    }
    cout<<ans<<endl;
}