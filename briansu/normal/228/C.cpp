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


const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

bool d[MAXn][MAXn];
ll pre[MAXn][MAXn];
bool dp[MAXlg][MAXn][MAXn];
ll r,c;

bool cal(ll a,ll b,ll c,ll d)
{
  a++;b++;c++;d++;
  return pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1]==(c-a+1)*(d-b+1);
}
int main()
{
    IOS();
    cin>>r>>c;
    REP(i,r)
    {
      string s;
      cin>>s;
      REP(j,c)d[i][j]=(s[j]=='*'),pre[i+1][j+1]=d[i][j];
    }
    REP1(i,r)REP1(j,c)pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];

    ll ans=0;

    REP(I,16)
    {
      REP(i,r)REP(j,c)dp[0][i][j]=!d[i][j];

      for(int it=1,l=2,h=1;l<=min(r,c);l<<=1,it++,h<<=1)
      {
        REP(i,r-l+1)REP(j,c-l+1)
        {
          ll a[4]={i,i+h,i+h,i},b[4]={j,j,j+h,j+h};
          dp[it][i][j]=((I&1)?cal(a[0],b[0],a[0]+h-1,b[0]+h-1):dp[it-1][a[0]][b[0]])&&
                    ((I&2)?cal(a[1],b[1],a[1]+h-1,b[1]+h-1):dp[it-1][a[1]][b[1]])&&
                    ((I&4)?cal(a[2],b[2],a[2]+h-1,b[2]+h-1):dp[it-1][a[2]][b[2]])&&
                    ((I&8)?cal(a[3],b[3],a[3]+h-1,b[3]+h-1):dp[it-1][a[3]][b[3]]);
          if(it>1&&dp[it][i][j])debug(it,i,j,I);
          if(it>1)ans+=dp[it][i][j];
        }
      }
    }
    cout<<ans<<endl;

}