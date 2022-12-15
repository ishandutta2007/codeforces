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

const ll K = 1516228;

int main()
{
    IOS();
    ll n,l,r,k;
    cin>>n>>l>>r>>k;
    ll a = (r - l + n) % n + 1,b = (n - a);
    debug(a,b);
    if(k - a<0)
    {
      cout<<-1<<endl;
      return 0;
    }
    if(n <= K)
    {
      ll mx = -1;
      REP(i,n+1)
      {
        {
          ll sa = (k-a) % (n+i);
          if(sa <= i && sa <= a && i - sa <= b)mx = i;
          debug(i,sa,mx);
        }

        if(i > 0 && a > 0)
        {
          ll sa = (k + 1 - a) % (n+i);
          if(sa >= 1 && sa <= i && sa <= a && i - sa <= b)mx = i;
          debug(i,sa,mx);
        }

      }
      cout<<mx<<endl;

      return 0;
    }
    else{
      ll ans = -1;
      for(ll R = 0;R * n <= k - a;R++)
      {
        ll C = k - a - n * R;
        if(R == 0)
        {
          if(C <= a)ans = max(ans,C + b);
          continue;
        }
        ll mx = (C + b) / (R + 1);
        mx = min(mx,n);
        mx = min(mx,C / R);
        ll sa = C - mx *  R;
        if(sa >= 0 && sa <= a && sa <= mx && mx - sa <= b)ans = max(ans,mx);
      }
      for(ll R = 0;R * n <= k + 1 - a;R++)
      {
        ll C = k + 1 - a - n * R;
        if(R == 0)
        {
          if(C <= a && C >= 1)ans = max(ans,C + b);
          continue;
        }
        ll mx = (C + b) / (R + 1);
        mx = min(mx,n);
        if(C == 0)continue;
        mx = min(mx,(C-1) / R);
        ll sa = C - mx *  R;
        if(sa >= 1 && sa <= a && sa <= mx && mx - sa <= b)ans = max(ans,mx);
      }
      //
      cout<<ans<<endl;
      return 0;
    }

}