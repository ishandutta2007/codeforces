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
template<typename _t> void pary2(_t _a,ll __n,ll __m){cerr<<"{";REP(i,__n){cerr<<(i?" ":"");_OUTC(cerr,_a[i],_a[i]+__m);cerr<<(i==__n-1?"}":",")<<endl;}}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define pary2(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=3e5+5,MAXc=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXc][MAXc];
ll p[MAXn][5],c[MAXn];

ll clr[MAXc][MAXc][30],ct[MAXc][MAXc],diff[MAXc][MAXc];//cnt of color for each block

ll qr(ll i,ll t)
{
  ll a=p[i][0],b=p[i][1],c=p[i][2]-1,d=p[i][3]-1;
  return clr[c][d][t]-clr[c][b-1][t]-clr[a-1][d][t]+clr[a-1][b-1][t];
}
ll qr2(ll i)
{
  ll a=p[i][0],b=p[i][1],c=p[i][2]-1,d=p[i][3]-1;
  return diff[c][d]-diff[c][b-1]-diff[a-1][d]+diff[a-1][b-1];
}

int main()
{
    IOS();
    ll n,m,q;
    cin>>n>>m>>q;
    REP1(i,n)
    {
      string s;
      cin>>s;
      REP1(j,m)d[i][j]=s[j-1]-'a';
    }
    REP(i,q)
    {
      REP(j,4)cin>>p[i][j];
      p[i][2]++;p[i][3]++;
      char tmp;
      cin>>tmp;
      c[i]=tmp-'a';

    }
    REP(i,q)debug(i,c[i]);
    REP(i,q)
    {
      clr[p[i][0]][p[i][1]][c[i]]++;
      clr[p[i][2]][p[i][3]][c[i]]++;
      clr[p[i][0]][p[i][3]][c[i]]--;
      clr[p[i][2]][p[i][1]][c[i]]--;
      ct[p[i][0]][p[i][1]]++;
      ct[p[i][2]][p[i][3]]++;
      ct[p[i][0]][p[i][3]]--;
      ct[p[i][2]][p[i][1]]--;
    }

    REP1(i,n)REP1(j,m)ct[i][j]+=ct[i][j-1]+ct[i-1][j]-ct[i-1][j-1];
    REP(t,26)REP1(i,n)REP1(j,m)clr[i][j][t]+=clr[i][j-1][t]+clr[i-1][j][t]-clr[i-1][j-1][t];

    pary2(ct,n+1,m+1);
    REP1(i,n)REP1(j,m)clr[i][j][d[i][j]]+=q-ct[i][j];

    REP1(i,n)REP1(j,m)
    {
      REP(t,26)diff[i][j]+=abs(d[i][j]-t)*clr[i][j][t];
    }
    pary2(diff,n+1,m+1);

    REP1(i,n)pary2(clr[i],m+1,26);
    REP(t,26)REP1(i,n)REP1(j,m)clr[i][j][t]+=clr[i][j-1][t]+clr[i-1][j][t]-clr[i-1][j-1][t];
    REP1(i,n)REP1(j,m)diff[i][j]+=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
    cerr<<endl;
    REP1(i,n)pary2(clr[i],m+1,26);

    //REP(t,26)REP(i,n)REP(j,m)debug(i,j,t,clr[i][j][t]);
    //REP(i,n)REP(j,m)debug(i,j,diff[i][j],ct[i][j]);

    ll mn=INF;
    REP(i,q)
    {
      ll tt=0;
      REP(t,26)
      {
        tt+=abs(c[i]-t)*qr(i,t);
        debug(tt,c[i]-t,qr(i,t));
      }
      tt+=diff[n][m]-qr2(i);
      debug(tt);
      mn=min(mn,tt);
    }
    cout<<mn<<endl;
}