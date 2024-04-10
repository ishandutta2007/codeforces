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


struct pt{
  ll tp,x,id;
  pt(ll tpi,ll xi,ll idi):tp(tpi),x(xi),id(idi){}

};

vector<pt> dt[2*MAXn];
ii ans[MAXn];

vector<ii> tmp;

int main()
{
    IOS();
    ll n,w,h;
    cin>>n>>w>>h;
    REP(i,n)
    {
      ll tp,x,t;
      cin>>tp>>x>>t;
      dt[x-t+MAXn].pb(pt(tp,x,i));
    }
    REP(i,2*MAXn)if(SZ(dt[i]))
    {
      stable_sort(ALL(dt[i]),[](pt a,pt b){
        if(a.tp!=b.tp)return a.tp>b.tp;
        if(a.tp==1)return a.x>b.x;
        else return a.x<b.x;
      });
      tmp.clear();
      REP(j,SZ(dt[i]))
      {
        if(dt[i][j].tp==1)tmp.pb(ii(dt[i][j].x,h));
        else tmp.pb(ii(w,dt[i][j].x));
      }
      stable_sort(ALL(dt[i]),[](pt a,pt b){
        if(a.tp!=b.tp)return a.tp<b.tp;
        if(a.tp==1)return a.x>b.x;
        else return a.x<b.x;
      });

      REP(j,SZ(dt[i]))ans[dt[i][j].id]=tmp[j];
    }
    REP(i,n)cout<<ans[i].X<<" "<<ans[i].Y<<endl;
}