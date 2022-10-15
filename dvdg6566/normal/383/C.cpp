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

vi aList[200100];

ll fw[200100];
ll N,Q,a,b,c;

struct node{
  ll s,e,m; ll v;
  node *l, *r;
  node(ll _s, ll _e){
    s=_s;e=_e;m=(s+e)/2;v = 0;
    if (s != e){
      l = new node(s,m);
      r = new node(m+1, e);
    }
  }

  void update(ll x, ll val){
    if (s == e){v += val; return;}
    if (x <= m)l->update(x,val);
    if (x > m)r->update(x, val);
    v = l->v + r->v;
  }

  ll query(ll x, ll y){
    if (s == x && y == e)return v;
    if (y <= m)return l->query(x,y);
    if (x > m)return r->query(x,y);
    return l->query(x,m) + r->query(m+1,y);
  }
}*root;

ll p[200100], depth[200100], heavy[200100], head[200100], pos[200100];
ll A[200100];
ll cur;

ll dfs(ll x){
  ll size = 1; ll mchild = 0;
  for (auto i : aList[x]){
    if (i == p[x])continue;
    p[i] = x;
    depth[i] = depth[x] + 1;
    ll cs = dfs(i);
    size += cs;
    if (cs > mchild){mchild = cs; heavy[x] = i;}
  }
  return size;
}

void decompose(ll x, ll h){
  head[x] = h; pos[x] = cur++;
  if (heavy[x] != -1)decompose(heavy[x], h);
  for (auto i : aList[x]){
    if (i == p[x] || i == heavy[x])continue;
    decompose(i,i);
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  for (ll i=1;i<=N;++i){
    cin>>A[i];
  }
  for (ll i=1;i<N;++i){
    cin>>a>>b;
    aList[a].pb(b);aList[b].pb(a);
  }
  memset(heavy,-1,sizeof(heavy));
  cur = 1;
  dfs(1);
  decompose(1,1);
  // for (int i=1;i<=N;++i)cout<<head[i]<<' ';cout<<'\n';
  root = new node(1,N);
  while(Q--){
    cin>>c;
    if (c == 1){
      cin>>a>>b;
      if (depth[a]%2 == 0){
        // cout<<"Update Positive " << a << '\n';
        root->update(pos[a],b);
      }
      else {
        // cout<<"Update Negative " << a << '\n';
        root->update(pos[a],-b);
      }
    }else{
      cin>>a;
      int l = depth[a]%2;
      ll res = A[a];
      while (head[a] != 1){
        // cout<<head[a]<<' '<<a<<' '<<root->query(pos[head[a]], pos[a])<<'\n';
        if (l % 2 == 1)res -= root->query(pos[head[a]], pos[a]);
        else res += root->query(pos[head[a]], pos[a]);
        a = p[head[a]];
      }
      if (l % 2 == 1) res -= root->query(1, pos[a]);
      else res += root->query(1, pos[a]);
      cout<<res<<'\n';
    }
  }
}