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


const ll MAXn=1e5+5,MAXlg=28;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct node{
  ll sz;
  node*lc,*rc;
  node():sz(0),lc(0),rc(0){}
};
node *ins(node *nd,string &s,ll lv,ll k)
{
  if(!nd)nd=new node();
  nd->sz+=k;
  if(lv==SZ(s))return nd;
  else if(s[lv]=='0')nd->lc=ins(nd->lc,s,lv+1,k);
  else nd->rc=ins(nd->rc,s,lv+1,k);
  return nd;
}

ll gsz(node *a){return a?a->sz:0;}
ll qr(node *nd,string &s,string &k,ll lv)
{
  if(!nd)return 0;
  bool a=s[lv]-'0';
  bool b=k[lv]-'0';
  if(b)
  {
    if(a)return qr(nd->lc,s,k,lv+1)+gsz(nd->rc);
    else return qr(nd->rc,s,k,lv+1)+gsz(nd->lc);
  }
  else
  {
    if(a)return qr(nd->rc,s,k,lv+1);
    else return qr(nd->lc,s,k,lv+1);
  }
}

string to_bin(ll a)
{
  string s="";
  REP(i,MAXlg)
  {
    s+=(a%2?"1":"0");
    a/=2;
  }
  reverse(ALL(s));
  return s;
}

node *rt=0;

int main()
{
    IOS();
    ll q;
    cin>>q;
    REP(i,q)
    {
      ll t,p;
      cin>>t>>p;
      string s=to_bin(p);
      if(t==1)rt=ins(rt,s,0,1);
      else if(t==2)rt=ins(rt,s,0,-1);
      else
      {
        ll l;
        cin>>l;
        string k=to_bin(l);
        cout<<qr(rt,s,k,0)<<endl;
      }
    }
}