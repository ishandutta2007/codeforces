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


const ll MAXn=3e5+5,MAXc=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll bit[MAXn];
void ins(ll x,ll k)
{
  while(x<MAXn)bit[x]+=k,x+=x&-x;
}
ll qr(ll x)
{
  ll rt=0;
  while(x)rt+=bit[x],x-=x&-x;
  return rt;
}

set<ll> st;
ll mnpm[MAXc];
vector<ll> pm;
ll D[MAXc],d[MAXn];

int main()
{
    IOS();
    for(ll i=2;i<MAXc;i++)
    {
      if(!mnpm[i])pm.pb(i);
      for(int j=0;pm[j]*i<MAXc;j++)
      {
        mnpm[pm[j]*i]=pm[j];
        if(i%pm[j]==0)break;
      }
    }
    D[1]=1;
    for(int i=2;i<MAXc;i++)
    {
      if(!mnpm[i])D[i]=2;
      else
      {
        ll ct=0,tmp=i;
        while(tmp%mnpm[i]==0)ct++,tmp/=mnpm[i];
        D[i]=D[tmp]*(ct+1);
      }
    }
    pary(D+1,D+10+1);
    ll n,q;
    cin>>n>>q;
    REP1(i,n)
    {
      cin>>d[i];
      ins(i,d[i]);
      if(d[i]>2)st.insert(i);
    }
    debug(st);
    while(q--)
    {
      ll tp,a,b;
      cin>>tp>>a>>b;
      if(tp==1)
      {
        while(1)
        {
          auto it=st.lower_bound(a);
          if(it==st.end()||*it>b)break;
          ll t=*it;
          ins(t,D[d[t]]-d[t]);
          d[t]=D[d[t]];
          if(d[t]==2)st.erase(it);
          a=t+1;
        }
        debug(st);
        pary(d+1,d+1+n);
      }
      else cout<<qr(b)-qr(a-1)<<endl;
    }

}