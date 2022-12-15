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


const ll MAXn=7e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[2][MAXn],ct[2][MAXn],ans[2][MAXn];
// 0 lose 1 win 2 loop  -1 unknown

queue<ii> q;
ll k[2];



int main()
{
    IOS();
    ll n;
    cin>>n;
    cin>>k[0];
    REP(i,k[0])cin>>d[0][i];
    cin>>k[1];
    REP(i,k[1])cin>>d[1][i];
    FILL(ans,-1);

    REP(t,2)REP(i,k[t])
    {
      ll p = (n - d[t][i]) % n;
      ans[t][p] = 1;
      q.push(ii(t,p));
    }

    while(SZ(q))
    {
      ll t = q.front().X,p = q.front().Y;q.pop();
      if(ans[t][p] == 0)
      {
        REP(i,k[!t])
        {
          ll tmp = (p - d[!t][i] + n)%n;
          if(ans[!t][tmp] == -1)
          {
            ans[!t][tmp] = 1;
            q.push({!t,tmp});
          }
        }
      }
      else{
        REP(i,k[!t])
        {
          ll tmp = (p - d[!t][i] + n)%n;
          if(ans[!t][tmp] == -1)
          {
            ct[!t][tmp] ++;
            if(ct[!t][tmp] == k[!t])
            {
              ans[!t][tmp] = 0;
              q.push({!t,tmp});
            }
          }
        }
      }
    }
    REP1(i,n-1)
    {
      if(ans[0][i] == 0)cout<<"Lose"<<" ";
      else if(ans[0][i] == 1)cout<<"Win"<<" ";
      else cout<<"Loop"<<" ";
    }
    cout<<endl;
    REP1(i,n-1)
    {
      if(ans[1][i] == 0)cout<<"Lose"<<" ";
      else if(ans[1][i] == 1)cout<<"Win"<<" ";
      else cout<<"Loop"<<" ";
    }
    cout<<endl;

}