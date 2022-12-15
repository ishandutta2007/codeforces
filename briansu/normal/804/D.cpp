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

map<ii,double> mp;
ll n,m,q;
vector<ll> v[MAXn];
ll g[MAXn],h[MAXn][2],mx[MAXn];
bool vis[MAXn];
vector<ll> fd[MAXn],pre[MAXn];

void dfs(ll now,ll f,ll git)
{
  g[now]=git;
  vis[now]=1;
  for(ll k:v[now])
  {
    if(k==f)continue;
    dfs(k,now,git);
    if(h[k][0]+1>=h[now][0])
    {
      h[now][1]=h[now][0];
      h[now][0]=h[k][0]+1;
    }
    else if(h[k][0]+1>h[now][1])h[now][1]=h[k][0]+1;
  }
  mx[git]=max(mx[git],h[now][0]+h[now][1]);
}

void dfs2(ll now,ll f,ll mxd)
{
  vis[now]=1;
  fd[g[now]].pb(max(mxd,h[now][0]));

  for(ll k:v[now])
  {
    if(k==f)continue;
    if(h[k][0]+1==h[now][0])dfs2(k,now,max(mxd+1,h[now][1]+1));
    else dfs2(k,now,max(mxd+1,h[now][0]+1));
  }
}
int main()
{
    IOS();
    cin>>n>>m>>q;
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    ll gcnt=0;
    REP(i,n)if(!vis[i])dfs(i,-1,gcnt++);
    FILL(vis,0);
    REP(i,n)if(!vis[i])dfs2(i,-1,0);
    REP(i,gcnt)
    {
      sort(ALL(fd[i]));
      pre[i].pb(0);
      for(ll k:fd[i])pre[i].pb(pre[i].back()+k);
      debug(i,fd[i],pre[i]);
    }
    REP(i,q)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      a=g[a];b=g[b];
      if(a==b)
      {
        cout<<-1<<endl;
        continue;
      }
      ii qr=ii(min(a,b),max(a,b));
      if(!mp.count(qr))
      {
        if(SZ(fd[a])>SZ(fd[b]))swap(a,b);
        double tmp=0;
        ll tmx=max(mx[a],mx[b]);
        for(ll k:fd[a])
        {
          ll t=upper_bound(ALL(fd[b]),tmx-k-1)-fd[b].begin();
          tmp+=(SZ(fd[b])-t)*(k+1)+pre[b][SZ(fd[b])]-pre[b][t];
          tmp+=t*tmx;
        }
        assert(tmp>=0);
        mp[qr]=double(tmp)/double(ll(SZ(fd[a]))*ll(SZ(fd[b])));
      }
      cout<<fixed<<setprecision(9)<<mp[qr]<<endl;
    }
}