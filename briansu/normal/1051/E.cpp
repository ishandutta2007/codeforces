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


const ll MAXn=2e6+10,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);

string s;

void buildz(ll *z)
{
  z[0] = 0;
  ll l = 0,r = 0;
  for(int i = 1;i<SZ(s);i++)
  {
    if(r >= i)z[i] = min(z[i - l],r-i+1);
    for(;i + z[i] < SZ(s) && s[z[i]] == s[i + z[i]];z[i]++);
    if(i + z[i] - 1 > r)r = i + z[i] - 1,l = i;
  }
}


void add(ll &a,ll b){
  a += b;
  if(a >= MOD) a-= MOD;
}
void sub(ll &a,ll b)
{
  a -= b;
  if(a < 0)a += MOD;
}

string a,l,r;
ll dp[MAXn];
ll zl[MAXn],zr[MAXn];

bool chkl(int i,int it){ // i = last digit, it = first digit
  ll dt = zl[it + SZ(l) - 1];
  debug(i,it,dt);
  if(i - it + 1 < SZ(l))return 0;
  else if(i - it + 1 > SZ(l))return 1;
  if(dt >= SZ(l))return 1;

  ll t;
  if(l[dt] < a[it + dt - 1])t = SZ(l);
  else t = SZ(l) + 1;
  if(i - it + 1 >= t)return 1;
  else return 0;
}

bool chkr(int i,int it){ // i = last digit, it = first digit
  ll dt = zr[it + SZ(r) - 1];
  debug(i,it,dt);
  if(i - it + 1 < SZ(r))return 1;
  else if(i - it + 1 > SZ(r))return 0;
  if(dt >= SZ(r))return 1;

  ll t;
  if(r[dt] < a[it + dt - 1])t = SZ(r);
  else t = SZ(r) + 1;
  debug(t);
  if(i - it + 1 >= t)return 0;
  else return 1;
}
/*
bool chkr(int i,int it){ // i = last digit, it = first digit
  ll dt = zr[it + SZ(r) - 1];
  debug(i,it,dt);
  if(dt + it > i)return 1;
  if(dt >= SZ(r) && i >= SZ(r))return 1;
  ll t;
  if(r[dt] < a[i + dt - 1])t = SZ(r);
  else t = SZ(r) + 1;
  debug(t);
  if(i - it + 1 >= t)return 0;
  else return 1;
}*/

int main()
{
    IOS();
    cin>>a>>l>>r;
    bool zf = 0;
    if(l == "0")zf = 1;
    s = l + a;
    buildz(zl);
    debug(s);
    pary(zl,zl+SZ(s));
    s = r + a;
    buildz(zr);
    debug(s);
    pary(zr,zr+SZ(s));

    {
      ll tt = 0,itl = 0,itr = 0;
      FILL(dp,0);
      dp[0] = 1;
      REP1(i,SZ(a))
      {
        if(a[i-1] == '0')
        {
          if(zf)add(dp[i],dp[i-1]);
          dp[i-1] = 0;
        }
        while(itl < i && chkl(i,itl+1))
        {
          add(tt,dp[itl]);
          itl++;
        }
        while(itr < i && !chkr(i,itr+1))
        {
          sub(tt,dp[itr]);
          itr++;
        }
        add(dp[i], tt);
        debug(i,dp[i],itl,itr,tt);
      }
    }
    REP(i,SZ(a)+1)debug(i,dp[i]);
    cout<<dp[SZ(a)]<<endl;
}