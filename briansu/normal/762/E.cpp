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


struct node
{
  ll l,r;
  node *lc,*rc;
  ll d;
  node (ll li,ll ri):l(li),r(ri),lc(0),rc(0),d(0){}
  void ins(int x)
  {
    if(l==r-1)d++;
    else
    {
      if(x<(l+r)/2)
      {
        if(!lc)lc=new node(l,(l+r)/2);
        lc->ins(x);
      }
      else
      {
        if(!rc)rc=new node((l+r)/2,r);
        rc->ins(x);
      }
      d=(lc?lc->d:0)+(rc?rc->d:0);
    }
    //debug(l,r,x,d);
  }
  ll qr(ll li,ll ri)
  {
    debug(l,r,li,ri,d);
    if(li>=r||ri<=l)return 0;
    else if(li<=l&&ri>=r)return d;
    else
    {
      ll t=0;
      if(lc)t+=lc->qr(li,ri);
      if(rc)t+=rc->qr(li,ri);
      return t;
    }
  }
};

const ll MAXf=1e4+5,MAXc=1e9+5;
node *rt[MAXf];
ll p[MAXn],r[MAXn],f[MAXn];
ll d[MAXn];
int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP(i,n)cin>>p[i]>>r[i]>>f[i];
    REP(i,n)d[i]=i;
    sort(d,d+n,[](int a,int b){return r[a]>r[b];});
    REP(i,MAXf)rt[i]=new node(0,MAXc);
    ll ans=0;
    REP(i,n)
    {
      for(int t=max(1LL,f[d[i]]-k);t<=f[d[i]]+k&&t<MAXf;t++)ans+=rt[t]->qr(max(0LL,p[d[i]]-r[d[i]]),min(MAXc,p[d[i]]+r[d[i]]+1));
      rt[f[d[i]]]->ins(p[d[i]]);
    }
    cout<<ans<<endl;
}