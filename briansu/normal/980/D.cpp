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


const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn],sn[MAXn];
ll a[MAXn];
vector<ll> pm;
bool ispm[10000+5];

int pos[MAXn],neg[MAXn];
vector<ll> uni;

int main()
{
    IOS();
    for(int i=2;i<=10000;i++)
    {
      if(!ispm[i])pm.pb(i);
      for(int j=0;i*pm[j]<=10000;j++)
      {
        ispm[i*pm[j]] = 1;
        if(i%pm[j]==0)break;
      }
    }
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n)
    {
      if(d[i]<0)sn[i]=-1;
      else if(d[i]==0)sn[i]=0;
      else sn[i]=1;
      d[i]=abs(d[i]);
      REP(j,SZ(pm))
      {
        ll tmp = pm[j]*pm[j];
        if(tmp>d[i])break;
        while(d[i]%tmp==0)d[i]/=tmp;
      }
      if(sn[i]!=0)uni.pb(d[i]);
    }
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());
    REP(i,n)if(sn[i]!=0)d[i] = lower_bound(ALL(uni),d[i]) - uni.begin() + 1;
    REP(i,n)
    {

      ll fg=0,tt=0;
      for(int j=i;j<n;j++)
      {
        if(sn[j]>0)pos[d[j]]++,tt+=(pos[d[j]]==1);
        else if(sn[j]<0)neg[d[j]]++,tt+=(neg[d[j]]==1);
        else fg=1;
        if(fg)a[max(tt,1LL)]++;
        else a[tt]++;
      }
      for(int j=i;j<n;j++)
      {
        if(sn[j]>0)pos[d[j]]=0;
        else if(sn[j]<0)neg[d[j]]=0;
      }
    }
    REP1(i,n)cout<<a[i]<<" ";
}