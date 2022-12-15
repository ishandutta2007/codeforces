//{
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
#undef brian
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

ll d[(1<<12)],dt[(1<<24)];

ll bs[15];

#define AND 1
#define OR 2
#define XOR 3
#define NAND 4
#define NOR 5
#define NXOR 6

ll mp[3][10];


int main()
{
    //IOS();
    REP(x,2)REP(y,2)
    {
      if(x & y)mp[x][NAND] += (1<<y);else mp[x][AND] += (1<<y);
      if(x | y)mp[x][NOR] += (1<<y);else mp[x][OR] += (1<<y);
      if(x ^ y)mp[x][NXOR] += (1<<y);else mp[x][XOR] += (1<<y);
    }

    bs[0] = 0;
    REP1(i,12)bs[i] = 2 * i;
    ll w,n,m;
    //cin>>w>>n>>m;
    scanf("%d %d %d",&w,&n,&m);
    //w = 12,n = 0,m = 50000;
    REP(i,n)
    {
      ll x;
      scanf("%d",&x);
      //cin>>x;
      d[x] ++;
    }
    REP(I,(1<<w))REP(J,(1<<w)){
      ll tt = 0;
      REP(i,w)
      {
        if((1<<i) & J)tt += (1<<bs[i]) + (1<<bs[i]) + (1<<bs[i]);
        else if((1<<i) & I)tt += (1<<bs[i]) + (1<<bs[i]);
        else tt += (1<<bs[i]);
      }
      dt[tt] += d[I];
    }
    while(m--)
    {
      //string s;
      char s[15];
      scanf("%s",s);
      //cin>>s;
      //s = "xxxxxxxxxxxx";
      ll gt[15];
      REP(i,w)
      {
        if(s[i] == 'A')gt[i]=AND;
        else if(s[i] == 'O')gt[i]=OR;
        else if(s[i] == 'X')gt[i]=XOR;
        else if(s[i] == 'a')gt[i]=NAND;
        else if(s[i] == 'o')gt[i]=NOR;
        else gt[i]=NXOR;
      }
      ll tt = 0;
      REP(I,(1<<w))
      {
        ll msk = 0;
        REP(i,w)
        {
          ll x;
          if(I & (1<<i))x = 1;
          else x = 0;
          msk += (mp[x][gt[w-i-1]] << bs[i]);
        }
        tt += dt[msk] * d[I];
        //debug(bitset<12>(msk),d[I],dt[msk]);
      }
      printf("%d\n",tt);
      //cout<<tt<<endl;
    }
}