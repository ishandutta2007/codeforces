//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

ii p[MAXn];
vector<ii> v[MAXn],dt[MAXn];
vector<ll> pre[MAXn];


void dfs(ll now)
{
  dt[now].pb(ii(0,now));
  for(ii &k:v[now])
  {
    dfs(k.X);
    for(ii &tmp:dt[k.X])dt[now].pb(ii(tmp.X+k.Y,tmp.Y));
    //dt[now].pb(ii(k.Y,k.X));
  }
  if(SZ(v[now])==2)inplace_merge(dt[now].begin()+1,dt[now].begin()+1+SZ(dt[v[now][0].X]),dt[now].end());
  pre[now].pb(0);
  for(ii &tmp:dt[now])pre[now].pb(pre[now].back()+tmp.X);
}

int main()
{
    IOS();
    ll q,n;
    cin>>n>>q;
    REP1(i,n-1)
    {
      ll t;
      cin>>t;
      p[i+1]=ii((i+1)/2,t);
      v[(i+1)/2].pb(ii(i+1,t));
    }
    dfs(1);
    REP1(i,n)debug(i,dt[i],pre[i]);
    REP(T,q)
    {
      ll x,h;
      cin>>x>>h;
      ll ct=0,tt=0,s=0,tmph=h;
      while(h>0)
      {
        ll a=lower_bound(ALL(dt[x]),ii(h,-1))-dt[x].begin();
        tt+=pre[x][a]+a*s;ct+=a;
        debug(T,dt[x],pre[x],s,h,a,ct,tt);
        if(x==1)break;

        ll b=lower_bound(ALL(dt[x]),ii(h-2*p[x].Y,-1))-dt[x].begin();
        ct-=b;tt-=pre[x][b]+(p[x].Y)*b+b*(s+p[x].Y);
        debug(T,h,b,ct,tt);
        s+=p[x].Y,h-=p[x].Y;x=p[x].X;
      }
      cout<<ct*tmph-tt<<endl;
    }
}