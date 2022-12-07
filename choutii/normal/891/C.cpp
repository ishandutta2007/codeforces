#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define T_ template
#define Tn typename
T_ <Tn T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
T_ <Tn T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
T_ <Tn L, Tn R> ostream & operator << (ostream &out, pair<L, R> t) {
   return out << "(" << t.first << "," << t.second << ")";
}
T_ <Tn T> ostream & operator << (ostream &out, vector<T> t) {
  for (unsigned i = 0; i < t.size(); i++)
    out << (" ("[!i]) << t[i] << (",)"[i == t.size() - 1]);
  return out;
}

T_<Tn T> inline void read(T &x) {
  x = 0; char ch;
  while (!isdigit(ch = getchar()));
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
}
const int NX = 501234, MX = NX << 1;

int n, m, q;

struct edge_t {
  int u, v, w;
  edge_t() {
    
  }
  void read_() {
    read(u); read(v); read(w);
  }
}e[NX];

bool ans[NX];
vector<edge_t> edges[NX];
vector<pair<int, int> > qs[NX];

int fa[NX], Fa[NX], siz[NX];
int find_(int x) {
  return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

int find(int x) {
  return Fa[x] == x ? x : Fa[x] = find(Fa[x]);
}
int main() {
  read(n); read(m);
  int max_w = 0;
  for (int i = 1; i <= m; i++) {
    e[i].read_();
    edges[e[i].w].push_back(e[i]);
    cmax(max_w, e[i].w);
  }
    
  read(q);
  for (int i = 1; i <= q; i++) {
    int k, x; read(k);
    while (k--) {
      read(x);
      qs[e[x].w].push_back(make_pair(i, x));
    }
    ans[i] = true;
  }
 
  for (int i = 1; i <= n; i++)
     fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= max_w; i++) {
    sort(qs[i].begin(), qs[i].end());
    for (int l = 0, r = 0; l < qs[i].size(); l = r) {
      int cur_id = qs[i][l].first;
      for (; r < qs[i].size() && qs[i][r].first == cur_id; r++) {
        int e_id = qs[i][r].second;
        int u = find_(e[e_id].u), v = find_(e[e_id].v);
        Fa[u] = u; Fa[v] = v;
      }
      
      for (int t = l; t < r; t++) {
        int e_id = qs[i][t].second;
        int u = find_(e[e_id].u);
        int v = find_(e[e_id].v);
        if (find(u) == find(v)) {
          ans[qs[i][t].first] = false;
          continue;
        }
        
        Fa[find(u)] = find(v);
      }
    }
    
    for (auto p : edges[i]) {
      int u = find_(p.u), v = find_(p.v);
      if (u != v)
        fa[v] = fa[u];
    }
  }
  
  for (int i = 1; i <= q; i++)
    puts(ans[i] ? "YES" : "NO");
  return 0;
}