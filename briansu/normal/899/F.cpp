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
const ll INF=ll(1e15);

ll bit[(1<<MAXlg)];
void ins(ll x,ll k)
{
  while(x<(1<<MAXlg))
  {
    bit[x]+=k;
    x+=x&-x;
  }
}
ll qr(ll x)
{
  ll p=0,l=(1<<(MAXlg-1));
  while(l)
  {
    if(bit[p+l]<x)x-=bit[p+l],p+=l;
    l>>=1;
  }
  return p+1;
}

vector<ii> ans;

const ll M=26*2+10;
set<ll> st[M+5];
ll f(char c)
{
  if(isdigit(c))return c-'0';
  else if(islower(c))return c-'a'+10;
  else return c-'A'+36;
}

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    REP1(i,n)st[f(s[i-1])].insert(i),ins(i,1);

    REP(i,q)
    {
      ll l,r;
      char c;
      cin>>l>>r>>c;
      c=f(c);
      l=qr(l),r=qr(r);
      debug(l,r);
      while(1)
      {
        auto it=st[c].lower_bound(l);
        if(it==st[c].end()||*it>r)break;
        ins(*it,-1);
        st[c].erase(it);
      }
    }
    REP(i,M)for(ll tmp:st[i])ans.pb(ii(tmp,i));
    sort(ALL(ans));
    for(ii tmp:ans)
    {
      char c;
      if(tmp.Y<10)c=tmp.Y+'0';
      else if(tmp.Y<36)c=tmp.Y-10+'a';
      else c=tmp.Y-36+'A';
      cout<<(char)c;
    }
    cout<<endl;
}