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

ll d[MAXn][MAXn],dis[MAXn][MAXn];

priority_queue<pair<ll,ii>,vector<pair<ll,ii>>,greater<pair<ll,ii>> > pq;

void go(ll x,ll y,ll ds)
{
  if(d[x][y] && ds < dis[x][y])
  {
    pq.push({ds,{x,y}});
    dis[x][y] = ds;
  }
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    ii st;
    cin>>st.X>>st.Y;
    ll l,r;
    cin>>l>>r;
    REP1(i,n)
    {
      string s;
      cin>>s;
      REP1(j,m)if(s[j-1] == '.')d[i][j] = 1;
    }
    REP1(i,n)REP1(j,m)dis[i][j] = INF;
    dis[st.X][st.Y] = 0;
    pq.push({0,st});
    while(SZ(pq))
    {
      while(SZ(pq) && dis[pq.top().Y.X][pq.top().Y.Y] != pq.top().X)pq.pop();
      if(!SZ(pq))break;
      ll x = pq.top().Y.X,y = pq.top().Y.Y;
      pq.pop();
      go(x-1,y,dis[x][y]);
      go(x,y-1,dis[x][y]+1);
      go(x+1,y,dis[x][y]);
      go(x,y+1,dis[x][y]);
    }
    ll tt = 0;
    //REP1(i,n)REP1(j,m)if(d[i][j])debug(i,j,dis[i][j],dis[i][j]!=INF && dis[i][j] <= l && dis[i][j] - (st.X - i) <= r);
    REP1(i,n)REP1(j,m)if(d[i][j])
    {
      if(dis[i][j]!=INF && dis[i][j] <= l && dis[i][j] - (st.Y - j) <= r)tt++;
    }
    cout<<tt<<endl;
}