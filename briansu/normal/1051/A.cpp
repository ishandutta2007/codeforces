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

ll d[MAXn],ct[5];

char get(ll x)
{
  if(x == 0)return 'a';
  else if(x==1)return 'A';
  else return '1';
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      string s;
      cin>>s;
      REP(i,SZ(s))
      {
        if(islower(s[i]))d[i] = 0;
        else if(isupper(s[i]))d[i] = 1;
        else d[i] = 2;
      }
      FILL(ct,0);
      REP(i,SZ(s))ct[d[i]]++;
      if(min({ct[0],ct[1],ct[2]}) > 0){
        cout<<s<<endl;
        continue;
      }
      bool ok = 0;
      REP(i,SZ(s))REP(j,3)
      {
        if(ok)continue;
        ct[d[i]]--;
        ct[j]++;
        if(min({ct[0],ct[1],ct[2]}) > 0)
        {
          s[i] = get(j);
          ok = 1;
          break;
        }
        ct[j]--;
        ct[d[i]]++;
      }
      if(ok)
      {
        cout<<s<<endl;
        continue;
      }
      else REP(i,SZ(s)-1)REP(k,3)REP(l,3)
      {
        if(ok)continue;
        ct[d[i]]--;
        ct[d[i+1]]--;
        ct[k]++;
        ct[l]++;
        if(min({ct[0],ct[1],ct[2]}) > 0)
        {
          s[i] = get(k);
          s[i+1] = get(l);
          ok = 1;
          break;
        }
        ct[d[i]]++;
        ct[d[i+1]]++;
        ct[k]--;
        ct[l]--;
      }
      cout<<s<<endl;

    }
}