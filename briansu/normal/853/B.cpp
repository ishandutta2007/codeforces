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


const ll MAXn=1e5+5,MAXk=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



struct flt{
  ll x,a,b,c;
};
flt d[MAXn];
vector<flt> go,bk;

vector<ii> god,bkd;
ll gomn[MAXn],bkmn[MAXn];

int main()
{
    IOS();
    ll n,m,k;
    FILL(gomn,-1);
    FILL(bkmn,-1);
    cin>>n>>m>>k;
    REP(i,m)
    {
      cin>>d[i].x>>d[i].a>>d[i].b>>d[i].c;
      if(d[i].b==0)go.pb(d[i]);
      else bk.pb(d[i]);
    }
    stable_sort(ALL(go),[](flt a,flt b){return a.x<b.x;});
    stable_sort(ALL(bk),[](flt a,flt b){return a.x>b.x;});

    ll it=0,ng=n,tt=0;
    while(it<SZ(go))
    {
        ll now=go[it].x;
        while(it<SZ(go)&&go[it].x==now)
        {
          ll t=go[it].a;
          ll c=go[it].c;
          if(gomn[t]==-1)
          {
            gomn[t]=c;
            tt+=c;
            ng--;
          }
          else if(c<gomn[t])
          {
            tt-=gomn[t]-c;
            gomn[t]=c;
          }
          it++;
        }
        if(!ng)god.pb(ii(now,tt));
    }

    it=0,ng=n,tt=0;
    while(it<SZ(bk))
    {
        ll now=bk[it].x;
        while(it<SZ(bk)&&bk[it].x==now)
        {
          ll t=bk[it].b;
          ll c=bk[it].c;
          if(bkmn[t]==-1)
          {
            bkmn[t]=c;
            tt+=c;
            ng--;
          }
          else if(c<bkmn[t])
          {
            tt-=bkmn[t]-c;
            bkmn[t]=c;
          }
          it++;
        }
        if(!ng)bkd.pb(ii(now,tt));
    }

    reverse(ALL(bkd));

    ll ans=-1;

    for(ii &tmp:god)
    {
      auto t=lower_bound(ALL(bkd),ii(tmp.X+k+1,-1));
      if(t!=bkd.end())
      {
        ll aa=tmp.Y+t->Y;
        if(ans==-1||ans>aa)ans=aa;
      }
    }
    cout<<ans<<endl;

}