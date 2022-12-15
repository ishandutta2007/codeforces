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

string s;
bool b[MAXn],fg=0;
string d1,d2;

int main()
{
    IOS();
    cin>>s;
    for(char c:s)b[c]=1;
    cin>>s;
    REP(i,SZ(s))
    {
      if(s[i]=='*')
      {
        fg=1;
        d1=s.substr(0,i);
        d2=s.substr(i+1);
        reverse(ALL(d2));
      }
    }
    ll n;
    cin>>n;
    debug(d1,d2);
    REP(T,n)
    {
      string tmp;
      cin>>tmp;

      bool ok=1;
      if(fg)
      {
        if(SZ(tmp)<SZ(s)-1)ok=0;
        else
        {
          REP(i,SZ(d1))if((d1[i]=='?'&&!b[tmp[i]])||(d1[i]!='?'&&d1[i]!=tmp[i]))ok=0;
          REP(i,SZ(d2))if((d2[i]=='?'&&!b[tmp[SZ(tmp)-i-1]])||(d2[i]!='?'&&d2[i]!=tmp[SZ(tmp)-i-1]))ok=0;
          for(int i=SZ(d1);i<SZ(tmp)-SZ(d2);i++)if(b[tmp[i]])ok=0;
        }
      }
      else
      {
        if(SZ(s)!=SZ(tmp))ok=0;
        else
        {
          REP(i,SZ(s))if((s[i]=='?'&&!b[tmp[i]])||(s[i]!='?'&&s[i]!=tmp[i]))ok=0;
        }
      }
      if(ok)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

}