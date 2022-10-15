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
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int db;

struct node{
  int s,e,m;
  int leftclear, rightclear, maxclear;
  node *l, *r;
  node(int _s, int _e, int up, node *previous) { // Up refers to the index to update. Sometimes may need to add entry val 
    s = _s; e = _e; m = (s+e)/2;
      leftclear = rightclear = maxclear = 0;
    if (up == -1){ // Means that this is the original segment tree
      leftclear = rightclear = maxclear = (e-s+1);
      if (s == e)return;
      l = new node(s,m,up,previous);
      r =new node(m+1, e, up, previous);
      return;
    }

    if (s == e){
      leftclear = rightclear = maxclear = 0;
      // if (db)cout<<s<<' '<<e<<' '<<leftclear<<' '<<rightclear<<' '<<maxclear<<'\n';
      return;
    }
    if (up <= m){
      l = new node(s, m, up, previous->l);
      r = previous->r;
    }else{
      l = previous->l;
      r = new node(m+1,e, up, previous->r);
    }
    int llen = l->e - l->s + 1;
    if (l->leftclear == llen){
      leftclear = r->leftclear + llen;
    }
    else leftclear = l->leftclear;
    int rlen = r->e - r->s + 1;
    if (r-> rightclear == rlen){
      rightclear = l->rightclear + rlen;
    }
    else rightclear = r->rightclear;
    maxclear = max({ l->maxclear, r->maxclear, leftclear, rightclear, l->rightclear + r->leftclear });
    // if (db)cout<<s<<' '<<e<<' '<<leftclear<<' '<<rightclear<<' '<<maxclear<<'\n';
 }

  pii ask(int a, int b){
    if (s == a && b == e)return mp(maxclear, mp(leftclear, rightclear) );
    if (b <= m)return l->ask(a,b);
    if (a > m)return r->ask(a,b);
    pii x = l->ask(a,m);
    pii y = r->ask(m+1,b);
    pii res;
    int llen = m - a + 1;
    if (x.s.f == llen){
      res.s.f = y.s.f + llen;
    }
    else res.s.f = x.s.f;
    int rlen = b - (m+1) + 1;
    if (y.s.s == rlen){
      res.s.s = x.s.s + rlen;
    }
    else res.s.s = y.s.s;
    res.f = max({ x.f, y.f, res.s.f, res.s.s, x.s.s + y.s.f });
    // cout<<"Asking from " << a << ' ' << b << " at " << s << ' ' << e << ' '<< res.f<<' '<<res.s.f<<' '<<res.s.s<<'\n';
    // cout<<x.f<<' '<<x.s.f<<' '<<x.s.s<<'\n';
    // cout<<y.f<<' '<<y.s.f<<' '<<y.s.s<<'\n';
    // cout<<llen<<' '<<rlen<<'\n';
    return res;
  }

  void bug(){
    cout<<s<<' '<<e<<' '<<leftclear<<' '<<rightclear<<' '<<maxclear<<'\n';
    if (s!=e){l->bug();r->bug();}
  }

}*A[100100], *root;

int V[100100];
int N,Q,T,a,b,w;
vi des;
map<int,int> M;
vi add[100100];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>V[i];
    des.pb(V[i]);
  }
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  T = SZ(des);
  for (int i=0;i<T;++i)M[des[i]] = i;
  for (int i=0;i<N;++i){
    V[i] = M[V[i]];
    add[V[i]].pb(i);
  }
  A[0] = new node(0, N-1, -1, A[1]);
  for (int i=0;i<T; ++i){
    root = A[i];
    for (auto j : add[i]){
      // cout<<"At " << i+1 << " remove " << j << '\n';
      root = new node(0, N-1, j, root);
    }
    // db = 1;
    A[i+1] = root;
  }
  // for (int i=0;i<=T;++i)cerr<<A[i]->maxclear<<' ';cout<<'\n';
  assert(A[T]->maxclear == 0);
  // A[4]->bug();
  // cout<<A[4]->ask(0,8).f<<'\n';
  // return 0;
  cin>>Q;
  // for (auto i:des)cout<<i<<' ';cout<<'\n';
  for (int i=0;i<Q;++i){
    cin>>a>>b>>w;
    --a;--b;
    int low = 0, upp = T;
    while(upp > low+1){
      int mid = (low+upp)/2;
      pii x = A[mid] -> ask(a,b);
      // cerr<<"Ask " << mid <<' '<<a<<' '<<b<<' '<<x.f<< '\n';
      // cerr<<x.f<<'\n';
      if (x.f >= w)low= mid;
      else upp= mid;
      // cout<<"Range " << low << ' ' << upp << '\n';
    } 
    if (A[low] ->ask(a,b).f >= w)upp = low;
    cout<<des[low]<<'\n';
  }
}