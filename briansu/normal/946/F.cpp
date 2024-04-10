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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll ocu[5][MAXn][MAXn],fst[5][MAXn],lst[5][MAXn],ful[5],emp[5];

void add(ll &a,ll b)
{
  a+=b%MOD;
  if(a>=MOD)a-=MOD;
}

int main()
{
    IOS();
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    REP(i,n)ocu[s[i]-'0'][i][i]=1;
    if(s=="0")ful[0]=1;
    if(s=="1")ful[1]=1;
    fst[s[0]-'0'][0]=1;
    lst[s[n-1]-'0'][n-1]=1;
    emp[0]=emp[1]=2;
    //for(int k=2;k<=x;k++)emp[k]=emp[k-1]*emp[k-2]%MOD;
    if(x<2)
    {
      cout<<ful[x]<<endl;
      return 0;
    }
    //REP(k,2)for(int i=0;i<n;i++)for(int j=i;j<n;j++)debug(k,i,j,ocu[k][i][j]);
    //REP(k,2)for(int i=0;i<n-1;i++)debug(k,i,fst[k][i]);
    //REP(k,2)for(int i=1;i<n;i++)debug(k,i,lst[k][i]);
    for(int k=2;k<=x;k++)
    {
      add(ful[2],ful[1]*emp[0]);
      add(ful[2],ful[0]*emp[1]);
      for(int i=0;i<n-1;i++)add(ful[2],fst[1][i]*lst[0][i+1]);
      for(int i=1;i<n;i++)add(lst[2][i],lst[1][i]*emp[0]+lst[0][i]);
      for(int i=0;i<n-1;i++)add(fst[2][i],fst[0][i]*emp[1]+fst[1][i]);
      for(int i=1;i<n;i++)for(int j=i;j<n-1;j++)add(lst[2][i],ocu[1][i][j]*lst[0][j+1]);
      for(int i=0;i<n-1;i++)for(int j=0;j<i;j++)add(fst[2][i],fst[1][j]*ocu[0][j+1][i]);
      for(int i=0;i<n;i++)for(int j=i;j<n;j++)
      {
        add(ocu[2][i][j],ocu[1][i][j]+ocu[0][i][j]);
        for(int l=i;l<j;l++)add(ocu[2][i][j],ocu[1][i][l]*ocu[0][l+1][j]);
      }
      emp[2]=emp[1]*emp[0]%MOD;
      //for(int i=0;i<n;i++)for(int j=i;j<n;j++)debug(k,i,j,ocu[2][i][j]);
      //debug(k,ful[2]);
      //for(int i=0;i<n-1;i++)debug(k,i,fst[2][i]);
      //for(int i=1;i<n;i++)debug(k,i,lst[2][i]);
      for(int i=0;i<n;i++)for(int j=i;j<n;j++)ocu[0][i][j]=ocu[1][i][j],ocu[1][i][j]=ocu[2][i][j],ocu[2][i][j]=0;
      for(int i=0;i<n-1;i++)fst[0][i]=fst[1][i],fst[1][i]=fst[2][i],fst[2][i]=0;
      for(int i=1;i<n;i++)lst[0][i]=lst[1][i],lst[1][i]=lst[2][i],lst[2][i]=0;
      ful[0]=ful[1],ful[1]=ful[2],ful[2]=0;
      emp[0]=emp[1],emp[1]=emp[2],emp[2]=0;
    }
    cout<<ful[1]<<endl;
}