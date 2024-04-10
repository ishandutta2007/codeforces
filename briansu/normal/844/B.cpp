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

ll d[100][100];
ll ct[2][2][MAXn];

ll c[100][100];

ll ans=0;

void cal1(ll a)
{
  REP1(i,a)ans+=c[a][i];
}

void cal2(ll a)
{
  REP1(i,a-1)ans+=c[a][i+1];
}

int main()
{
    IOS();

    REP(i,60)REP(j,i+1)
    {
      if(j==0||j==i)c[i][j]=1;
      else c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    ll n,m;
    cin>>n>>m;
    REP(i,n)REP(j,m)
    {
      cin>>d[i][j];
      ct[d[i][j]][0][i]++;
      ct[d[i][j]][1][j]++;
    }
    REP(i,n)
    {
      cal1(ct[0][0][i]);
      cal1(ct[1][0][i]);
    }
    REP(i,m)
    {
      cal2(ct[0][1][i]);
      cal2(ct[1][1][i]);
    }
    cout<<ans<<endl;

}