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
template<typename _a,typename _b> ostream &operator << (ostream &_s,multiset<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
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
const ll INF=ll(1e17);

struct line{
  ll a,b,l,r;
};
bool fg=0; // 0 -> sort with slope, 1-> query point
struct cmp{
  bool operator () (const line &a,const line &b){
    if(fg==0)return a.a > b.a;
    else return a.r<b.l;
  }
};

ii mydiv(ll a,ll b)
{
  assert(b!=0);
  a--;
  ll x=a/b;
  if(a%b!=0&&((a<0)!=(b<0)))return ii(x-1,x);
  else return ii(x,x+1);
}

void ins(multiset<line,cmp> &st,ll a,ll b)
{
  line ln=(line){a,b,-INF,INF};
  fg=0;
  auto it=st.lower_bound(ln),pit=it;
  if(it!=st.end()&&it->a==a)
  {
    if(it->b<=b)return;
    else it=st.erase(it);
  }
  while(it!=st.end())
  {
    ii x=mydiv(it->b-b,a-it->a);
    if(x.Y>it->r)it=st.erase(it);
    else break;
  }
  while(it!=st.begin())
  {
    pit=prev(it);
    ii x=mydiv(pit->b-b,a-pit->a);
    if(x.X<pit->l)st.erase(pit);
    else break;
  }
  if(!SZ(st)){st.insert(ln);return;}
  if(it!=st.end())ln.r=mydiv(it->b-b,a-it->a).X;
  if(it!=st.begin())pit=prev(it),ln.l=mydiv(pit->b-b,a-pit->a).Y;
  ll tl,tr;
  if(ln.l<=ln.r)tl=ln.l-1,tr=ln.r+1;
  else{
    pit=prev(it);
    ii x=mydiv(pit->b-it->b,it->a-pit->a);
    tl=x.X;tr=x.Y;
  }
  if(it!=st.begin()){
    pit=prev(it);
    line tmp=*pit;
    st.erase(pit);
    tmp.r=tl;
    st.insert(tmp);
  }
  if(it!=st.end()){
    line tmp=*it;
    st.erase(it);
    tmp.l=tr;
    st.insert(tmp);
  }
  if(ln.l<=ln.r)st.insert(ln);
}


multiset<line,cmp> st[MAXn];
ii d[MAXn];
vector<ll> v[MAXn];
ll dp[MAXn];

void dfs(ll now,ll f)
{
  if(SZ(v[now])==1&&now!=1)
  {
    ins(st[now],d[now].Y,0);
    return;
  }
  REP(i,SZ(v[now]))if(v[now][i]==f)
  {
    v[now].erase(v[now].begin()+i);
    break;
  }
  for(ll k:v[now])dfs(k,now);

  sort(ALL(v[now]),[](int a,int b){return SZ(st[a])>SZ(st[b]);});
  st[v[now][0]].swap(st[now]);
  REP1(i,SZ(v[now])-1)
  {
    ll t=v[now][i];
    for(auto ln:st[t])ins(st[now],ln.a,ln.b);
    st[t].clear();
  }
  fg=1;
  auto ln=*st[now].lower_bound((line){0,0,d[now].X,d[now].X});
  dp[now]=ln.a*d[now].X+ln.b;
  debug(ln.a,ln.b,ln.l,ln.r);
  debug(now);
  for(auto tmp:st[now])debug(tmp.a,tmp.b,tmp.l,tmp.r);
  ins(st[now],d[now].Y,dp[now]);
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)cin>>d[i].X;
    REP1(i,n)cin>>d[i].Y;
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      v[b].pb(a);
    }
    dfs(1,-1);
    REP1(i,n)cout<<dp[i]<<" ";

}