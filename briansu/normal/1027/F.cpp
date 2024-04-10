//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll INF=ll(1e9) + 10;

ll a[MAXn],b[MAXn],vis[MAXn],egs[MAXn];
vector<ll> uni,v[MAXn];
int main()
{
    IOS();
    ll n;
    cin>>n;
    //n = 1000000;
    REP(i,n)cin>>a[i]>>b[i];//a[i] = (9487234 ^ i), b[i] = (381245401 ^ i);
    REP(i,n)uni.pb(a[i]),uni.pb(b[i]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    debug(uni);
    REP(i,n)a[i] = lower_bound(ALL(uni),a[i]) - uni.begin(),b[i] = lower_bound(ALL(uni),b[i]) - uni.begin(),v[a[i]].pb(b[i]),v[b[i]].pb(a[i]),egs[a[i]]++;
    ll l = -1,r = SZ(uni);
    REP(i,n)debug(i,a[i],b[i]);
    while(l!=r-1)
    {
      ll h = (l + r)/2,ok=1;
      debug(l,r,h,uni[h]);
      REP(i,n)if(a[i] > h){
        l = h;
        ok=0;
        break;
      }
      debug(ok);
      if(!ok)continue;
      memset(vis,0,sizeof(ll) * (h+1));
      vector<ll> stk;
      REP(i,n)if(!vis[i]){
        stk.pb(i);
        vis[i] = 1;
        ll pt = 0,eg = 0;
        while(SZ(stk))
        {
          ll t = stk.back();
          stk.pop_back();
          eg += egs[t];
          pt++;
          for(ll k:v[t])if(k <= h && !vis[k]){
            vis[k] = 1;
            stk.pb(k);
          }
        }
        debug(h,uni[h],i,uni[i],pt,eg);
        if(pt < eg){
          ok = 0;
          break;
        }
      }

      if(!ok)l = h;
      else r = h;
    }
    if(r == SZ(uni))cout<<-1<<endl;
    else cout<<uni[r]<<endl;
}