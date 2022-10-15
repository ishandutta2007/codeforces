#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

ll N,a,b,c,d,e,f,Q;

struct node{
  ll s,e,m,v;
  node *l, *r;
  node(ll _s, ll _e, ll up, ll val, node *previous) {
    s = _s; e = _e; m = (s+e)/2;
    // if (s == 0 && e == 200100){
      // cout<< "Update " << up <<' '<<val <<'\n';
    // }
    if (up == -2){ // Means that this is the original segment tree
      if (s == e){
        v = 0;
        return;
      }
      l = new node(s,m,up,val,previous);
      r =new node(m+1, e, up, val,previous);
      v = l->v + r->v;
      return;
    }
    if (up == -1){
      l = previous->l;
      r = previous->r;
      v = previous->v;
      return;
    }
    if (s == e){
      // cout<<"Change " << s << " from " << v << " to " << v + val <<'\n';
      v = previous->v + val;
      return;
    }
    if (up <= m){
      l = new node(s, m, up, val, previous->l);
      r = previous->r;
      v = l->v + r->v;
    }else{
      l = previous->l;
      r = new node(m+1,e, up,val,previous->r);
      v = l->v + r->v;
    }
    // cout<<s<<' '<<e<<' '<<v<<'\n';
  }

  ll query(ll x, ll y){
    // cout<<s<<' '<<e<<' '<<v<<'\n';
    // if (s == 0 && e == 200100){
      // cerr <<"Query " << x << ' ' << y << '\n';
    // }
    if (x == s && y == e)return v;
    if (y <= m)return l->query(x,y);
    if (x > m)return r->query(x,y);
    return l->query(x,m) + r->query(m+1, y);
  }

}*A[200100], *B[200100], *root;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  A[0] = new node(0, 200100, -2, 0, A[10]);
  B[0] = new node(0, 200100, -2, 0, B[10]);
  for (int i=1;i<=N;++i){
    cin>>a>>b>>c>>d>>e>>f;
    // cout<<"GRAD\n";
    root = new node(0, 200100, a+1, d, A[i-1]);
    A[i] = new node(0, 200100, b+1, -d, root);
    // cout<<"const\n";
    root = new node(0, 200100, 1, c, B[i-1]);
    root = new node(0, 200100, a+1, e-c, root);
    B[i] = new node(0, 200100, b+1, f-e, root);
  }
  cin>>Q;
  ll last = 0;
  for (int i=0;i < Q; ++i){
    cin>>a>>b>>c;
    c = (c + last) % MOD;
    // cout<<"Query " << a<<' '<<b<<' '<<c<<'\n';
    // cout<<"Lower " << A[a-1]->query(1LL, c) << ' '<< B[a-1]->query(1LL,c)<<'\n';
    // cerr << c <<' '<<b<<'\n';
    // last = A[b]->query(1LL, c) - A[a-1]->query(1LL, b);
    // cout<<last<<'\n';
    if (c > 200100)c = 200100;
    ll grad = A[b] -> query(0LL, c) - A[a-1] -> query(0LL, c);
    ll con = B[b] ->query(0LL, c);
    ll m = B[a-1] -> query(0LL, c);
    con -= m;
    if (c == 200100)assert(grad == 0);
    last = c * grad + con;
    cout<<last<<'\n';
  }
}