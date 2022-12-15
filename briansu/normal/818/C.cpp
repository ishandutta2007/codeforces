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

ll d[MAXn][4];

ll dt[4][MAXn];// l,r,d,u

int main()
{
    IOS();
    ll n;
    cin>>n;
    ll r,c;
    cin>>r>>c;
    REP(i,n)
    {
      cin>>d[i][0]>>d[i][2]>>d[i][1]>>d[i][3];
      if(d[i][0]>d[i][1])swap(d[i][0],d[i][1]);
      if(d[i][2]>d[i][3])swap(d[i][2],d[i][3]);
      REP(j,4)dt[j][d[i][j]]++;
    }
    REP1(i,MAXn-1)dt[0][i]+=dt[0][i-1],dt[2][i]+=dt[2][i-1];
    for(int i=MAXn-2;i>=0;i--)dt[1][i]+=dt[1][i+1],dt[3][i]+=dt[3][i+1];

    ll g[4];
    REP(i,4)cin>>g[i];

    REP(i,n)
    {
      ll t[4];
      t[0]=dt[0][d[i][1]-1];
      t[1]=dt[1][d[i][0]+1];
      t[2]=dt[2][d[i][3]-1];
      t[3]=dt[3][d[i][2]+1];

      if(d[i][1]!=d[i][0])t[0]--,t[1]--;
      else t[2]--,t[3]--;
      pary(t,t+4);
      bool b=1;
      REP(j,4)if(t[j]!=g[j])b=0;
      if(b){cout<<i+1<<endl;return 0;}
    }
    cout<<-1<<endl;
}