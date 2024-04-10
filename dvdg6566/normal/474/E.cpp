#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

struct node{
  ll s,e,m,v,o;
  node *l,*r;
  node(ll _s, ll _e){
    s=_s;e=_e;m=(s+e)/2;
    v=0; o=-1;
    if (s != e){
      l = new node(s,m); r = new node(m+1, e);
    }
  }

  void up (ll x, ll nv, ll i){
    if (s == e){v = nv; o = i;return;}
    if (x > m)r->up(x,nv,i);
    if (x<=m)l->up(x,nv,i);
    if (l->v > r->v){
      v = l->v;
      o = l->o;
    }
    else{
      v = r->v;
      o = r->o;
    }
  }
  
  pi rmq(ll x, ll y){
    if(s == x&&e==y)return mp(v,o);
    if (x>m)return r->rmq(x,y);
    if (y<=m)return l->rmq(x,y);
    pi a = l->rmq(x,m), b = r->rmq(m+1,y);
    if (a.f > b.f)return a;
    return b;
  }
  
}*root;
ll p[100100];
ll N, D;
vi des;
pi V[100100];
map<ll,ll> M;
ll a[100100];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>D;
  for (ll i=0;i<N;++i)cin>>a[i];
  des.pb(-INF);
  for (ll i=0;i<N;++i){
    des.pb(a[i]);
  }
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  des.pb(INF);
  ll T = SZ(des);
  ll lower = 0, upper = 0;
  // for (auto i : des)cout<<i<<' ';cout<<'\n';
  for (ll i=1;i<T-1;++i){
    M[des[i]] = i;
    // cout<<des[i]<<'\n';
    while (des[lower]+D<=des[i])++lower;
    while (des[upper+1]-D<des[i])++upper;
    V[i] = mp(lower,upper);
    // cout<<lower<<' '<<upper<<'\n';
  }
  ll opt=0, cur=-1;
  root = new node(0,T);
  for (ll i=0;i<N;++i){
    ll de = M[a[i]];
    pi x = root->rmq(0, V[de].f-1);
    pi y = root->rmq(V[de].s+1, T);
    if (y.f > x.f)x = y;
    root->up(de, x.f+1, i);
    if (x.f+1 > opt){cur = i; opt = x.f+1;}
    p[i] = x.s;
  }
  ll x = cur;
  stack<ll> st;
  while(p[x] != -1){
    st.push(x);
    x = p[x];
  }
  st.push(x);
  cout<<SZ(st)<<'\n';
  while(SZ(st)){cout<<1+st.top()<<' ';st.pop();}
}