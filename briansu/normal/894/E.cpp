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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ii> v[MAXn],vr[MAXn],v3[MAXn];
vector<ll> dt,dt2,tp;
ll dp[MAXn],g[MAXn],tt[MAXn],vis[MAXn];

void dfs1(ll now)
{
  vis[now]=1;
  for(ii k:v[now])if(!vis[k.X])dfs1(k.X);
  tp.pb(now);
}

void dfs2(ll now,ll gi)
{
  vis[now]=1;g[now]=gi;
  for(ii k:vr[now])if(!vis[k.X])dfs2(k.X,gi);
}

ll cal(ll x)
{
    ll tmp=upper_bound(ALL(dt),x)-dt.begin();
    return x*tmp-dt2[tmp-1];
}

void dfs3(ll now)
{
  dp[now]=tt[now];vis[now]=1;
  for(ii k:v3[now])
  {
    if(!vis[k.X])dfs3(k.X);
    dp[now]=max(dp[now],tt[now]+dp[k.X]+k.Y);
  }
}

int main()
{
    IOS();

    ll sum = 0;
    for(ll i=1;i*(i-1)/2 <= 100000000;i++)
    {
      dt.pb(i*(i-1)/2);
      dt2.pb(sum);
      sum+=i*(i+1)/2;
    }

    ll n,m;
    cin>>n>>m;
    ll it=0;
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      v[a-1].pb(ii(b-1,c));
      vr[b-1].pb(ii(a-1,c));
    }

    FILL(vis,0);
    REP(i,n)if(!vis[i])dfs1(i);

    reverse(ALL(tp));
    FILL(vis,0);
    REP(i,n)if(!vis[tp[i]])dfs2(tp[i],it++);

    tp.clear();
    REP(i,n)for(ii k:v[i])if(g[i]==g[k.X])tt[g[i]]+=cal(k.Y);else v3[g[i]].pb(ii(g[k.X],k.Y));

    FILL(vis,0);
    FILL(dp,-1);
    ll s;cin>>s;
    dfs3(g[s-1]);
    cout<<dp[g[s-1]]<<endl;

}