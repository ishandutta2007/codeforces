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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll cnt[MAXn],tmpcnt[MAXn];
ll k,mx = 0;

bool chk(ll n,ll m,ll x,ll y)
{
  debug(n,m,x,y);
  ll tmp = n * m;
  REP(i,tmp+1)tmpcnt[i] = 0;
  REP1(i,n)REP1(j,m)tmpcnt[abs(x-i) + abs(y-j)] += 1;
  REP(i,tmp+1)if(tmpcnt[i] != cnt[i])return 0;
  return 1;
}

int main()
{
    IOS();
    cin>>k;
    REP(i,k)
    {
      ll x;
      cin>>x;
      cnt[x]++;
      mx = max(mx,x);
    }
    if(cnt[0] != 1){
      cout<<-1<<endl;
      return 0;
    }
    ll fg = 0,a,b,det;
    for(int i=1;;i+=1)
    {
      ll tmp = 4 * i;
      if(!fg&&tmp != cnt[i])
      {
        a = i - 1;
        fg = 1;det = 1;
      }
      if(fg&&tmp-det != cnt[i])
      {
        b = i - 1;
        break;
      }
      if(fg)det += 2;
    }
    debug(a,b);
    for(int i = 0;i+1+a <= k && i <= mx;i++)
    {
      if(k % (i + 1 + a) != 0)continue;
      ll c = mx - i,d = k / (i + 1 + a) - c - 1;
      if(i != b && c != b && d != b)continue;
      if(chk(a+i+1,c+d+1,a+1,c+1)){
        cout<<a+i+1<<" "<<c+d+1<<endl;
        cout<<a+1<<" "<<c+1<<endl;
        return 0;
      }
    }
    cout<<-1<<endl;
}