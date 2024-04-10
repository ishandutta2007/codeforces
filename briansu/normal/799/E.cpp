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
template<typename _a> ostream &operator << (ostream &_s,multiset<_a> &_c){return _OUTC(_s,ALL(_c));}
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

ll ct[MAXn],lka[MAXn],lkb[MAXn];

vector<ll> dtab,dta,dtb;
multiset<ll> st;
multiset<ll,greater<ll> > pst;

int main()
{
    IOS();
    ll n,m,k,cta,ctb;
    cin>>n>>m>>k;
    REP(i,n)cin>>ct[i];
    cin>>cta;
    REP(i,cta)
    {
      ll t;
      cin>>t;
      lka[t-1]=1;
    }
    cin>>ctb;
    REP(i,ctb)
    {
      ll t;
      cin>>t;
      lkb[t-1]=1;
    }

    REP(i,n)
    {
      if(lka[i]&&lkb[i])dtab.pb(ct[i]);
      else if(lka[i])dta.pb(ct[i]);
      else if(lkb[i])dtb.pb(ct[i]);
      else st.insert(ct[i]);
    }

    sort(ALL(dtab));
    sort(ALL(dta));
    sort(ALL(dtb));

    ll ans=INF,ttab=0,tta=0,ttb=0,tt=0,ttct=0;

    for(ll t:dta)tta+=t;
    for(ll t:dtb)ttb+=t;

    REP(i,m+1)
    {
      if(i>SZ(dtab))break;
      if(i)ttab+=dtab[i-1];
      ll t=max(k-i,0LL);
      while(SZ(dta)>t)
      {
        tta-=dta.back();
        st.insert(dta.back());
        dta.pop_back();
      }
      while(SZ(dtb)>t)
      {
        ttb-=dtb.back();
        st.insert(dtb.back());
        dtb.pop_back();
      }
      if(SZ(dta)<t||SZ(dtb)<t||i+2*t>m)continue;
      if(SZ(pst))
      {
        ttct--;
        tt-=*pst.begin();
        st.insert(*pst.begin());
        pst.erase(pst.begin());
      }
      while(SZ(st)&&ttct+2*t+i<m)
      {
        tt+=*st.begin();
        pst.insert(*st.begin());
        st.erase(st.begin());
        ttct++;
      }
      if(ttct+2*t+i!=m)continue;
      debug(ttab,tta,ttb,tt,ttct,dtab,dta,dtb,st,i,t);
      ans=min(ans,ttab+tta+ttb+tt);
    }
    if(ans!=INF)cout<<ans<<endl;
    else cout<<-1<<endl;

}