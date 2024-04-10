#include <bits/stdc++.h>

bool home=1;

using namespace std;

/// #define int long long

typedef long long ll;
const int N=(int)2e5+7;
const int INFINT=(int)1e9+7;
const ll INFLL=(ll)1e18+7;
const int K=20;
int n;
int q;
int par_edge_id[N],par[N],id[N],inds,low[N],high[N],who_has_this_id[N];
ll valof[N];
pair<int, int> rmq[K][2*N];
int lg[2*N];
int ff[N],ss[N],top,dep[N];
int sub[N],bgk[N],col[N],colors;
ll cur_on_edge[N];
pair<int, int> edges[N];
int boss[N];
vector<int> _gindex_only_for_initial_use_[N];
vector<int> g[N];

void build(int a,int p=-1){
  rmq[0][++top]={dep[a], a};
  ff[a]=ss[a]=top;
  vector<int> kids;
  sub[a]=1;
  for(auto&i:_gindex_only_for_initial_use_[a]){
    int b=edges[i].first+edges[i].second-a;
    if(b==p) continue;
    dep[b]=1+dep[a];
    boss[i]=b;
    valof[a]=cur_on_edge[i];
    par_edge_id[b]=i;
    par[b]=a;
    kids.push_back(b);
    build(b,a);
    sub[a]+=sub[b];
    if(sub[b]>sub[bgk[a]]){
      bgk[a]=b;
    }
    rmq[0][++top]={dep[a], a};
    ss[a]=top;
  }
  g[a]=kids;
}

ll mult(ll a, ll b) {
  if(a==0||b==0) return a;
  if(a<=INFLL/b) return a*b;
  return INFLL;
}

ll tree[4*N];

void setup(int v,int tl,int tr,int i,ll what){
  if(tr<i||i<tl) return;
  if(tl==tr){
    tree[v]=what;
    return;
  }
  int tm=(tl+tr)/2;
  setup(2*v,tl,tm,i,what);
  setup(2*v+1,tm+1,tr,i,what);
  tree[v]=mult(tree[2*v],tree[2*v+1]);
}

ll get(int v,int tl,int tr,int l,int r){
  if(tr<l||r<tl) return 1;
  if(l<=tl&&tr<=r) return tree[v];
  int tm=(tl+tr)/2;
  return mult(get(2*v,tl,tm,l,r),get(2*v+1,tm+1,tr,l,r));
}

void update(int i,ll what){
  setup(1,1,n,i,what);
}

ll get_prod(int l,int r){
  return get(1,1,n,l,r);
}

int get_lca(int a, int b){
  if (ff[a] > ss[b]) swap(a, b);
  a = ff[a];
  b = ss[b];
  assert(a <= b);
  int k = lg[b - a + 1];
  return min(rmq[k][a], rmq[k][b - (1 << k) + 1]).second;
}

void col_build(int a){
  id[a]=++inds;
  who_has_this_id[id[a]] = a;
  low[col[a]]=min(low[col[a]],id[a]);
  high[col[a]]=max(high[col[a]],id[a]);
  for (auto &b:g[a]){
    if(b==bgk[a]){
      col[b] = col[a];
      col_build(b);
    }
  }
  for (auto &b:g[a]){
    if(b!=bgk[a]){
      col[b]=++colors;
      col_build(b);
    }
  }
}

void update_vertex(int vertex, ll new_value) {
  assert(vertex > 1);
  update(id[vertex], new_value);
}

ll get_anc_prod(int a, int c) {
  ll sol = 1;
  while (1) {
    ///cout << a << " and " << c << "\n";
    if (col[a] == col[c]) {
      sol = mult(sol, get_prod(id[c] + 1, id[a]));
      break;
    } else {
      sol = mult(sol, get_prod(low[col[a]], id[a]));
      a = par[who_has_this_id[low[col[a]]]];
    }
  }
  return sol;
}

void set_edge(int i, ll value) {
  update_vertex(boss[i], value);
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif


  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  cin>>n>>q;
  for(int i=1;i<n;i++){
    cin>>edges[i].first>>edges[i].second>>cur_on_edge[i];
    _gindex_only_for_initial_use_[edges[i].first].push_back(i);
    _gindex_only_for_initial_use_[edges[i].second].push_back(i);
  }
  for(int i=1;i<=n;i++){
    low[i]=+INFINT;
    high[i]=-INFINT;
  }
  build(1);
  for(int i=2;i<=top;i++) lg[i]=1 + lg[i / 2];
  for (int k = 1; (1 << k) <= top; k++) {
    for (int i = 1; i + (1 << k) - 1 <= top; i++) {
      rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
    }
  }
  col[1]=++colors; col_build(1);

  assert(inds==n);
  for(int i=1;i<n;i++){
    set_edge(i, cur_on_edge[i]);
  }

  for (int i = 1; i <= n; i++) {
    //cout << "col[" << i << "] = " << col[i] << "\n";
  }

  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int a, b;
      ll have;
      cin >> a >> b >> have;
      int c = get_lca(a, b);
      ll prod = mult(get_anc_prod(a, c), get_anc_prod(b, c));
      cout << have / prod << "\n";
    } else {
      int i;
      cin >> i;
      cin >> cur_on_edge[i];
      set_edge(i, cur_on_edge[i]);
    }
  }
}