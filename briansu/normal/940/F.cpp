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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct chtg{int t,x,a,b;};
ll l[MAXn],r[MAXn],ct[MAXn],ctct[MAXn];
vector<chtg> ch;
vector<ll> uni,qr;
ll d[MAXn];

void add(ll x)
{
  x=d[x];
  if(ct[x]>=0)ctct[ct[x]]--;
  ct[x]++;
  if(ct[x]>=0)ctct[ct[x]]++;
}
void rm(ll x)
{
  x=d[x];
  if(ct[x]>=0)ctct[ct[x]]--;
  ct[x]--;
  if(ct[x]>=0)if(ct[x]>=0)ctct[ct[x]]++;
}
ll cal()
{
  for(int i=0;;i++)if(ctct[i]==0)return i;
}
ll ans[MAXn];
int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP1(i,n)cin>>d[i],uni.pb(d[i]);
    REP(i,q)
    {
      ll tp,a,b;
      cin>>tp>>a>>b;
      if(tp==1)
      {
        qr.pb(i);
        l[i]=a,r[i]=b+1;
      }
      else
      {
        ch.pb({i,a,d[a],b});
        uni.pb(b);
        d[a]=b;
      }
    }
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());
    REP1(i,n)d[i]=lower_bound(ALL(uni),d[i])-uni.begin()+1;
    REP(i,SZ(ch))
    {
      ch[i].a=lower_bound(ALL(uni),ch[i].a)-uni.begin()+1;
      ch[i].b=lower_bound(ALL(uni),ch[i].b)-uni.begin()+1;
    }
    ctct[0]=SZ(uni)+1;
    ll K=max(1,(int)pow(n,0.66666));
    auto func=[&](int a){return make_tuple(l[a]/K,r[a]/K,a);};
    sort(ALL(qr),[&](int a,int b){return func(a)<func(b);});

    ll itl=1,itr=1,itt=SZ(ch);
    for(ll t:qr)
    {
      while(itr<r[t])add(itr++);
      while(itr>r[t])rm(--itr);
      while(itl<l[t])rm(itl++);
      while(itl>l[t])add(--itl);
      while(itt<SZ(ch)&&ch[itt].t<t){
        if(ch[itt].x>=l[t]&&ch[itt].x<r[t])rm(ch[itt].x),d[ch[itt].x]=ch[itt].b,add(ch[itt].x);
        else d[ch[itt].x]=ch[itt].b;
        itt++;
      }
      while(itt&&ch[itt-1].t>t){
        itt--;
        if(ch[itt].x>=l[t]&&ch[itt].x<r[t])rm(ch[itt].x),d[ch[itt].x]=ch[itt].a,add(ch[itt].x);
        else d[ch[itt].x]=ch[itt].a;
      }
      ans[t]=cal();
    }
    sort(ALL(qr));
    for(ll t:qr)cout<<ans[t]<<endl;

}