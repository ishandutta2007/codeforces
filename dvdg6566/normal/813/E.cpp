#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e18+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int vals[100100];

struct node{
  int s,e,m,v;
  node *l, *r;
  node(int _s, int _e, int up, node *previous) {
    s = _s; e = _e; m = (s+e)/2;
    if (up == -2){ // Means that this is the original segment tree
      if (s == e){
        v = vals[s];
        return;
      }
      l = new node(s,m,up,previous);
      r =new node(m+1, e, up, previous);
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
      v = 1;
      return;
    }
    if (up <= m){
      l = new node(s, m, up, previous->l);
      r = previous->r;
      v = l->v + r->v;
    }else{
      l = previous->l;
      r = new node(m+1,e, up,previous->r);
      v = l->v + r->v;
    }
    // cout<<s<<' '<<e<<' '<<v<<'\n';
  }

  int query(int x, int y){
    if (s == x & y == e)return v;
    if (x>m)return r->query(x,y);
    if (y <= m) return l->query(x,y);
    return l->query(x,m) + r->query(m+1, y);
  }

}*A[100100];

int col[100100],N,fw[100100],K,Q,a,b;
deque<int> p[100100];
vi des;
map<int,int> M;

int main(){
  // vals[0] = vals[1] = vals[2] = 1;
  // vals[3] = vals[4] = 0;
  // A[0] = new node(0, 4, 0, -1, A[10000]);
  // A[1] = new node(0, 4, 1, -1, A[0]);
  // A[2] = new node(0,4,2,3,A[1]);
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>K;
  for (int i=1;i<=N;++i){
    cin>>col[i];
    des.pb(col[i]);
  }
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  for (int i=0;i<SZ(des);++i)M[des[i]] = i;
  for (int i=1;i<=N;++i)col[i] = M[col[i]];
  memset(fw,-1,sizeof(fw));
  // for (auto it : des)cerr<<it<<' ';
  for (int i=1;i<=N;++i){
    int x = col[i];
    // cerr<<x<<' ';
    if (SZ(p[x]) == K){
      // cerr<<"GG ";
      fw[p[x][0]] = i;
      vals[i] = 0;
      p[x].pop_front();
    }
    else {
      vals[i] = 1;
    }
    p[x].pb(i);  
  }
  // for (int i=0;i<N;++i){
    // cout<<fw[i]<<' '<<vals[i] <<'\n';
  // }
  A[1] = new node(1, N, -2, A[100]);
  for (int i=2;i<=N;++i){
    // cout<<"Updating " << i<<' '<<fw[i-1]<<'\n';
    A[i] = new node(1, N, fw[i-1] , A[i-1]);
  }
  cin>>Q;
  int ans=0;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    a = (ans + a) % N + 1;
    b = (ans + b) % N + 1;
    if (a > b)swap(a,b);
    // cout<<a<<' '<<b<<'\n';
    ans = A[a]->query(a,b);
    cout<<ans<<'\n';
  }
}