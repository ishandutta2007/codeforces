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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int d[MAXn],dt[MAXn],pr[MAXn][5],bk[MAXn][5],md[MAXn][MAXn][3][3];

int main()
{
    IOS();
    ll mx=1;
    ll n;
    cin>>n;
    REP1(i,n)cin>>d[i];
    REP1(i,n)
    {
      pr[i][1]=pr[i-1][1];
      pr[i][2]=pr[i-1][2];
      if(d[i]==1)pr[i][1]++;
      else pr[i][2]=max(pr[i][1],pr[i][2])+1;
    }
    for(int i=n;i>=1;i--)
    {
      bk[i][1]=bk[i+1][1];
      bk[i][2]=bk[i+1][2];
      if(d[i]==2)bk[i][2]++;
      else bk[i][1]=max(bk[i][1],bk[i][2])+1;
    }
    REP1(i,n)
    {
      ll t;
      if(d[i]==1)t=2;
      else t=1;
      md[i][i][t][t]=1;
      for(int j=i+1;j<=n;j++)
      {
        ll p;
        if(d[j]==1)p=2;
        else p=1;
        REP1(x,2)REP1(y,2)md[i][j][x][y]=md[i][j-1][x][y];
        if(p==1)md[i][j][1][1]++;
        else md[i][j][1][2]=max(md[i][j][1][2],md[i][j][1][1])+1,md[i][j][2][2]++;
      }
    }
    REP1(i,n)for(int j=i-1;j<=n;j++)
    {
      REP1(x,2)REP1(y,2)if(x<=y)
      {
        ll a,b;
        if(x==1)a=pr[i-1][1];
        else a=max(pr[i-1][1],pr[i-1][2]);
        if(y==2)b=bk[j+1][2];
        else b=max(bk[j+1][1],bk[j+1][2]);
        mx=max(mx,md[i][j][x][y]+a+b);
      }
    }

    cout<<mx<<endl;
}