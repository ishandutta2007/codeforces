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

set<ii> st;
ll tt=0;
void rm(ll l,ll r){//[l,r]
  auto itl = st.lower_bound(ii(l,-1)),itpl=itl;
  bool fg=0;
  if(itpl!=st.begin())itpl=prev(itpl),fg=1;
  for(auto it = itl;it!=st.end()&&it->X<=r;tt+=it->X,tt-=it->Y+1,it=st.erase(it))
  {
    if(it->Y>r)
    {
      ii tmp = *it;
      st.erase(it);
      st.insert(ii(r+1,tmp.Y));
      tt-=r-tmp.X+1;
      break;
    }
  }
  if(fg&&itpl->Y>r)
  {
    ii tmp=*itpl;
    st.erase(itpl);
    st.insert(ii(tmp.X,l-1));
    st.insert(ii(r+1,tmp.Y));
    tt-=r-l+1;
  }
  else if(fg&&itpl->Y>=l)
  {
    ii tmp=*itpl;
    st.erase(itpl);
    st.insert(ii(tmp.X,l-1));
    tt-=tmp.Y-l+1;
  }
}

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP(i,q)
    {
      ll l,r,k;
      cin>>l>>r>>k;
      rm(l,r);
      debug(st,tt);

      if(k==1)st.insert(ii(l,r)),tt-=l,tt+=r+1;
      cout<<n-tt<<endl;
    }
}