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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn],pre[MAXn],prect[2][MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)
    {
      ll x,c = 0;
      cin>>x;
      while(x > 0)
      {
        if(x & 1)c++;
        x /= 2;
      }
      d[i] = c;
      pre[i] = c + pre[i-1];
      prect[pre[i] & 1][i]++;
      REP(j,2)prect[j][i] += prect[j][i-1];
    }
    pary(d+1,d+1+n);
    pary(pre+1,pre+1+n);
    pary(prect[0]+1,prect[0]+1+n);
    pary(prect[1]+1,prect[1]+1+n);
    ll tt = 0;
    REP1(i,n)
    {
      ll tmp = 0,mx = 0;
      for(int j = 0;j<60 && i + j <= n;j++)
      {
        tmp += d[i + j];
        mx = max(mx,d[i + j]);
        debug(i,j,tmp,mx);
        if(mx * 2 <= tmp && tmp % 2 == 0)tt++;
      }
      if(i + 59 < n)
      {
        if(pre[i-1] & 1)tt += prect[1][n] - prect[1][i + 59];
        else tt += prect[0][n] - prect[0][i + 59];
      }
    }
    cout<<tt<<endl;
}