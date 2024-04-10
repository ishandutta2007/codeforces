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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll d[MAXn][MAXn];

ll mn[2][MAXn];

vector<ii> ans;

int main()
{
    IOS();
    ll r,c;
    cin>>r>>c;
    REP(i,r)REP(j,c)cin>>d[i][j];
    REP(i,r)
    {
      mn[0][i]=d[i][0];
      REP(j,c)mn[0][i]=min(mn[0][i],d[i][j]);
    }
    REP(j,c)
    {
      mn[1][j]=d[0][j];
      REP(i,r)mn[1][j]=min(mn[1][j],d[i][j]);
    }

    while(1)
    {
      bool b=0;
      if(c>=r)
      {
        REP(i,r)if(mn[0][i]>0)
        {
          b=1;
          REP(j,c)d[i][j]-=mn[0][i],mn[1][j]=min(mn[1][j],d[i][j]);
          REP(k,mn[0][i])ans.pb(ii(0,i+1));
          mn[0][i]=0;

        }
        if(b)continue;
        REP(j,c)if(mn[1][j]>0)
        {
          b=1;
          REP(k,mn[1][j])ans.pb(ii(1,j+1));
          REP(i,r)d[i][j]-=mn[1][j],mn[0][i]=min(mn[0][i],d[i][j]);
          mn[1][j]=0;
        }
      }
      else
      {
        REP(j,c)if(mn[1][j]>0)
        {
          b=1;
          REP(k,mn[1][j])ans.pb(ii(1,j+1));
          REP(i,r)d[i][j]-=mn[1][j],mn[0][i]=min(mn[0][i],d[i][j]);
          mn[1][j]=0;
        }
        if(b)continue;
        REP(i,r)if(mn[0][i]>0)
        {
          b=1;
          REP(j,c)d[i][j]-=mn[0][i],mn[1][j]=min(mn[1][j],d[i][j]);
          REP(k,mn[0][i])ans.pb(ii(0,i+1));
          mn[0][i]=0;
        }
      }


      if(!b)break;
    }
    debug(ans);
    REP(i,r)REP(j,c)if(d[i][j]){cout<<-1<<endl;return 0;}

    cout<<SZ(ans)<<endl;
    for(ii k:ans)
    {
      if(k.X==0)cout<<"row ";
      else cout<<"col ";
      cout<<k.Y<<endl;
    }

}