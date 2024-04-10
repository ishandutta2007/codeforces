#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<int> vi;

struct SegmentTree {

  vector<ll> T, lazy;
  int n;

  SegmentTree() {
    n = 0;
  }

  SegmentTree(int _n) {
    n = _n;
    T = lazy = vector<ll>(4*(n+1), 0);
  }

  void add(int pos0, int pos1, ll val) {
    fes(1, 0, n, pos0, pos1, val);
  }

  ll ask(int pos0, int pos1) {
    return que(1, 0, n, pos0, pos1);
  }

  void actu(int node, bool b) {
    T[node] += lazy[node];
    if (b) {
      lazy[2*node] += lazy[node];
      lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void fes(int node, int a, int b, int x, int y, ll val) {
    actu(node, a != b);
    if (b < x or y < a) return;
    if (x <= a and b <= y) {
      lazy[node] = val;
      actu(node, a != b);
      return;
    }
    int mid = (a+b)/2;
    fes(2*node, a, mid, x, y, val);
    fes(2*node+1, 1+mid, b, x, y, val);
    T[node] = max(T[2*node], T[2*node+1]);
  }

  ll que(int node, int a, int b, int x, int y) {
    actu(node, a != b);
    if (b < x or y < a) return 0;
    if (x <= a and b <= y) return T[node];
    int mid = (a+b)/2;
    return max(
        que(2*node, a, mid, x, y),
        que(2*node+1, 1+mid, b, x, y));
  }

};

struct block {

  SegmentTree tree;
  unordered_map<int,pi> A;
  
  vector<block*> sons;
  multiset<ll> diameters;
  multiset<ll> radials;
  vi sonsnodes;
  vpll sonsvalues;

  block* parent;
  int ind;
  int depth;

  ll diameter;

  int dfs1(int x, vi& V, vvpll& G) {
    V[x] = 1;
    for (auto it : G[x]) {
      int y = (int)it.first;
      if (V[y] == 0) {
        V[x] += dfs1(y, V, G);
      }
    }
    return V[x];
  }

  int dfs2(int x, vi& V, vvpll& G, int n) {
    V[x] = -1;
    for (auto it : G[x]) {
      int y = (int)it.first;
      if (V[y] > 0 and 2*V[y] >= n) 
        return dfs2(y, V, G, n);
    }
    return x;
  }

  void dfs3(int x, vi& V, vvpll& G, int& cont, ll val) {
    A[x].first = cont++;
    V[x] = 0;
    for (auto it : G[x]) {
      int y = (int)it.first;
      ll w = it.second;
      if (V[y] != 0 and V[y] != -2) dfs3(y, V, G, cont, w);
    }
    A[x].second = cont;
    tree.add(A[x].first, A[x].second-1, val);
  }

  void calc_diameter() {
    diameter = 0;
    if (sons.size()) {
      diameter = max(diameter, -(*diameters.begin()));
      diameter = max(diameter, -(*radials.begin()));
    }
    if (sons.size() >= 2) {
      auto it1 = radials.begin();
      auto it2 = it1; ++it2;
      ll val = *it1 + *it2;
      diameter = max(diameter, -val);
    }
  }

  void print() {
    cerr << "Block :";
    for (auto it : A) {
      cerr << ' ' << it.first;
    }
    cerr << endl;
    cerr << "diameter = " << diameter << endl;
    for (int i = 0; i < (int)sonsnodes.size(); ++i) {
      cerr << sonsnodes[i] << " -> (" << sonsvalues[i].first << ", " << sonsvalues[i].second << ")" << endl;
    }
    cerr << endl;
  }

  block(block* _parent, int _ind, int _depth, vvpll& G, vi& V, int x, vector<block*>& B) {
    parent = _parent;
    ind = _ind;
    depth = _depth;

    int n = dfs1(x, V, G);
    x = dfs2(x, V, G, n);
    tree = SegmentTree(n);
    int cont = 0;
    dfs3(x, V, G, cont, 0);

    V[x] = -2;
    B[x] = this;
    for (auto it : G[x]) {
      int y = (int)it.first;
      if (V[y] == 0) {
        block* b = new block(this, (int)sons.size(), depth + 1, G, V, y, B);
        sons.push_back(b);
        sonsnodes.push_back(y);
        sonsvalues.push_back(pll(b->diameter, tree.ask(A[y].first, A[y].second-1))); 
        diameters.insert(-sonsvalues.back().first);
        radials.insert(-sonsvalues.back().second);
      }
    }
    calc_diameter();
  }

  ~block() {
    for (auto s : sons) delete s;
  }

  ll query(int x, int y, ll val, int index) {
    if (A[y].first <= A[x].first and A[x].second <= A[y].second) swap(x,y);
    tree.add(A[y].first, A[y].second-1, val);

    auto itd = diameters.find(-sonsvalues[index].first);
    diameters.erase(itd);
    sonsvalues[index].first = sons[index]->diameter;
    diameters.insert(-sonsvalues[index].first);

    auto itr = radials.find(-sonsvalues[index].second);
    radials.erase(itr);
    sonsvalues[index].second = tree.ask(A[sonsnodes[index]].first, A[sonsnodes[index]].second-1);
    radials.insert(-sonsvalues[index].second);

    calc_diameter();
    if (parent != nullptr) {
      return max(diameter, parent->query(x, y, val, ind));
    }
    return diameter;
  }

};

struct aresta {
  int x, y;
  ll c;
  aresta() {}
  aresta(int _x, int _y, ll _c) : x(_x), y(_y), c(_c) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  ll w;
  cin >> n >> q >> w;

  vvpll G(n);
  vector<aresta> M(n-1);

  for (int i = 0; i < n-1; ++i) {
    int x, y;
    ll c;
    cin >> x >> y >> c;
    --x; --y;
    G[x].push_back({y, c});
    G[y].push_back({x, c});
    M[i] = aresta(x,y,c);
  }

  vi V(n, 0);
  vector<block*> B(n);

  block* root = new block(nullptr, -1, 0, G, V, 0, B); 

  ll last = 0;

  while (q--) {
    ll ind, c;
    cin >> ind >> c;
    
    ind = (ind + last)%(n-1);
    c = (c + last)%w;

    ll val = c - M[ind].c;
    M[ind].c = c;

    int x = M[ind].x;
    int y = M[ind].y;
    int index = -1;
    if (B[x]->depth > B[y]->depth) swap(x,y);
    auto blocky = B[y];
    while (B[x]->depth < blocky->depth) {
      index = blocky->ind;
      blocky = blocky->parent;
    }

    last = blocky->query(x, y, val, index);
    cout << last << '\n';
  }
  
  delete root;
}