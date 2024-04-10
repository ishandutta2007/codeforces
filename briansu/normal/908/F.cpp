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

#define G 0
#define B 1
#define R 2

vector<ii> v;



int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)
    {
      ll p;
      char c;
      cin>>p>>c;
      if(c == 'G')v.pb({p,G});
      if(c == 'R')v.pb({p,R});
      if(c == 'B')v.pb({p,B});
    }

    ll mxr = 0,mxb = 0,fgr = 0,fgb = 0,lstb = -1,lstr = -1,lstg = -1,ttr = 0,ttb = 0,tt = 0;
    for(ii pr:v)
    {
      ll p = pr.X,clr = pr.Y;
      if(clr == R)
      {
        if(lstr != -1)mxr = max(mxr,p - lstr),ttr += p - lstr;
        lstr = p;
        fgr = 1;
      }
      else if(clr == B)
      {
        if(lstb != -1)mxb = max(mxb,p - lstb),ttb += p - lstb;
        lstb = p;
        fgb = 1;
      }
      else // clr == G
      {
          if(fgr)mxr = max(mxr,p - lstr),ttr += p - lstr;
          if(fgb)mxb = max(mxb,p - lstb),ttb += p - lstb;

          if(lstg == -1)tt += ttr + ttb;
          else if(!fgr || !fgb)
          {
            tt += p - lstg;
            if(fgr)tt += ttr - mxr;
            if(fgb)tt += ttb - mxb;
          }
          else{
            tt += min(p - lstg + ttr - mxr + ttb - mxb,2 * (p-lstg));
          }
          mxr = 0,mxb = 0,fgr = 0,fgb = 0,lstb = p,lstr = p,lstg = p,ttr = 0,ttb = 0;
      }
    }
    tt += ttr + ttb;
    cout<<tt<<endl;
}