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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e17);


ll w[MAXn],s[MAXn],p[MAXn],tw[MAXn],ss[MAXn],mx[MAXn],d[MAXn];
vector<ll> v[MAXn];
vector<ii> e;
vector<ll> dt[MAXn];
bool vis[MAXn];

ll dfs(ll now)
{
  ll tt=0;
  for(ll k:v[now])
  {
    tt+=dfs(k);
    if(SZ(dt[k])>SZ(dt[now]))dt[now].swap(dt[k]);
    for(ll tmp:dt[k])dt[now].pb(tmp);
    dt[k].clear();
  }
  debug(now,tt);
  while(tt>s[now])
  {
    if(!SZ(dt[now])){cout<<-1<<endl;exit(0);}
    ll t=dt[now].back();
    if(mx[t]-d[t]<=tt-s[now])//ALL
    {
      tt-=mx[t]-d[t];
      d[t]=mx[t];
      dt[now].pop_back();
      ss[p[t]]--;
      tw[p[t]]+=tw[t]+w[t]-mx[t];
      if(ss[p[t]]==0&&p[t]!=now)
      {
        dt[now].pb(p[t]);
        mx[p[t]]=min(w[p[t]]-1,s[p[t]]-tw[p[t]]);
      }
    }
    else//not all
    {
      d[t]+=tt-s[now];
      tt=s[now];
    }
  }
  if(ss[now]==0)
  {
    dt[now].pb(now);
    mx[now]=min(w[now]-1,s[now]-tw[now]);
  }
  return tt+w[now];
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n-1)
    {
      ll a,b,wi,si;
      cin>>a>>b>>wi>>si;
      e.pb(ii(a,b));
      p[b]=a;
      v[a].pb(b);
      ss[a]++;
      w[b]=wi;
      s[b]=si;
    }
    s[1]=INF;
    dfs(1);
    cout<<n<<endl;
    REP(i,n-1)
    {
      ll t=e[i].Y;
      cout<<e[i].X<<" "<<t<<" "<<w[t]-d[t]<<" "<<s[t]-d[t]<<endl;
    }
}