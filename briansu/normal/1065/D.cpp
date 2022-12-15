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


const ll MAXn=1e1+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

typedef pair<ll,pair<ll,ll> > plc;

ii dis[3][MAXn][MAXn];
ii lst[3][MAXn][MAXn];

ii p[MAXn * MAXn];

queue<plc> q;
ll n;

void go(ll t,ll x,ll y,ii d)
{
  if(x < 0 || x >= n || y < 0 || y >= n)return;
  if(d >= dis[t][x][y])return;
  dis[t][x][y] = d;
  q.push({t,{x,y}});
}

ii ans[3];

int main()
{
    IOS();
    cin>>n;
    REP(i,n)REP(j,n)
    {
      ll x;
      cin>>x;
      p[x] = ii(i,j);
    }
    REP(i,3)ans[i] = ii(0,0);
    for(int now = 1;now<n * n;now++)
    {
      while(SZ(q))q.pop();
      REP(t,3)REP(x,n)REP(y,n)dis[t][x][y] = ii(INF,INF),lst[t][x][y] = ii(-1,-1);
      REP(t,3)dis[t][p[now].X][p[now].Y] = ans[t],q.push({t,{p[now].X,p[now].Y}});
      while(SZ(q))
      {
        ll t = q.front().X;
        ll x = q.front().Y.X;
        ll y = q.front().Y.Y;
        q.pop();
        if(lst[t][x][y] == dis[t][x][y])continue;
        lst[t][x][y] = dis[t][x][y];
        ii d = dis[t][x][y];
        if(t == 0)
        {
          REP(i,n)if(i!=x)go(t,i,y,ii(d.X+1,d.Y));
          REP(i,n)if(i!=y)go(t,x,i,ii(d.X+1,d.Y));
        }
        else if(t == 1)
        {
          REP(i,n)if(i!=x)go(t,i,y - (x - i),ii(d.X+1,d.Y));
          REP(i,n)if(i!=x)go(t,i,y + (x - i),ii(d.X+1,d.Y));
        }
        else{
          go(t,x + 1,y + 2,ii(d.X+1,d.Y));
          go(t,x - 1,y + 2,ii(d.X+1,d.Y));
          go(t,x - 1,y - 2,ii(d.X+1,d.Y));
          go(t,x + 1,y - 2,ii(d.X+1,d.Y));
          go(t,x - 2,y + 1,ii(d.X+1,d.Y));
          go(t,x + 2,y + 1,ii(d.X+1,d.Y));
          go(t,x - 2,y - 1,ii(d.X+1,d.Y));
          go(t,x + 2,y - 1,ii(d.X+1,d.Y));
        }
        if(t!=0)go(0,x,y,ii(d.X+1,d.Y+1));
        if(t!=1)go(1,x,y,ii(d.X+1,d.Y+1));
        if(t!=2)go(2,x,y,ii(d.X+1,d.Y+1));
      }
      REP(t,3)ans[t] = dis[t][p[now+1].X][p[now+1].Y];
    }
    ii mn = ii(INF,INF);
    REP(t,3)mn = min(mn,ans[t]);
    cout<<mn.X<<" "<<mn.Y<<endl;

}