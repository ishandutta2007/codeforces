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

ll bit[MAXn];

ll n,q;

void ins(ll x)
{
  while(x<n+5)
  {
    bit[x]++;
    x+=x&-x;
  }
}

ll qr(ll x)
{
  ll rt=0;
  while(x>0)
  {
    rt+=bit[x];
    x-=x&-x;
  }
  return rt;
}

ll c[MAXn];

ll ct[MAXn][10];

ll d[MAXn][10];
ll p[MAXn];

vector<ii> dt;

int main()
{
    IOS();

    cin>>n>>q;
    REP1(i,n)
    {
      ll t;
      cin>>t;
      p[t]=i;
    }
    REP(i,q)REP(j,4)cin>>d[i][j];

    FILL(bit,0);
    dt.clear();
    REP(i,q)dt.pb(ii(d[i][1],i));
    sort(ALL(dt));
    debug(dt);
    ll it=0;
    REP1(i,n)
    {
        while(it<q&&dt[it].X==i)
        {
          ll t=dt[it].Y;
          ct[t][0]=qr(d[t][0]-1);
          ct[t][1]=i-1-qr(d[t][2]);
          it++;
        }
        ins(p[i]);
    }

    FILL(bit,0);
    dt.clear();
    REP(i,q)dt.pb(ii(d[i][3],i));
    sort(ALL(dt),greater<ii>());
    debug(dt);
    it=0;
    for(ll i=n;i>0;i--)
    {
        while(it<q&&dt[it].X==i)
        {
          ll t=dt[it].Y;
          ct[t][2]=qr(d[t][0]-1);
          ct[t][3]=n-i-qr(d[t][2]);
          it++;
        }
        ins(p[i]);
    }

    FILL(c,0);
    REP1(i,n)c[i]=i*(i-1)/2;

    REP(i,q)
    {
      ll tt=c[n];
      tt-=c[d[i][1]-1];
      tt-=c[d[i][0]-1];
      tt-=c[n-d[i][3]];
      tt-=c[n-d[i][2]];

      REP(j,4)tt+=c[ct[i][j]];
      cout<<tt<<endl;
    }

    REP(i,q)REP(j,4)debug(i,j,ct[i][j]);

}