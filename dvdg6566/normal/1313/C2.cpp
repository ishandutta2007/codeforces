#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 998244353;
const ll INF = 1e9;
const ll MAXN = 2500100;

ll A[MAXN];

struct node{
  ll s,e,m;
  node *l, *r;

  pi v;
  node (ll _s, ll _e):s(_s),e(_e){
    m=(s+e)/2;
    if (s==e){v=mp(A[s],s);return;}
    l=new node(s,m);r=new node(m+1,e);
    if (l->v.f<r->v.f)v=l->v;
    else v=r->v;
  }
  void up(ll x, ll val){
    if(s==e){
      A[x]=val;
      v=mp(val,s);
      return;
    }
    if (x<=m)l->up(x,val);
    else r->up(x,val);
    if (l->v.f<r->v.f)v=l->v;
    else v=r->v;
  }
  pi query(ll x, ll y){
    if(s==x&&e==y)return v;
    if(y<=m)return l->query(x,y);
    if(x>m)return r->query(x,y);
    pi a=l->query(x,m);pi b=r->query(m+1,y);
    if(a.f<b.f)return a;
    return b;
  }
}*root;

map<pi,ll>M;
ll ans[MAXN];
ll N;

ll solve(ll s,ll e){
  if(e<s)return 0;
  pi mid=root->query(s,e);
  // cerr<<"A "<<s<<' '<<e<<'\n';
  //calculate left
  ll left=(mid.s-s+1)*mid.f+solve(mid.s+1,e);
  ll right=(e-mid.s+1)*mid.f+solve(s,mid.s-1);
  if(left>right)M[mp(s,e)]=1;
  else M[mp(s,e)]=-1;
  return max(left,right);
}

void calc(ll s,ll e){
  ll t=M[mp(s,e)];
  pi mid=root->query(s,e);
  // cerr<<s<<' '<<mid.s<<' '<<e<<'\n';
  if (e<=s){ans[s]=A[s];return;}
  // cerr<<s<<' '<<e<<'\n';
  if (t==1){
    for (ll i=s;i<=mid.s;++i)ans[i]=mid.f;
    calc(mid.s+1,e);
  }else{
    assert(t==-1);
    for (ll i=mid.s;i<=e;++i)ans[i]=mid.f;
    calc(s,mid.s-1);
  }
}

int main(){
  cin>>N;
  for (ll i=1;i<=N;++i)cin>>A[i];
  root=new node(1,N);
  solve(1,N);
  calc(1,N);
  for (ll i=1;i<=N;++i)cout<<ans[i]<<' ';
}