//{
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


const ll MAXn=50+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct mov{
  ii s,t;
};

ll d[MAXn][MAXn],ord[MAXn],p[MAXn];
ii s[MAXn],t[MAXn];
vector<mov> v;
ll n,m;

void output(){
  cout<<SZ(v)<<endl;
  for(auto &pr:v)cout<<pr.s.X<<" "<<pr.s.Y<<" "<<pr.t.X<<" "<<pr.t.Y<<endl;
  exit(0);
}

void do_mov(ii a,ii b){
  swap(d[a.X][a.Y],d[b.X][b.Y]);
  v.pb({a,b});
}

void mov_blank(ll r,ll x,ll y)
{
  while(x!=y)
  {
    if(x < y)do_mov({r,x+1},{r,x}),x=x+1;
    else do_mov({r,x-1},{r,x}),x = x-1;
  }
}

void mov_tile(ll r,ll x,ll y)
{
  while(x!=y)
  {
    if(x < y)do_mov({r,x},{r,x+1}),x=x+1;
    else do_mov({r,x},{r,x-1}),x = x-1;
  }
}

void do_row(ll r)
{
  for(int i = 1;i <= n;i++)
  {
    if(d[r][i]){
      ll id = d[r][i],tg=t[id].Y;
      if(tg <= i)mov_tile(r,i,tg);
      else {
        ll sp = -1;
        for(int k = i+1;k<=n;k++)if(!d[r][k]){sp = k;break;}
        mov_blank(r,sp,i);
      }
    }
  }
}

int main()
{
    IOS();
    cin>>n>>m;
    REP1(i,m)cin>>s[i].X>>s[i].Y,d[s[i].X][s[i].Y] = i;
    REP1(i,m)cin>>t[i].X>>t[i].Y;
    if(n == 1)
    {
      cout<<0<<endl;
      return 0;
    }
    else if(n==2)
    {
        ii dt[4] = {{1,1},{1,2},{2,2},{2,1}};
        ll sa,sb,ta,tb;
        REP(i,4)if(dt[i] == s[1])sa = i;
        REP(i,4)if(dt[i] == t[1])ta = i;
        if(m==2){
          REP(i,4)if(dt[i] == s[2])sb = i;
          REP(i,4)if(dt[i] == t[2])tb = i;
        }
        else{
          debug(sa,ta);
          while(sa != ta){
            do_mov(dt[sa],dt[(sa+1)%4]);
            sa = (sa+1)%4;
          }
          output();
        }
        if(sa > sb)swap(sa,sb),swap(ta,tb);
        debug(sa,sb,ta,tb);
        while(sa!=0)do_mov(dt[sa],dt[sa-1]),sa--;
        while(sb!=1)do_mov(dt[sb],dt[sb-1]),sb--;
        if(ta < tb){
          while(sb != tb)do_mov(dt[sb],dt[sb+1]),sb++;
          while(sa != ta)do_mov(dt[sa],dt[sa+1]),sa++;
        }
        else{
          do_mov(dt[0],dt[3]),sa = 3;
          if(tb == 2)do_mov(dt[1],dt[2]);
          if(tb == 0)do_mov(dt[1],dt[0]);
          while(sa != ta)do_mov(dt[sa],dt[sa-1]),sa--;
        }
        output();
    }

    REP1(i,m)ord[i] = i;
    sort(ord + 1,ord + 1 + m,[](int a,int b){return t[a] < t[b];});
    REP1(i,m)p[ord[i]] = i;

    for(int i = 4;i <= n;i++){
      REP1(j,n)if(d[i][j])
      {
        int sp = -1;
        for(int k = j;k>0;k--)if(!d[3][k]){sp = k;break;}
        if(sp == -1)for(int k = j+1;k<=n;k++)if(!d[3][k]){sp = k;break;}
        mov_blank(3,sp,j);
        for(int k = i;k > 3;k--){
          do_mov({k,j},{k-1,j});
        }
      }
    }
    for(int i = 2;i > 0;i--){
      REP1(j,n)if(d[i][j])
      {
        int sp = -1;
        for(int k = j;k>0;k--)if(!d[3][k]){sp = k;break;}
        if(sp == -1)for(int k = j+1;k<=n;k++)if(!d[3][k]){sp = k;break;}
        mov_blank(3,sp,j);
        for(int k = i;k < 3;k++){
          do_mov({k,j},{k+1,j});
        }
      }
    }
    REP1(i,n)if(d[3][i]){
      ll tg = p[d[3][i]],now = i;
      do_mov({3,i},{2,i});
      while(now != tg){
        if(now < tg)do_mov({2,now},{2,now+1}),now=now+1;
        else do_mov({2,now},{2,now-1}),now = now-1;
      }
      do_mov({2,tg},{1,tg});
    }
    for(int i = n;i>0;i--){
      if(d[1][i]){
        ll id = d[1][i];
        for(int j = 1;j < t[id].X;j++)do_mov({j,i},{j+1,i});
      }
    }
    REP1(i,n)do_row(i);
    output();
}