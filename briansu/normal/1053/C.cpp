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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


void add(ll &a,ll b)
{
  a += b;
  if(a>=MOD)a-= MOD;
}
void sub(ll &a,ll b)
{
  a-=b;
  if(a < 0)a+=MOD;
}

ll n,Q;
ll a[MAXn],w[MAXn],bitw[MAXn],bitaw[MAXn],bitidxw[MAXn],bitrevidxw[MAXn]; //revidx = n - i,idx = i, i = [1,n]


void ins(ll idx)
{
  ll x = idx,aw = a[idx] * w[idx] % MOD,idxw = idx * w[idx] % MOD, revidxw = (n - idx) * w[idx] %MOD;
  while(x < MAXn)
  {
    bitw[x] += w[idx];
    add(bitaw[x],aw);
    add(bitidxw[x],idxw);
    add(bitrevidxw[x],revidxw);
    x += x & -x;
  }
}

void rem(ll idx)
{
  ll x = idx,aw = a[idx] * w[idx] % MOD,idxw = idx * w[idx] % MOD, revidxw = (n - idx) * w[idx] %MOD;
  while(x < MAXn)
  {
    bitw[x] -= w[idx];
    sub(bitaw[x],aw);
    sub(bitidxw[x],idxw);
    sub(bitrevidxw[x],revidxw);
    x += x & -x;
  }
}

ll qrw(ll l,ll r)
{
  ll ret = 0;
  l--;
  while(r > 0)ret += bitw[r],r -= r & -r;
  while(l > 0)ret -= bitw[l],l -= l & -l;
  return ret;
}
ll qraw(ll l,ll r)
{
  ll ret = 0;
  l--;
  while(r > 0)add(ret,bitaw[r]),r -= r & -r;
  while(l > 0)sub(ret,bitaw[l]),l -= l & -l;
  return ret;
}
ll qridxw(ll l,ll r)
{
  ll ret = 0;
  l--;
  while(r > 0)add(ret,bitidxw[r]),r -= r & -r;
  while(l > 0)sub(ret,bitidxw[l]),l -= l & -l;
  return ret;
}
ll qrrevidxw(ll l,ll r)
{
  ll ret = 0;
  l--;
  while(r > 0)add(ret,bitrevidxw[r]),r -= r & -r;
  while(l > 0)sub(ret,bitrevidxw[l]),l -= l & -l;
  return ret;
}

int main()
{
    IOS();
    cin>>n>>Q;
    REP1(i,n)cin>>a[i];
    REP1(i,n)cin>>w[i];
    REP1(i,n)ins(i);
    while(Q--)
    {
      ll x,y;
      cin>>x>>y;
      if(x < 0)
      {
        x = -x;
        rem(x);
        w[x] = y;
        ins(x);
      }
      else{
        ll sumw = qrw(x,y);
        ll pl = x - 1,pr = y;
        while(pl != pr - 1)
        {
          ll h = (pl + pr) / 2;
          ll tmp = qrw(x,h);
          //debug(pl,pr,h,tmp);
          if(tmp * 2 >= sumw)pr = h;
          else pl = h;
        }
        ll p = pr,ans = 0;
        pary(w+1,w+1+n);
        debug(p);
        {
          ll ttw = qrw(x,p) % MOD;
          ll ttaw = qraw(x,p);
          ll ttrevidxw = qrrevidxw(x,p);
          debug(ttw,ttaw,ttrevidxw);
          add(ans,a[p] * ttw % MOD);
          //debug(ans);
          sub(ans,ttaw);
          sub(ttrevidxw, ttw * (n - p) % MOD);
          //debug(ans,ttrevidxw);
          sub(ans,ttrevidxw);
        }
        debug(ans);
        if(p != y)
        {
          ll ttw = qrw(p+1,y) % MOD;
          ll ttaw = qraw(p+1,y);
          ll ttidxw = qridxw(p+1,y);
          //debug(ttw,ttaw,ttidxw);
          add(ans,ttaw);
          sub(ans,a[p] * ttw % MOD);
          sub(ttidxw, ttw * p % MOD);
          sub(ans,ttidxw);
        }
        cout<<ans<<endl;
      }
    }
}