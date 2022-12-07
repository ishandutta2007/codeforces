#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 10005;

int n;

struct tree_t {
  set<int> e[MaxN], pe[MaxN], vs;
  set<pair<int, int> > ds, lv;
  int d[MaxN];
  void add(int u, int v) {
    e[u].insert(v);
    e[v].insert(u);
    pe[u].insert(v);
    pe[v].insert(u);
    ++d[u]; ++d[v];
  }
  
  int fe(int x) {
    return *e[x].begin();
  } 
  
  void prep() {
    for (int i = 1; i <= n; i++) {
      vs.insert(i);
      ds.insert(make_pair(d[i], i));
      if (d[i] == 1)
        lv.insert(make_pair(fe(i), i));
    }
  } 
  
  int ojbk() {
    int mx = ds.rbegin() -> first;
    return (int) vs.size() - mx - 1;
  }
  
  
  pair<int, int> find() {
    vector<pair<int, int> > ps;
    int nd = 2;
    auto it = lv.begin();
    while (nd--)
      ps.push_back(*it), it++;
    nd = 2;
    auto ti = lv.rbegin();
    while (nd--) 
      ps.push_back(*ti), ti++;
    int u = -1;
    for (auto i : ps) {
      int j = i.first;
      if (d[j] > 2) {
        u = j; break;
      } 
    }
    
    if (~u) {
      int a, b; a = b = -1;
      for (auto x : ps) {
        int y = x.first;
        if (y == u)
          a = x.second;
        else
          b = x.second;
      }
      assert(~a && ~b); 
      assert((*e[a].begin()) != (*e[b].begin()));
      return make_pair(a, b);
    } else {
      assert(ps.size() > 1);
      int a = ps[0].second, b = ps[2].second;
      return make_pair(a, b); 
    }
  }
  
  void de(int x) {
    vs.erase(x);
    int y = fe(x);
    lv.erase(make_pair(y, x));
    ds.erase(make_pair(1, x));
    e[x].erase(y);
    e[y].erase(x); 
    ds.erase(make_pair(d[y]--, y));
    ds.insert(make_pair(d[y], y));
    if (d[y] == 1)
      lv.insert(make_pair(fe(y), y)); 
  }
}A, B;

int ans[MaxN], rev[MaxN];
void solve0(int n) {
  vector<int> vx, vy;
  for (auto x : A.vs) vx.push_back(x);
  for (auto y : B.vs) vy.push_back(y);
  
  do {
    int ok = true;
    for (int i = 0; i < n && ok; i++) 
      for (int j = 0; j < i; j++) {
        bool cx = A.e[vx[i]].find(vx[j]) != A.e[vx[i]].end();
        bool cy = B.e[vy[i]].find(vy[j]) != B.e[vy[i]].end();
        if (cx && cy)
          ok = false;
      }  
    if (ok) {
      for (int i = 0; i < n; i++)
        ans[vx[i]] = vy[i];
      return;
    }
  } while (next_permutation(vx.begin(), vx.end()));
}

void solve1(tree_t &A, tree_t &B) {
  int u = (++A.ds.rbegin()) -> second;
  int v = 0, w = 0;
  for (auto t : A.e[u])
    if (A.e[t].size() == 1)
      v = t;
    else
      w = t;

  int w_ = B.lv.begin() -> second;
  int v_ = *B.e[w_].begin();
  int u_ = 0;
  for (auto p : B.vs) {
    bool cx = B.e[p].find(v_) != B.e[p].end();
    bool cy = B.e[p].find(w_) != B.e[p].end();
    if (!cx && !cy) {
      u_ = p;
      break;
    }
  }

  ans[u] = u_; 
  ans[v] = v_;
  ans[w] = w_;
  vector<int> tt; 
  for (auto x : B.vs)   
    if (x != u_ && x != v_ && x != w_)
      tt.push_back(x);
  int t_ = 0;
  
  for (auto x : A.vs)
    if (x != u && x != v && x != w)
      ans[x] = tt[t_++];
}

void work() {
  int cur_n = A.vs.size();
  if (cur_n <= 5) {
    solve0(cur_n);
    return;
  } 
  if (A.ojbk() == 1) {
    solve1(A, B);
    return;
  }
  if (B.ojbk() == 1) {
    solve1(B, A);
    for (int i = 1; i <= n; i++)
      rev[ans[i]] = i;
    for (int i = 1; i <= n; i++) 
      ans[i] = rev[i];
    return;
  }
   
  int a, b, c, d;
  tie(a, b) = A.find();
  tie(c, d) = B.find();
  int e = A.fe(a), f = A.fe(b), g = B.fe(c), h = B.fe(d); 
  A.de(a); A.de(b); B.de(c); B.de(d); 
  
  work(); 
  ans[a] = d, ans[b] = c;
  if (ans[e] != g && ans[f] != h)
    swap(ans[a], ans[b]);
}

bool validate() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) {
      bool cx = A.pe[i].find(j) != A.pe[i].end();
      bool cy = B.pe[ans[i]].find(ans[j]) != B.pe[ans[i]].end();
      if (cx && cy) {
        return false;
      }
    }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    A.add(u, v);
  }
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    u -= n; v -= n;
    B.add(u, v);
  }
  
  A.prep();
  B.prep();
  if (!A.ojbk() || !B.ojbk()) {
    puts("No");
    return 0;
  }
  
  work();

  puts("Yes");
  for (int i = 1; i <= n; i++)
    printf("%d ", ans[i] + n);
  puts(""); 
//  validate();
  return 0;
}