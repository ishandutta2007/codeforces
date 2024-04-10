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
const ll INF=ll(1e17);

vector<ii> v[MAXn];
ll n,m,dph[MAXn],dis[30][MAXn],p[MAXn][MAXlg],tt[MAXn][MAXlg],it = 0;

void dij(ll s)
{
  priority_queue<ii,vector<ii>, greater<ii> > pq;
  REP(i,n)dis[it][i] = INF;
  dis[it][s] = 0;
  pq.push(ii(0,s));
  while(SZ(pq))
  {
    while(SZ(pq)&&dis[it][pq.top().Y] != pq.top().X)pq.pop();
    if(!SZ(pq))break;
    ll t = pq.top().Y;pq.pop();
    for(ii k:v[t])
    {
      if(dis[it][k.X] > dis[it][t] + k.Y)
      {
        dis[it][k.X] = dis[it][t] + k.Y;
        pq.push(ii(dis[it][k.X],k.X));
      }
    }
  }
  it ++;
}

void dfs(ll now,ll f)
{
  for(ii k:v[now])if(k.X != f)
  {
    if(dph[k.X] == -1)
    {
      dph[k.X] = dph[now] + 1;
      p[k.X][0] = now;
      tt[k.X][0] = k.Y;
      debug(k);
      dfs(k.X,now);
    }
    else if(dph[k.X] < dph[now])dij(now);
  }
}

ll lca(ll a,ll b)
{
  ll res = 0;
  if(dph[a] < dph[b])swap(a,b);
  for(int i = MAXlg-1;i>=0;i--)if(dph[p[a][i]] >= dph[b])res+=tt[a][i],a = p[a][i];
  if(a==b)return res;
  for(int i = MAXlg-1;i>=0;i--)if(p[a][i] != p[b][i])res += tt[a][i] + tt[b][i],a=p[a][i],b=p[b][i];
  return res + tt[a][0] + tt[b][0];
}

int main()
{
    IOS();
    cin>>n>>m;
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      v[a].pb(ii(b,c));
      v[b].pb(ii(a,c));
    }
    FILL(dph,-1);
    dph[0] = 0;
    dfs(0,-1);
    pary(dph,dph+n);
    REP1(j,MAXlg - 1)REP(i,n)p[i][j] = p[p[i][j-1]][j-1],tt[i][j] = tt[i][j-1] + tt[p[i][j-1]][j-1];
    REP(i,n)REP(j,MAXlg)debug(i,j,tt[i][j]);
    ll q;
    cin>>q;
    while(q--)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      ll x = lca(a,b);
      ll tmp = x;
      debug(a,b,x,tmp);
      REP(i,it)
      {
        tmp = min(tmp,dis[i][a] + dis[i][b]);
      }
      cout<<tmp<<endl;
    }
}