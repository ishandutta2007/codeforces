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


const int MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const int INF=ll(1e9);
const int M = (1<<12);

int dp[2][M],cst[15],msk[15];
int d[MAXn],p[10];

inline void smin(int &a,int b){a=min(a,b);}

#define dbg() REP(I,M)debug(bitset<12>(I),dp[fg][I]);

int main()
{
    IOS();

    int n;
    cin>>n;
    REP1(i,4)cin>>p[i];
    REP(i,4)
    {
      string s;
      cin>>s;
      REP(j,n)if(s[j]=='*')d[j]+=(1<<i);
    }
    int it=0;
    REP1(i,3)for(int j=0;j+i<=4;j++)
    {
      REP(k,i)msk[it]=(msk[it]<<4)+(1<<i)-1;
      msk[it]<<=j;
      cst[it]=p[i];
      it++;
    }
    REP(i,it)debug(i,bitset<12>(msk[i]),cst[i]);
    REP(i,n)debug(i,bitset<4>(d[i]));
    bool fg=0;
    REP(I,M)dp[0][I]=INF;
    dp[0][d[0]]=0;
    debug(dp[fg][15]);
    REP(i,n)
    {
      REP(j,it)
      {
        REP(I,M)dp[!fg][I]=dp[fg][I];
        REP(I,M)smin(dp[!fg][I&(~(msk[j]))],dp[fg][I]+cst[j]);
        fg=!fg;
      }
      REP(I,M)dp[!fg][I]=INF;
      REP(I,M)
      {
        smin(dp[!fg][0],dp[fg][I]+p[4]);
        if(I<(1<<8))smin(dp[!fg][(I<<4)|d[i+1]],dp[fg][I]);
      }
      fg=!fg;
      //dbg();
    }
    cout<<dp[fg][0]<<endl;
}