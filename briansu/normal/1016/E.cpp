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
const lf eps = 1e-9;

vector<ii> f;
ll pre[MAXn];

ll sy,a,b,n;

lf proj(ll x,ll y,ll p){
  return lf(p - x) * lf(y-sy) / lf(y) + lf(x);
}

int main()
{
    IOS();
    cin>>sy>>a>>b>>n;
    REP1(i,n)
    {
      ll l,r;
      cin>>l>>r;
      f.pb({l,r});
      pre[i] = r-l;
      pre[i] += pre[i-1];
    }
    ll Q;
    cin>>Q;
    while(Q--)
    {
      ll x,y;
      cin>>x>>y;
      lf pa = lf(a - x) * lf(y) / lf(y-sy) + lf(x);
      lf pb = lf(b - x) * lf(y) / lf(y-sy) + lf(x);
      ll l = -1,r = n;
      while(l!=r-1)
      {
        ll h = (l+r)/2;
        if(f[h].Y > pa)r = h;
        else l = h;
      }
      ll p = r;
      //ll p = upper_bound(ALL(f),make_pair(pa,pa),[](pair<lf,lf> a,pair<lf,lf> b){return pair<lf,lf>(a.Y,a.X) < pair<lf,lf>(b.Y,b.X);}) - f.begin();
      if(p == n)
      {
        cout<<0<<endl;
        continue;
      }
      l = p-1,r = n;
      while(l!=r-1)
      {
        ll h = (l+r)/2;
        if(f[h].X >= pb)r = h;
        else l = h;
      }
      ll q = r;
      //ll q = lower_bound(f.begin() + p,f.end(),make_pair(pb,pb)) - f.begin();
      if(p == q)
      {
        cout<<"0.0000000000000"<<endl;
        continue;
      }
      lf tt = 0;
      q--;
      if(p!=q)
      {
        tt = lf(pre[q] - pre[p+1]) * lf(y - sy) / y;
        tt += min(lf(b),proj(x,y,f[p].Y)) -  max(lf(a),proj(x,y,f[p].X));
        tt += min(lf(b),proj(x,y,f[q].Y)) -  max(lf(a),proj(x,y,f[q].X));

      }else{
        tt += min(lf(b),proj(x,y,f[p].Y)) -  max(lf(a),proj(x,y,f[p].X));
      }
      //tt = proj()
      cout<<fixed<<setprecision(12)<<tt<<endl;
    }
}