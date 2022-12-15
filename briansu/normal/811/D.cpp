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
//#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll d[MAXn][MAXn];
ll f[MAXn][MAXn];
queue<ii> q;
ll n,m;

vector<ll> st;
ii e;
int main()
{
    IOS();
    FILL(f,-1);
    FILL(d,0);
    cin>>n>>m;
    REP(i,n)
    {
      string s;
      cin>>s;
      REP(j,m)
      {
        if(s[j]=='.')d[i+1][j+1]=1;
        else if(s[j]=='F')d[i+1][j+1]=2,e=ii(i+1,j+1);
      }
    }
    q.push(ii(1,1));
    f[1][1]=0;
    debug(2);
    while(SZ(q))
    {
      debug(1);
      if(!SZ(q))break;
      ll x=q.front().X;
      ll y=q.front().Y;
      q.pop();
      if(d[x][y]==2)break;
      ll dx[4]={1,-1,0,0};
      ll dy[4]={0,0,1,-1};
      REP(i,4)
      {
        if(d[x+dx[i]][y+dy[i]]&&f[x+dx[i]][y+dy[i]]==-1)
        {
          f[x+dx[i]][y+dy[i]]=i;
          q.push(ii(x+dx[i],y+dy[i]));
        }
      }
    }
    debug(3);
    ll dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    ll x=e.X,y=e.Y;
    while(ii(x,y)!=ii(1,1))
    {
      debug(x,y);
      st.pb(f[x][y]);
      ll t=f[x][y];
      x=x+dx[t];
      y=y+dy[t];
    }
    reverse(ALL(st));
    debug(st);
    ll a=-1,b=-1;
    x=1,y=1;
    for(ll k:st)
    {
      ll c,d;
      if(k==0||k==1)
      {
        if(a==-1)
        {
          cout<<'D'<<endl;
          cin>>c>>d;
          if(x!=c||y!=d)
          {
            x=c;y=d;
            a=0;
            continue;
          }
          else a=1;
        }
        if(a==0)cout<<(k==0?'D':'U')<<endl;
        else cout<<(k==1?'D':'U')<<endl;
      }
      else
      {
        if(b==-1)
        {
          cout<<'R'<<endl;
          cin>>c>>d;
          if(x!=c||y!=d)
          {
            x=c;y=d;
            b=0;
            continue;
          }
          else b=1;
        }
        if(b==0)cout<<(k==2?'R':'L')<<endl;
        else cout<<(k==3?'R':'L')<<endl;
      }
      cin>>x>>y;
    }
}