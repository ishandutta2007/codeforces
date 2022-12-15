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


const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);


map<ii,ll> d;
map<ii,bool> vis;
ll bx[2][MAXn],by[2][MAXn];
vector<ll> v[MAXn];
ll dis[MAXn],vs2[MAXn];

void maxfy(ll &a,ll b){a=max(a,b);}
void minfy(ll &a,ll b){a=min(a,b);}

void dfs(ll x,ll y,ll c)
{
  vis[ii(x,y)]=1;
  d[ii(x,y)]=c+1;
  minfy(bx[0][c],x);
  minfy(by[0][c],y);
  maxfy(bx[1][c],x);
  maxfy(by[1][c],y);
  ll dx[4]={1,-1,0,0};
  ll dy[4]={0,0,1,-1};
  REP(i,4)
  {
    ll a=x+dx[i],b=y+dy[i];
    if(d.count(ii(a,b))&&!vis.count(ii(a,b)))dfs(a,b,c);
  }
}

bool chk(ii a,ii b)
{
  if(a>b)swap(a,b);
  debug(a,b,a.Y-b.X>=-2);
  if(a.Y-b.X>=-2)return 1;
  else return 0;
}
queue<ll> q;
vector<ii> dt;

int main()
{
    IOS();
    ll n,m,k;
    cin>>n>>m>>k;
    REP1(i,k)
    {
      ll x,y;
      cin>>x>>y;
      d[ii(x,y)]=i;
      dt.pb(ii(x,y));
    }
    ll it=-1;
    for(ii &tmp:dt)
    {
      ll i=tmp.X,j=tmp.Y;
      if(!vis.count(tmp))
      {
        it++;
        bx[0][it]=bx[1][it]=i;
        by[0][it]=by[1][it]=j;
        dfs(i,j,it);
      }
    }
    REP(i,it+1)for(int j=i+1;j<=it;j++)
    {
      if(chk(ii(bx[0][i],bx[1][i]),ii(bx[0][j],bx[1][j]))||chk(ii(by[0][i],by[1][i]),ii(by[0][j],by[1][j])))v[i].pb(j),v[j].pb(i);
    }
    REP(i,it+1)dis[i]=INF;
    dis[0]=0;
    q.push(0);
    while(SZ(q))
    {
      while(SZ(q)&&vs2[q.front()])q.pop();
      if(!SZ(q))break;
      ll t=q.front();
      q.pop();
      vs2[t]=1;
      for(ll tmp:v[t])if(!vs2[tmp]&&dis[tmp]>dis[t]+1)
      {
        dis[tmp]=dis[t]+1;
        q.push(tmp);
      }
    }

    ll ans=INF;
    for(ii &tmp:dt)
    {
      if(tmp.X>=n-1||tmp.Y>=m-1)minfy(ans,dis[d[tmp]-1]+1);
    }
    if(d.count(ii(n,m)))minfy(ans,dis[d[ii(n,m)]-1]);
    pary(dis,dis+it+1);
    cout<<(ans==INF?-1:ans)<<endl;

}