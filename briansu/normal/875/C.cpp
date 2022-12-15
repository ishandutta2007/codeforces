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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

bool r[MAXn];

vector<vector<ll> > d;

vector<ii> mp[MAXn];
queue<ii> q;

void qt()
{
  cout<<"No"<<endl;
  exit(0);
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,n)
    {
      ll l;
      cin>>l;
      vector<ll> tmp;
      REP(j,l)
      {
        ll t;
        cin>>t;
        tmp.pb(t);
      }
      d.pb(tmp);
    }

    REP(i,n-1)q.push(ii(i,0));

    while(SZ(q))
    {
      debug(q.front());
      ll t=q.front().X,it=q.front().Y;
      q.pop();
      if(it>=min(SZ(d[t]),SZ(d[t+1])))
      {
        if(SZ(d[t])>SZ(d[t+1]))qt();
        else continue;
      }
      if(d[t][it]==d[t+1][it])
      {
        q.push(ii(t,it+1));
        continue;
      }
      ll a=d[t][it],b=d[t+1][it];
      if(a<b)
      {
        if(r[a])continue;
        if(r[b])
        {
          debug(a);
          r[a]=1;
          for(ii tmp:mp[a])q.push(tmp);
          continue;
        }
        else mp[b].pb(ii(t,it));
      }
      else
      {
        if(r[b])qt();
        if(r[a])mp[b].pb(ii(t,it));
        else
        {
          debug(a);
          r[a]=1;
          for(ii tmp:mp[a])q.push(tmp);
          mp[b].pb(ii(t,it));
          continue;
        }
      }
    }
    cout<<"Yes"<<endl;
    vector<ll> dt;
    REP1(i,m)if(r[i])dt.pb(i);
    cout<<SZ(dt)<<endl;
    for(ll k:dt)cout<<k<<" ";
    cout<<endl;

}